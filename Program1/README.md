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
to build
type "make" in console. This will build a cipher.o file and then build the "cipher" executable. 
