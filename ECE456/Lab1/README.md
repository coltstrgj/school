#Lab1 for ECE456
##Instructions
This program is written in golang.
to run it do either
 "go run Lab1.go" to run it in the go 
 OR
 "go build Lab1.go" to compile it
  then
 "./Lab1" to run it
if you want to generate your own keys, add the following to main
  write_file("your file name", {0xXW, 0xYZ, ...the rest of the keys}) //where WXYZ are the hex encoded bytes you want to use for keys. Do this before using the key file.
  As you can see, I have commented out a line that will make a file called "new_keys" feel free to use this. 

###Main:
This should be all that you have to edit when testing.

###The following should not need any modifications from you to work
###encode:
takes 3 arguments input file, keys (an array of bytes), and output file then reads in the message and cuts it in to blocks and encodes it with the keys

###encode_block:
just swaps the bytes sides and xors one with the key

###decode:
reads in the encoded data and splits them into blocks. Then it decodes them

###decode_block:
almost the same as encode, but it xors the opposite side and un swaps the sides of the bytes
