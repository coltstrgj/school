//Colt Darien
//CS356 Assignment 1
//using c++ 11 (so pretty much every arg is a pointer and not actually passed



#include <iostream>
#include <fstream>
#include <string>
#include <streambuf>
//#include <unistd.h>
#include <stdlib.h>
#include <vector>

using std::cout;
using std::string;
using std::endl;

//Requirements

//This program should be written in C or C++.
//Your submittal should include a Makefile.
//Your program will take 5 arguments in the order defined below. Your program should ensure there are 5 arguments, and that each argument is error-checked appropriately.
	//The first argument is either a 'B' or a 'S'.
		//B means you will use your block cipher function
		//S means you will use your stream cipher function.
		//Your program should terminate if other than a 'B' or an 'S' is entered with an appropriate error message.
	//The second argument is the input file name.
		//Your program should terminate with an appropriate error message if the file does not exist.
	//The third argument is the output file name.
	//The fourth argument is the keyfile
		//The keyfile contains the symmetric key in ASCII format ("ABCDEFGH"). The keysize for Block Encryption Mode would be 64 bits (8 bytes) and can be of any length for Stream Encryption Mode. Your program will read in the contents of the keyfile and use it to encrypt the plaintext provided in the input file. The keyfile will not contain a terminating "\n"(newline) character.
	//The fifth argument is the 'mode of operation' which can be either 'E' for encryption or 'D' for decryption.
	//Altough the same 'E' or 'D' module can be used for Stream Ciphers, the same does not apply for Block Ciphers as will be explained below in the 'Description of the algorithms' section. In the 'E' mode you would encrypt a plaintext using a key and produce a ciphertext. We can then evaluate your encrypted output against the output produced by our own program with the same key. Similarly, in the 'D' mode your program is expected to decrypt an already encrypted text, with the same symmetric key, and produce expected plaintext results.
	//Your program will read in the input file.
	//End of line characters are data just like any other character.
	//You may assume the file is in multiples of 8 bits.
	//Your file will write the output file based on the arguments.
	//Your file should be in 64-bit blocks in block mode.
	//This means you must pad blocks that are not 64 bits in length.
//Each padding byte should be 0X80. Because the input file will be a multiple of 8 bits or 1 byte, padding (if required) can also be done in multiples of 8 bits or 1 byte. For the purpose of this project you will be using the byte value 0X80 in hex or 128 in decimal. Becasue, the input file is in ASCII and the padding value (0X80) falls outside the ASCII (0-127) range, it allows us distinguish padding bytes from plaintext bytes.
//Your file should be in 8-bit multiples in stream mode.
//Your file will be read in by a program that isn't yours to test.
//If the input file is empty, the output file should be empty.


//Block cipher

//The encryption would be a three step process : pad (if required) -> encrypt (using XOR) -> swap
//Your block size will be 64 bits. As mentioned earlier, if a block is found to be less than 64 bits, it should be padded with as many (0X80) bytes so as to make 64 bits or 8 bytes.
//Your algorithm will XOR the 64 bit data block with the 64 bit key in a bitwise manner, i.e. each bit of the key starting from the left most bit will be XORed with each bit of a 64 bit data block, starting from the left hand side.
//Your algorithm will then swap bytes of the XORed output using the following algorithm.
//Let 'start' and 'end' be pointers which point to the start and end of the XORed output string.
//For each byte of the key, starting from the left most byte or 0th byte, you calculate the following : (ASCII value of the byte or character)mod2. This would give you either 0 or 1.
//If the value is 0 you do not swap anything and move to the next byte of the plaintext by incrementing the 'start' pointer. Otherwise, you swap the byte pointed by the 'start' pointer with that pointed by the 'end' pointer. Then increment the 'start' pointer so that it points to the next higher byte and decrement the 'end' pointer so that it points to the next lower byte. If the keysize is exhausted, you restart from the first byte of the key. This process is carried on until the 'start' and the 'end' pointers collide. The swap process stops and produces the required encrypted output.
//The decryption process is also of three steps but proceeds in the reverse order as the encryption process : swap -> decrypt (using XOR) -> remove padding (if required). The decrypted ouput should be written to the output file. Because, the decryption process occurs in the reverse direction of the encryption process, you cannot use the same module to perform both, altough the underlying logic will be the same.


void block_cipher_swap(string &data, string &key) {//swap bytes around based on the key
	int start_loc = 0;
	int end_loc = data.size() - 1;//get the location of the last character
	//	for(; start_loc < data.size(); ++start_loc) {//for all the characters in data, check key and swap if needed
	while(start_loc < end_loc){ //stop if we are with start at greater or equal to end
		if(((int)key[start_loc % key.size()]) % 2 == 1){//if this char in key is odd, swap start and end
			int tmp = data[start_loc];
			data[start_loc] = data[end_loc];//move char at end_loc to start_loc
			data[end_loc] = tmp; //change char at end_loc to the one that was start_loc
			--end_loc;//decrement end_loc to previous character
		}
		++start_loc;
	}
	return;
}


