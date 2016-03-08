//////////////////////////////////////////
//Author: Colt Darien                   //
//This program is Lab4 for ECE456 at CSU// 
//Spring 2016                           //
//////////////////////////////////////////

/*
//See README for more details about this program
*/

package main

import(
	"fmt"
	"os"
	"time"
	"strings"
	"io/ioutil"
	"strconv"
	"bufio"
	"net"
)
/* Create a struct for server and client
   could easily be done with just one struct, but this is clearer in code */
type socket_info struct {
	Source_address *net.UDPAddr
	Destination_address *net.UDPAddr
	Connection *net.UDPConn
	Key []byte
}

/* These will be used with the UDPAddr, they should probably be methods of the struct type, but since I used two different structs this is easier */
func get_port(address *net.UDPAddr) string{
	return strings.Split(address.String(), ":")[1]
}

func get_ip(address *net.UDPAddr) string{
	return strings.Split(address.String(), ":")[0]
}

///////////////////////////////UTILITY FUNCTIONS////////////////////////////////////////////////////

func convert_endian(data []byte) []byte{//you do not have to accept the return value because this is based on pointers, so base is updated anyway
	if(len(data) < 2){
		return data
	}
	for i, j := 0, 1; j < len(data)-1; i, j = i+2, j+2 {
		data[i], data[j] = data[j], data[i]
	}
	return data
}

func check(e error) {
	if e != nil {
		panic(e)
	}
}


func read_file(file_name string) []byte{
	data, err := ioutil.ReadFile(file_name)
	check(err)
	if _, err := os.Stat(file_name); os.IsNotExist(err) {
		fmt.Println("ERROR: File Does not exist or is blank")// path/to/whatever does not exist
	}
	//  data = data[0:len(data)-1]//get rid of the EOF character
	return data
}


func write_file(file_name string, data []byte) {
	file,err := os.Create(file_name)
	check(err)
	defer file.Close()//this is going to close the file after we return (defer is cool)
	_,err = file.Write(data)
	check(err)
}

func create_message(send_addr *net.UDPAddr, dest_addr *net.UDPAddr, data []byte) []byte{
	/* This will be the datagram later on */
	var datagram []byte
	/* This is calculated every time, and does not need to be but makes code clearer */
	sender_ip := get_ip_big_Endian(get_ip(send_addr))//get the data from arg[2] (sender ip) and format it to
	destination_ip := get_ip_big_Endian(get_ip(dest_addr))//get the data from args[3] (destination ip) and format
	source_port, _ := strconv.Atoi(get_port(send_addr))// get the port for sender
	dest_port, _ := strconv.Atoi(get_port(dest_addr))// get the port for destination
	/* Check to make sure that the ports are in range */
	if(dest_port > 0xFFFF || source_port > 0xFFFF){
		fmt.Println("Port is out of range")
		os.Exit(1)
	}

	//create the datagram
	datagram = append(datagram, byte(source_port>>8), byte(source_port))//append the source port	 //regular
	datagram = append(datagram, byte(dest_port>>8), byte(dest_port))//append the destination port  //regular

	//Add the size to the datagram
	datagram_size := len(data) + 8 //+8 for the preceding 8 bytes
	datagram = append(datagram, byte(datagram_size), byte(datagram_size>>8))//append the length of the message //big

	datagram = append(datagram, 0x00, 0x00)//append room for checksum to the datagram, but we do not know check yet, so leave blank for now replace later
	if len(data) % 2 == 1 {
		data = append(data, 0x00)//we need padding
	}
	/* Encrypt the message with the key */
	datagram = append(datagram, data...)

	//calculate the checksum
	checksum := calculate_checksum(sender_ip, destination_ip, datagram)
	datagram[7] = checksum[0]
	datagram[6] = checksum[1]

	/* Return the message*/
	return datagram
}

func read_input(send chan<- string) { /* This is to read input from keyboard, we will remove it when this is fully working  */
	reader := bufio.NewReader(os.Stdin)
	/*Get the input, This will change in the future (when done testing) TODO also get rid of newline if you feel like it*/
	for {
		/* Get input from user (the message they will send) */
		input,_  := reader.ReadString('\n')
		/* Delete the end newline */
		input = input[:len(input)-1]
		/* Send this input to main thread so that they can send it */
		send <- input
	}
}

