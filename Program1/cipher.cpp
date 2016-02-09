#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <stdlib.h>
#include <vector>
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

//Stream cipher

//You will XOR your input stream with the following data
//The key is (in Hex) "0123456789ABCDEF"
//Bit 0 from the input file will be XORed with Bit 0 from the key
//...
//Bit n-1 from the input file will be XORed with Bit n-1 from the key
//If you reach the end of the key, start over from the beginning.
//Note on the number of the bits. Since this is a stream, bit 0 is the first bit to arrive, bit 1 is the second bit and so forth. That means the leftmost bit of the first byte is bit 0. Same with the key.
//Encryption and decryption will performed with the same module that you design for the Stream Cipher. In other words, you do not have have to design separate modules for encryption and decryption in the Stream Encryption Mode.
int main (int argc, char **argv){
	bool block_cipher;//are we doing block cipher
	bool stream_cipher;//or stream cipher
	bool encrypt_data;
	bool decrypt_data;
	string input_file;
	string output_file;
	string key_file;
	//options B/S InFile OutFile KeyFile E/D
	string option;	
	if(argc != 6){//we have too few arguments
		cout << "Usage: 'B'/'S' input_file output_file key_file 'E'/'S'" << endl;
		cout << "'B' for block cipher, 'S' for stream cipher" << endl;
		cout << "The name of the file for input, the name of the file for output, and the name of the file containing the secret key" << endl;
	}
	// skip arg 0 because it is just this programs name
	option = argv[1];
	if(option )
	return 0;
}
