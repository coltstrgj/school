I wanted to make this file in markdown (for pretty formatting like on github) but I assume you will be reading it in a terminal, so I will leave the formatting out

This program generates and decrypts ciphertext from files. 

--------------------
Usage: B/S input_file output_file key_file E/D
				1				2						3				 4			5
1: B/S for Block or stream cipher respectively
2: the name (and path) for the input file
3: the name (and path) for output file
4: the name (and path) for the file containing the key that will be used for encryption and decryption
5: E/D for Encrypt or Decrypt respectively

Example: running "./cipher B message.txt cipher_text key.txt E"
  will use a Block Cipher(1) and Encrypt(5) the data contained in message.txt(2) using the key contained in key.txt(4). The resulting output will be written to cipher_text (3).

--------------------
Building
type "make" in console. This will build a cipher.o file and then build the "cipher" executable

--------------------
Problems and explanation for code.
Coding decisions: There are several things that I could do to improve this program. I could make it bundles faster by inlining a few things, and changing some things that I did for sucinctness of code, and otherwise readability. These changes would not be hard to make, and could imporve the speed greatly, but it is already fast enough to be un-noticable to most users (and on "small" files)

Problems faced: The instructions say that the key for stream cipher is in hexadecimal. This is entirely untrue. I read in this file, and converted to hex to get the key 00000001.....11111111. This led to a very different ciphertext output. I had to leave this input in ascii format in order to get the same output from the example. 