///////////////////////////////Cryptography stuff///////////////////////////////////////////////////
//DECODE///////////////////////////////////////////////////////

//decodes a block of data
func decode_block(data []byte, key byte) []byte{
	//These bytes are 
	left_byte := data[0]
	right_byte := data[1]//unnecessary, but makes code more readable
	//^ is Xor
	right_byte ^= key
	// switch the left and right half
	data[0] = right_byte
	data[1] = left_byte
	return data
}


func decode(encoded_data []byte, keys []byte) []byte{
	for i :=0; i<len(encoded_data);i+=2{
		//make a block (which in this case is a pointer) from the encoded_data. +2 because bound is [inclusive, exclusive]
		block := encoded_data[i:i+2]
		//iterate over all keys backwards to undo the things we did when encoding (just use encode because it is the same thing)
		for i :=len(keys); i>0; i--{
			decode_block(block, keys[i-1])
		}
	}
	
	return encoded_data
}

//ENCODE///////////////////////////////////////////////////////

//encodes a block of data
func encode_block(data []byte, key byte) []byte{
	//These bytes are 
	left_byte := data[0]
	right_byte := data[1]//unnecessary, but makes code more readable
	//^ is Xor
	left_byte ^= key
	// switch the left and right half
	data[0] = right_byte
	data[1] = left_byte
	return data
}
//I read data file block by block because we are supposed to be doing stuff as if it were packetized for network
//Keys on the other hand we would know ahead of time, so I just read them all in at once
func encode(data []byte, keys []byte) []byte{
	if len(data) %2 == 1 {
		/* Apend a 0x00 */
		data = append(data, 0x00)
	}
	for i :=0; i<len(data);i+=2{
		//make a block (which in this case is a pointer) from the data. +2 because bound is [inclusive, exclusive]
		block := data[i:i+2]
		//iterate over all keys (we encode blocks first)
		for _, key := range keys{
			encode_block(block, key)
		}
	}
	return data
}

///////////////////////////////////////Checksum///////////////////////////////////////////////////////

func calculate_checksum(source_ip []byte, destination_ip []byte, datagram []byte) []byte{// take in the ips and the length of data in bytes
	var checksum int = 0//will be rolled over to 16 in the end
	var checksum_byte []byte
	checksum += int(source_ip[0])<<8 + int(source_ip[1]) + int(source_ip[2])<<8 + int(source_ip[3])//roll over will be taken care of later, add the bytes shift as needed
	checksum += int(destination_ip[0])<<8 + int(destination_ip[1]) + int(destination_ip[2])<<8 + int(destination_ip[3])//roll over will be taken care of later, add the bytes shift as needed

	checksum += 0x0011 //add in the protocoll (udp is 17)

	checksum += int(datagram[4]) + int(datagram[5])<<8 //data size again
	for i := 0; i < len(datagram)-1; i += 2 {//take 16 bits (2 bytes) at a time
		checksum += int(datagram[i]) + int(datagram[i+1])<<8 //This is all big endian, so do not forget that we need to do it backwards
	}
	if (len(datagram) % 2 == 1) {//if we took an odd number of bytes in from the file, add the last one shifted? TODO
		checksum += int(datagram[len(datagram)-1])
	}

	for (checksum > 0xFFFF){ //keep adding the carry over until this is correct
		checksum = int(int16(checksum) + int16(checksum>>16)) // add the overflow to the checksum
	}

	checksum_byte = append(checksum_byte, byte(checksum>>8)^0xFF, byte(checksum)^0xFF)//convert this to slice of bytes
	return checksum_byte //invert evrything (ones complement) also done in previous line
}

///////////////////////////////////////Parse Arguments//////////////////////////////////////////////

