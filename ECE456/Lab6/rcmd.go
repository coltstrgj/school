//////////////////////////////////////////
//Author: Colt Darien                   //
//This program is Lab5 for ECE456 at CSU// 
//Spring 2016                           //
//////////////////////////////////////////

/*
//See README for more details about this program
*/

// To use:
package main
/// Three slash means I am using it to debug or something, and will not be there by the end
// and /**/ are for comments, I will use /* */ from now on, but it is too late

import(
	"fmt"
	"bytes"
	"strconv"
	"net"
	"os"
	"time"
	"bufio"
	"os/exec"
	"encoding/json"
)

//Struct for messages
type Message struct{
	Command string `json:"command"`//Should be either command, response, or request so that the server/node knows how to continue
	Arguments string `json:"args"`//This will be the name of the node that is sending 
	Count string `json:"count"`
	Delay string `json:"delay"`//How long to delay between running the commands
}

/* Used to check errors (avoids a lot of clutter in other code)  */
func check(e error) {
	if e != nil {
		panic(e)
	}
}

/* This will take input and un-marshal it (from json) into a map */
func unmarshal_message(message []byte) map[string]string{
	/* Maps are cool, take a look at them  */
	var dat map[string]string
	json.Unmarshal(message, &dat)
	return dat
}

/*Format the message with json*/
func format_message(command_to_run string, arguments string, count string, delay string) []byte{
	message_formatted := &Message{
		Command: command_to_run,
		Arguments: arguments,
		Count: count,
		Delay: delay}
	//Now actually format it
	message, err := json.Marshal(message_formatted)
	check(err)
	/* Check for errors */
	return message
}


//func read_input(send chan<- string) { /* This is to read input from keyboard, we will remove it when this is fully working  */
//	reader := bufio.NewReader(os.Stdin)
//	/*Get the input, This will change in the future (when done testing) TODO also get rid of newline if you feel like it*/
//	for {
//		fmt.Print("Enter text: ")
//		input,_  := reader.ReadString('\n')
//		input = input[:len(input)-1]
//		send <- input
//	}
//}

/////////////////////////////////SERVER//////////////////////////////////////

/* Runs every time a client tries to connect */
func connection_handler(conn net.Conn) {

	/* Read the incoming until we get a 0xFF (which is what I chose for my terminating character. This can be easily changed, it was just for debugging purposes */
	recv_message, err := bufio.NewReader(conn).ReadString(byte(0xFF))
	check(err)
	/* Remove the final byte from message (because messages are terminated with a byte that is not actual text) */
	recv_message = recv_message[:len(recv_message)-1]
	//fmt.Println(recv_message)
	/* The message is Json formatted, we want to return it as a map */
	message := unmarshal_message([]byte(recv_message))
	fmt.Printf("\nRunning \"%s %s\" every %s seconds for %s iterations\n", message["command"], message["args"], message["delay"], message["count"])


	count, _ := strconv.Atoi(message["count"])
	delay, _ := strconv.Atoi(message["delay"])

	cmd := exec.Command(message["command"], message["args"])
	//cmd.Stdin = strings.NewReader("some input")
	var out bytes.Buffer
	cmd.Stdout = &out //conn.Write

	err = cmd.Run()
	check(err)
	cmd.Wait()
	output := []byte(out.String())
	output = append(output, byte(0xFF))
	conn.Write(output)

	for i :=1; i < count; i++ {
		out.Reset()
		time.Sleep(time.Duration(delay) * time.Second)

		cmd := exec.Command(message["command"], message["args"])
		cmd.Stdout = &out //conn.Write

		err = cmd.Run()
		check(err)
		cmd.Wait()
		output := []byte(out.String())
		output = append(output, byte(0xFF))
		conn.Write(output)
	}
	/* Tell them we are finished */
	output = []byte("DONE")
	output = append(output, byte(0xFF))
	fmt.Println("\n\tsending: " + string(output) + "\n")
	_, err = conn.Write(output)
	fmt.Println("Done\n")
	check(err)
	conn.Close()
}


//TODO what do I name this thing?
/* ch_send and ch_recv is only used for communication to main thread */
/* ch_node_send and ch_node_recv are channels to communicate to the socket (which in turn sends to the actual node) */
func Server (port string) {
	/* This will create and setup the TCP socket to listen for all connections */
	req_server, err := net.Listen("tcp", ":" + port)
	check(err)
	fmt.Println("Server is ready, waiting for incoming connections")
	/* Close the server later (whenever main closes including in a panic) */
	defer req_server.Close()
	for {
		/* Accept any incoming connection */
		conn, _ := req_server.Accept()
		go connection_handler(conn)
	}
}


/////////////////////////////////////CLIENT////////////////////////

func Client(url string, command string, args string, count string, delay string) {
	server_conn, err := net.Dial("tcp", url)
	defer server_conn.Close()
	/* Check this error by hand */
	if err != nil {
		fmt.Println("Server refused connection request.\n are input arguments correct? (run with --help)\n otherwise it could be on a different port, not running, or there are network problems")
		os.Exit(1)
	}
	msg := format_message(command, args, count, delay)
	msg = append(msg, byte(0xFF))
	_, err = server_conn.Write([]byte(msg))
	/* Loop until we get one that works for us and server */
	for {
		reply, _ := bufio.NewReader(server_conn).ReadString(byte(0xFF))
		if len(reply) == 0 {
			break
		}
		/* Get rid of last character */
		reply = reply[:len(reply)-1]
		if reply == "DONE" {
			/* The server is done doing what it was doing */
			break
		} else {
			fmt.Println(reply + "\n")
		}
	}
	fmt.Println("Done")
}

//////////////////////////MAIN////////////////////////////////////
func main(){
	/*********************
	*    SERVER          *
	*********************/
	if len(os.Args) == 3 && os.Args[1] == "server" {
		fmt.Println("Getting Server Ready")
		Server(os.Args[2])
		os.Exit(0)
	}
	/*********************
	*    CLIENT          *
	*********************/
	if len(os.Args) == 7 && os.Args[1] == "client" {
		Client(os.Args[2], os.Args[3], os.Args[4], os.Args[5], os.Args[6])
		os.Exit(0)
	}
	/*********************
	*      ERROR         *
	*********************/
	/* This should never get ran unless the input args are wrong */
	fmt.Fprintf(os.Stderr, "Usage: ./rcmd server <source port>\n" +
						   "       ./rcmd client <destination ip:destination port> <command> <arguments> <iterations> <delay>\n")
	os.Exit(1)
}
