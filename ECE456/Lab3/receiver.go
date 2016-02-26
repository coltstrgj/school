//////////////////////////////////////////
//Author: Colt Darien                   //
//This program is Lab3 for ECE456 at CSU// 
//Spring 2016                           //
//////////////////////////////////////////

/*
//See README for more details about this program
//To compile "go build receiver.go"
//run the file "receiver" if compiled, otherwise do "go run receiver.go" to run in playground
*/

package main

import(
	"fmt"
	"os"
	"strings"
	"io/ioutil"
	"strconv"
)

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

///////////////////////////////////////DECODE///////////////////////////////////////////////////////

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

	checksum_byte = append(checksum_byte, byte(checksum>>8), byte(checksum))//convert this to slice of bytes
	return checksum_byte //invert evrything (ones complement) also done in previous line
}

///////////////////////////////////////Parse Arguments//////////////////////////////////////////////

func get_ip_big_Endian(address string) []byte{
	var ip []byte
	octets_string := strings.Split(address, ".")
	if len(octets_string) != 4 {
		fmt.Println("Error: Address should be of the form ###.###.###.### where all values are less than 255")
		os.Exit(1)
	}
	for _, octet := range octets_string {//iterate over all of the octet strings and change them to ints
		octet_int, _ := strconv.Atoi(octet)
		if octet_int > 255{
			fmt.Println("Error: Address should be of the form ###.###.###.### where all values are less than 255")
		}
		ip = append(ip, byte(octet_int))//transform the octet string to int and add it to the slice
	}
	//reverse the order of the octets to be big endian
	for i, j := 0, len(ip)-1; i < j; i, j = i+1, j-1 {
		ip[i], ip[j] = ip[j], ip[i]
	}
	return ip
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

func main(){
	var sender_ip, destination_ip []byte
	var datagram []byte
	if (len(os.Args) != 5) {/*check that there are enough args*/
		fmt.Println("Usage: receiver <datagram file> <source_ip> <destination_ip> <data file>")
		os.Exit(1)
	}
	sender_ip = get_ip_big_Endian(os.Args[2])//get the data from arg[2] (sender ip) and format it to int8
	destination_ip = get_ip_big_Endian(os.Args[3])//get the data from args[3] (destination ip) and format to int8
	//Read the data from the input file
	datagram = read_file(os.Args[1])
	//calculate the checksum
	checksum := calculate_checksum(sender_ip, destination_ip, datagram)
	//Pring information so that the user can see it
	fmt.Println("Big Endian:")
	fmt.Printf("\tSenderip: \t\t\t%v \n\tDestination ip: \t\t%v\n", sender_ip, destination_ip)//output the information for user to see before writing
	fmt.Printf("Datagram reported Size(bytes): %d\nDatagram actual size  Size (byte): %d\n", int(datagram[4]) + int(datagram[5])<<8, len(datagram))
	fmt.Printf("Checksum:%X\n", checksum)
	if int(checksum[0]) + int(checksum[1])<<8 == 0xFFFF  {
		fmt.Println("Yay, Checksum")
		data := datagram[8:]
		write_file(os.Args[4], data)
	}else{
		fmt.Println("Checksums do not match. Discarding message")
	}
	os.Exit(0)
}