func get_ip_big_Endian(address string) []byte{
	var ip []byte
	octets_string := strings.Split(address, ".")
	if len(octets_string) != 4 {
		fmt.Println("Error: Address should be of the form ###.###.###.### where all values are less than 255, but received: " + address)
		os.Exit(1)
	}
	for _, octet := range octets_string {//iterate over all of the octet strings and change them to ints
		octet_int, _ := strconv.Atoi(octet)
		if octet_int > 255{
			fmt.Println("Error: Address should be of the form ###.###.###.### where all values are less than 255, but received: " + address)
		}
		ip = append(ip, byte(octet_int))//transform the octet string to int and add it to the slice
	}
	//reverse the order of the octets to be big endian
	for i, j := 0, len(ip)-1; i < j; i, j = i+1, j-1 {
		ip[i], ip[j] = ip[j], ip[i]
	}
	return ip
}

///////////////////////////////////////SERVER ///////////////////////////////////////////////////////
//TODO do I do anything if for timeout on my replies?
func server(sock *socket_info) {
	var received_messages []string /*This will store all messages, but we will send the last 5 back to clients) */
	// Channel to get information from socket receive
	recv_msg := make(chan string)
	recv_addr := make(chan *net.UDPAddr)
	/* Start a new goroutine for handlin things */
	go receive_messages(sock, recv_msg, recv_addr)
	/* Read messages over and over again */
	/*****skip_one_reply := 0*****/
	for {
		select{
		case msg_recv := <-recv_msg:
			addr := <-recv_addr
			/* Create the socket to reply */
			msg := (time.Now().Format("15:04:05 | ") + get_ip(addr) + ":" + get_port(addr) + " | " + msg_recv + "\n")
			received_messages = append(received_messages, msg)
			fmt.Println(msg)
			if len(received_messages) <=5 {
				for _, msg := range received_messages {/* Get the last five messages */
					/*****if skip_one_reply == 0 {
						skip_one_reply = 1
						continue
					}*****/
					send_message(sock, addr, []byte(msg))
				}
			}else{
				for _, msg := range received_messages[len(received_messages) - 6:] {/* Get the last five messages */
					send_message(sock, addr, []byte(msg))
				}
			}
		}
	}
}