std::vector<string> split_blocks(string &data, int block_size){//split data into blocks of size block_size (in bytes, so 8 is 64 bits)
	std::vector<string> blocks;
	string sub_string;//the substring that we will use to hold blocks
	int loc=0;//this is the location we are in the string
	while((size_t)loc < data.size()){//we will exit the loop in the if statement (when substring is short
		sub_string = data.substr(loc,block_size);
		loc += block_size;
		blocks.push_back(sub_string);
	}
	return blocks;
}


void block_xor(string &data, string &key){
	//have to go byte by byte because I have no clue how to do it otherwise
	for(int i = 0; (size_t)i < data.size(); ++i){
		data[i] = data[i] ^ key[i];
	}
}


void block_cipher_encrypt(string &data, string &key, int block_size = 8){//used to decrypt data with the key. Passed reference, so we don't need to return anything
	data.resize(block_size - (data.size() % block_size) + data.size(), 0x80);
	//check if key is the correct size
	if(key.size() != (size_t)block_size){
		cout << "Error: Key file contains incorrectly formatted key" << endl;
		exit(1);
	}
	//split the full data into blocks
	//we don't necesarily need to split them, we could just create substrings instead, but this is readable, and can be easily modified
	std::vector<string> blocks = split_blocks(data, block_size);//split the data into blocks with default of size 64 bits (8 bytes)
	data = "";
	for (int i = 0; (size_t)i < blocks.size(); ++i){//iterate over all of the blocks
		//xor first
		block_xor(blocks[i], key);//xor the block with the key
		//TODO this should probably be in another loop for clarity, but this is easier
		data.replace(i * block_size, block_size, blocks[i]);
	}
	//swap things around
	block_cipher_swap(data, key);
	return;
}


void block_cipher_decrypt(string &data, string &key, int block_size = 8){//used to decrypt data with the key. Passed reference, so we don't need to return anything
	//check if key is the correct size
	if(key.size() != (size_t)block_size){
		cout << "Error: Key file contains incorrectly formatted key" << endl;
		exit(1);
	}
	//split the full data into blocks
	//we don't necesarily need to split them, we could just create substrings instead, but this is readable, and can be easily modified
	//swap things around before we xor (because we are decrypting
	block_cipher_swap(data, key);
	std::vector<string> blocks = split_blocks(data, block_size);//split the data into blocks with default of size 64 bits (8 bytes)
	for (int i = 0; (size_t)i < blocks.size(); ++i){//iterate over all of the blocks
		//swap first, then drcrypt
		block_xor(blocks[i], key);//xor the block with the key
		//TODO this should probably be in another loop for clarity, but this is easier
		data.replace(i * block_size, block_size, blocks[i]);
	}
	for(int i = 0; i < block_size; ++i){//check the last block for characters == 0x80
		if(data[data.size()-i-1] == 0x80)//roll through the last characters and if they are 0x80, delete them
			data.pop_back();
		else
			break;//otherwise we are done checking for pad, so exit the loop
	}
	return;
}


void stream_cipher(string &data, const std::vector<uint8_t> key){//stream cipher
	//key size does not matter (as long as it is a multiple of 1 byte)
	//data length does not matter either (also must be a multiple of bytes)
	char bit_mask; 
	uint8_t bit_loc = 128;//0b100000000; //use this to keep track of how many bits we have shifted in
	for(int i = 0; (size_t)i < data.size() * 8; ++i){
		bit_mask = bit_loc & key[(i / 8) % key.size()]; //and the bit_loc with the key character at i / 8 (i is a int, so this will always be int)
		if(bit_loc == 0b00000001)//if this is the last bit in byte, reset it
			bit_loc = 0b10000000;
		else
			bit_loc = bit_loc>>1;//shift thi s over to the next bit location
		data[i / 8] = data[i / 8] ^ bit_mask;//TODO i/8 takes time to calculate, so we could speed this up a little bit
	}
	return;
}

//Stream cipher

//You will XOR your input stream with the following data
//The key is (in Hex) "0123456789ABCDEF"
//Bit 0 from the input file will be XORed with Bit 0 from the key
//...
//Bit n-1 from the input file will be XORed with Bit n-1 from the key
//If you reach the end of the key, start over from the beginning.
//Note on the number of the bits. Since this is a stream, bit 0 is the first bit to arrive, bit 1 is the second bit and so forth. That means the leftmost bit of the first byte is bit 0. Same with the key.
//Encryption and decryption will performed with the same module that you design for the Stream Cipher. In other words, you do not have have to design separate modules for encryption and decryption in the Stream Encryption Mode.


