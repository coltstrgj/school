//////////////////////////////////////////
//Author: Colt Darien                   //
//This program is Lab1 for ECE456 at CSU// 
//Spring 2016                           //
//////////////////////////////////////////

/*
//See README for more details about this program
//To compile "go build Lab1.go"
//run the file "Lab1" if compiled, otherwise do "go run Lab1.go" to run in playground
*/

package main

import(
	"fmt"
	"os"
	"io/ioutil"
)
///////////////////////////////UTILITY FUNCTIONS////////////////////////////////////////////////////
func check(e error) {
	if e != nil {
		panic(e)
	}
}
func read_file(file_name string) []byte{
	data, _ := ioutil.ReadFile(file_name)
	data = data[0:len(data)-1]//get rid of the EOF character
	return data
}
func write_file(file_name string, data []byte) {
	file,err := os.Create(file_name)
	check(err)
	defer file.Close()//this is going to close the file after we return (defer is cool)
	_,err = file.Write(data)
	check(err)
}

//func read_data(data_file_name string) []byte{
//	data, _ := ioutil.ReadFile(data_file_name)
//	data = data[0:len(data)-1]//get rid of the EOF character
//	return data
//}
//func read_keys(key_file_name string)[]byte {
//	key, _ := ioutil.ReadFile(key_file_name)
//	key = key[0:len(key)-1]//get rid of the EOF
//	return key
//}





///////////////////////////////////////DECODE///////////////////////////////////////////////////////


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



///////////////////////////////////////ENCODE///////////////////////////////////////////////////////

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
func encode(data_file_name string, keys []byte, encoded_file_name string) []byte{
	//could just send data as input, but this is more modifiable if we need it to do something with network later in class
//data := read_data(data_file_name)
	data := read_file(data_file_name)
	for i :=0; i<len(data);i+=2{
		//make a block (which in this case is a pointer) from the data. +2 because bound is [inclusive, exclusive]
		block := data[i:i+2]
		//iterate over all keys (we encode blocks first)
		for _, key := range keys{
			encode_block(block, key)
		}
	}
	write_file(encoded_file_name, data)
	return data
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////
func main(){
/*///////////////This runs my test case/////////////////////////
	//read the keys from Keys.txt
	keys := read_file("Keys.txt")
	//this line is equivalent to "var encoded []byte = encode(..." but is cleaner
	//Encoded_data is not a .text file, but you can use cat to see what is in it if you want
	encoded := encode("Message.txt", keys, "Encoded_data")
	//reads data (again, because it is read in encode as well, this is just so I can print it)
	data := read_file("Message.txt")
	//print the data that we just read
	fmt.Println(data)
	//this line prints the data after it is encoded output in decimal (of the byte value)
	fmt.Println(encoded)
	//encoded is actually changing too, (pointer magic) but this makes code easier to read
	fmt.Println(string(encoded))
	//actually decode the data
	decode(encoded, keys)
	//Print the message that we got back after encoding and decoding
	fmt.Println(string(encoded))
*/



/*/////////////////////This generates a new key file
	new_keys := []byte{0x2b, 0x00, 0xB9, 0x20, 0x6A, 0x3F, 0xDC, 0xCC, 0xBA, 0x92}
	fmt.Println(new_keys)
	//I called it new_keys because it is not really text at this point
	write_file("new_keys", new_keys)
*/
}