///////////////////////////////////////CLIENT  ///////////////////////////////////////////////////////
func send_message (sock *socket_info, addr *net.UDPAddr, msg []byte) {
	/* encode the message using the key file */
	msg = encode(msg, sock.Key)
	/* Create the datagram */
	datagram := create_message(sock.Source_address, addr, msg)
	/* Send the datagram and check for errors */
	_, err := sock.Connection.WriteToUDP([]byte(datagram), addr)
	check(err)
}
func receive_messages (sock *socket_info, send chan<- string, send_addr chan<- *net.UDPAddr) {
	/* The array that the message will be read into(max size of 250 bytes plus 8 bytes for info in datagram plus time and sender, etc */
	msg := make([]byte, 512)
	for {/* Infinite loop of receiving messgaes */
		/* Read from the udp socket(get sender address, number of bytes, and an error if needed */
		//message,addr,err := sock.ReadFromUDP(msg)
		n, addr,err := sock.Connection.ReadFromUDP(msg)
		check(err)
		/* Check if the checksum matches or not */
		checksum := calculate_checksum(get_ip_big_Endian(get_ip(sock.Source_address)), get_ip_big_Endian(get_ip(addr)), msg[0:n])
		if int(checksum[0]) + int(checksum[1])<<8 == 0x0000 {/* Checksum was correct (0000 and FFFF are the same because this was cast from int16 to int)*/
			/* leave the rest of the datagram (ports, size, etc) then decrypt everything */
			data := msg[8:n]
			data = decode(data, sock.Key)
			/* Send the message back to main thread */
			send <- string(data)
			/* Send the address back also so that we can respond */
			send_addr <- addr
		}else{
			fmt.Printf("Checksums do not match. Discarding %X", checksum) /* Without an ACK the message will be resent eventually anyway also this line would not be necessary except for debugging*/
		}
	}
}
func client(sock *socket_info) {
	// Channel to get information from socket receive
	recv_msg := make(chan string)
	recv_addr := make(chan *net.UDPAddr)
	/* Start a new goroutine for handlin things */
	go receive_messages(sock, recv_msg, recv_addr)

	/* Read inpput from user  */
	recv_input := make(chan string)
	/* Go routine to get messages from socket */
	go read_input(recv_input)

	try_sending_message := func(msg string, timeout *time.Timer){
		/* Encode the message before sending */
		msg_encoded := encode([]byte(msg), sock.Key)
		/* encode the message properly */
		datagram := create_message(sock.Source_address, sock.Destination_address, msg_encoded)
		/* send the message that the user entered */
		_,err := sock.Connection.Write([]byte(datagram))
		check(err)
		/* Start a new thread with a timer, and if the timer goes off, we need to resend the message */
		<-timeout.C/* If this goes off, we resend the message */
		recv_input <- string(msg) /* Resend the message */
	}
	/* Infinite loop as long as the user wants to send messages (until ctrl+c */
	var timeouts []*time.Timer
	for {
		select{//TODO set some sort of timeout for responses
			case msg_send := <-recv_input: /* user entered text in the console, so send the message */
				n := 0//TODO if this is an exact multiple 250 it will send the last message twice
				//for ; n + 250 < len(msg_send); n += 250 {
				if len(msg_send) > 250 {
					msg_send = msg_send[0:251]//Get the first 250 characters, truncate the rest
				}
					//msg := msg_send[n:n+250]
					//timeout = time.NewTimer(time.Second * 2)
					//timeouts = append(timeouts, timeout)
					//go try_sending_message(msg, timeout)
				//}
					msg := msg_send[n:]
				timeout := time.NewTimer(time.Second * 2)
				timeouts = append(timeouts, timeout)
				go try_sending_message(msg, timeout)
				fmt.Printf("\033[H\033[2J")
			case msg_recv := <-recv_msg:
				_ = <-recv_addr /* We do not need address so discard it from the channel */
				fmt.Println("got a message: " + msg_recv)
				for _, timeout := range timeouts {
					timeout.Stop() /* Does nothing if the timer is not running, and stops the resend if it is running */
				}
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

func main(){
	/*********************
	*    SERVER          *
	*********************/
	if len(os.Args) == 5 && os.Args[1] == "server" {
		/* Create the UDP address for the server */
		ServerAddr, err := net.ResolveUDPAddr("udp", os.Args[2] + ":" + os.Args[3])
		check(err)
		/* No need for a destination address in server */
		/* Now listen at selected port */
		ServerConn, err := net.ListenUDP("udp", ServerAddr)
		check(err)
		/* Close the server later (whenever main closes) */
		defer ServerConn.Close()

		sock := &socket_info {
			Source_address: ServerAddr,
			Connection: ServerConn,
			Key: read_file(os.Args[4])}
		server(sock)
		os.Exit(0)
	}
	/*********************
	*    CLIENT          *
	*********************/
	if len(os.Args) == 7 && os.Args[1] == "client" {
		/* Create the destination information */
		ServerAddr,err := net.ResolveUDPAddr("udp", os.Args[4] + ":" + os.Args[5])
		check(err)

		/* Se the source information */
		LocalAddr, err := net.ResolveUDPAddr("udp", os.Args[2] + ":" + os.Args[3])
		check(err)

		/* Create the socket */
		Conn, err := net.DialUDP("udp", LocalAddr, ServerAddr)
		check(err)
		/* Close the socket when the method exits */
		defer Conn.Close()
		sock := &socket_info {
			Source_address: LocalAddr,
			Destination_address: ServerAddr,
			Connection: Conn,
			Key: read_file(os.Args[6])}
		client(sock)
		os.Exit(0)
	}
	/*********************
	*      ERROR         *
	*********************/
	/* This should never get ran unless the input args are wrong */
	fmt.Fprintf(os.Stderr, "Usage: ./UDPChat  client or server\n" +
						   "       ./UDPChat server <source ip> <source port> <Keyfile>\n" +
						   "       ./UDPChat client <source ip> <source port> <destination ip> <destionation port> <Keyfile>\n")
	os.Exit(1)
}
