#!/bin/sh
mes='Message.txt'
keys='Keys.txt'
sendip="192.168.1.109"
recip="74.86.29.55"
sendport="1337"
recport="40401"

echo Running tests
echo --------------------------------------------------------------------------------
echo Encrypting message : $mes with key file $keys
echo
go run crypto.go encrypt $mes $keys encrypted_message.bin

echo --------------------------------------------------------------------------------
echo Sending message from $sendip:$sendport to $recip:$recport
echo
go run sender.go encrypted_message.bin $sendip $recip $sendport $recport message_datagram.bin

echo --------------------------------------------------------------------------------
echo Receiving message_datagram.bin from $sendip to $recip
echo
go run receiver.go message_datagram.bin $sendip $recip received_message.bin
#at this point, received_message.bin and encrypted_message.bin should be the exact same

echo --------------------------------------------------------------------------------
echo decrypting message message.bin with key file $keys
echo
go run crypto.go decrypt received_message.bin $keys received_message.txt
echo -n "Final Message is: "
cat received_message.txt 

echo Differences between the two files are
diff $mes received_message.txt