std::vector<uint8_t> convert_hex(string data){//I could put this back into the key string as hex values (fake chars that may or may not be in ascii) 
	//but that would be confusing because it would not pring correctly or anything else
	std::vector<uint8_t> hex_data;
	uint8_t hex_value = 0b00000000;//initialize it to 0
	for (int i = 0; i < data.size(); ++i) {
		switch (data[i]) {
			case 'a': case 'b': case'c': case'd': case 'e': case 'f': //all of these use the same math
				//anding these together will generate the full byte if odd character, or initialize it if even
				hex_value = hex_value | (data[i] - 'a' + 10);// character minus 'a' will be between 0 and 5, then add 10 to make it match the hex value
				break;// leave this option
			case 'A': case 'B': case'C': case'D': case 'E': case 'F': //all of these use the same math
				//oring these together will generate the full byte if odd character, or initialize it if even
				hex_value = hex_value | (data[i] - 'A' + 10);// character minus 'A' will be between 0 and 5, then add 10 to make it match the hex value
				break;// leave this option
			case '0': case '1': case'2': case'3': case '4': case '5': case '6': case '7': case'8': case'9'://all of these use the same math
				hex_value = hex_value | (data[i] - '0');
		}
		if (i % 2 == 0){//if this is an even number we have to shift it over to make room for its less significant nibble
			hex_value = hex_value<<4;//shift to upper nibble
		} else {//we are on an odd one, so 
			hex_data.push_back(hex_value);//add it to the hex value
			hex_value = 0b00000000;//reset this value to zero for next byte
		}
	}
	return hex_data;
}


void write_file(string file_name, string data){
	std::ofstream file;
	file.open (file_name);
	//TODO maybe main only should crash, this could be bool, and if write fails, we return that instead of crashing here
	if (!file){
		cout << "Error: file " << file_name << " does not exist or is unreadable." << endl;
		exit(1);
	}
	file << data;//write the contents to a file
	file.close();
	return;
}

string read_file(string file_name) {
	//have to use .c_str() because if stream does not take pointer to string
	std::ifstream file(file_name.c_str());	//the file stream so that we can read
	string data;//the data that we read from the file
	
	if(!file){//Check to make sure that the file exists
		cout << "Error: file " << file_name << " does not exist or is unreadable." << endl;
		exit(1);
	}
	
	//allocate the string size first so that we don't have to re-allocate memory all the time
	file.seekg(0, std::ios::end);   
	data.reserve(file.tellg());
	file.seekg(0, std::ios::beg);

	//get the data out of the file
	data.assign((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
	
	//the data has a character at the end for some reason (newline or EOF or something) so we have to get rid of it
	//empty files to not have this character for some reason, so only delete it if string is greater than length 0
//if(!data.empty())
//	if(data[data.size() - 1] == '\n')//if it is a new line, get rid of it so that this will work either way
//		data.erase(data.size()-1,1); //get rid of the last character (Probably EOF or something) 
	return data;
}


int main (int argc, char **argv){
	bool use_block_cipher;//are we doing block cipher or stream cipher (block is True, otherwise we are stream cipher
	bool encrypt_data;//encrypt = true, decrypt = false
	string input_file;
	string output_file;
	string key_file;
	
	//We should really use boost or get opt or something for this, but because this assignment is so structured (all args in certain order) we don't need to
	
	//options B/S InFile OutFile KeyFile E/D
	string option;	
	if(argc != 6){//we have too few arguments
		cout << "Usage: 'B'/'S' input_file output_file key_file 'E'/'D'\n"
			<< "'B' for block cipher, 'S' for stream cipher\n"
			<< "The name of the file for input, the name of the file for output, and the name of the file containing the secret key" << std::endl;
		return 1;//return with an error
	}
	// skip arg 0 because it is just this programs name
	//get the first argument
	option = argv[1];
	if(option == "B")
		use_block_cipher = 1;//we are using block cipher
	if(option == "S")
		use_block_cipher = 0;//we are using stream cipher
	else if(!use_block_cipher){// if they are both 0, then the input was wrong
		cout << "Error: First flag must be either B or S" << endl;
		return 1;
	}
	//get the file names
	input_file = argv[2];
	output_file = argv[3];
	key_file = argv[4];

	//get the encrypt or decrypt argument
	option = argv[5];
	if(option == "E")
		encrypt_data = 1;//We are encrypting
	if(option == "D")
		encrypt_data = 0;
	else if(!encrypt_data){// if they are both 0, then the input was wrong
		cout << "Error: Fifth flag must be either E or D" << endl;
		return 1;
	}
	//Read in the input file
	string data = read_file(input_file);
	//Read in the key file
	string key = read_file(key_file);
	
	if(use_block_cipher){
		if(encrypt_data)
			block_cipher_encrypt(data, key);
		else
			block_cipher_decrypt(data, key);
	}else{
		//no need to check encrypt or decrypt because it is symmetric 
		std::vector<uint8_t> key_hex = convert_hex(key);//change the text we read in to hexadecimal
		//stored as unint, but is hexadecimal
		stream_cipher(data, key_hex);
	}
	string master = read_file("blockCipherText");
	string mine = read_file("blockCipherText.mine");
	cout << "mine " << mine.size() << " master " << master.size() << endl;
	//write to the output file
	write_file(output_file, data);

	return 0;
}
