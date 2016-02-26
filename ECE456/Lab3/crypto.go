//////////////////////////////////////////
//Author: Colt Darien                   //
//This program is Lab1 for ECE456 at CSU// 
//Spring 2016                           //
//////////////////////////////////////////

/*
//See README for more details about this program
//To compile "go build crypto.go"
//run the file "crypto" if compiled, otherwise do "go run crypto.go" to run in playground
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
	data, err := ioutil.ReadFile(file_name)
	check(err)
	if _, err := os.Stat(file_name); os.IsNotExist(err) {
		fmt.Println("ERROR: File Does not exist or is blank")
		// path/to/whatever does not exist
	}
	if len(data) <= 2 {
		panic("File too short")
	}
	//data = data[0:len(data)-1]//get rid of the EOF character
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
func encode(data []byte, keys []byte) []byte{
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


/////////////////////////////////////////////////////////////////////////////////////////////////////////////
func main(){
	var encrypt bool

	if (len(os.Args) != 5) {/*check that there are enough args*/
		fmt.Println("Usage: crypto <encrypt|decrypt> <input file> <key file> <output file>")
		os.Exit(1)
	}
	/* if the args are good, we continue, otherwise let user know */
	if (os.Args[1] == string("encrypt") || os.Args[1] == "decrypt") {
		encrypt = os.Args[1] == "encrypt" /* encrypt or decrypt? */
	}else{
		fmt.Println("Usage: crypto <encrypt|decrypt> <input file> <key file> <output file>")
		os.Exit(1)
	}
	/* get the keys and data from files */
	data := read_file(os.Args[2])
	keys := read_file(os.Args[3])
	if (encrypt) {
		data = encode(data,keys)
	}else{
		data = decode(data,keys)
	}
	/* write the crypto to file */
	write_file(os.Args[4], data)


	/*/////////////////////This generates a new key file
	new_keys := []byte{0x2b, 0x00, 0xB9, 0x20, 0x6A, 0x3F, 0xDC, 0xCC, 0xBA, 0x92}
	fmt.Println(new_keys)
	//I called it new_keys because it is not really text at this point
	write_file("new_keys", new_keys)
	*/
}
