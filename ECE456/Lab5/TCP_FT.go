//////////////////////////////////////////
//Author: Colt Darien                   //
//This program is Lab5 for ECE456 at CSU// 
//Spring 2016                           //
//////////////////////////////////////////

/*
//See README for more details about this program
*/

package main

import(
	"fmt"
	"os"
	"strings"
	"io"
	"bufio"
	"net"
)

///////////////////////////////UTILITY FUNCTIONS////////////////////////////////////////////////////

func check(e error) {
	if e != nil {
		panic(e)
	}
}

///////////////////////////////////////SERVER ///////////////////////////////////////////////////////
//TODO do I do anything if for timeout on my replies?
func server(serv net.Listener) {
	/* Run over and over (accept as many files until user kills program) */
	for {
		/* Accept any incoming connection */
		conn, err := serv.Accept()
		check(err)
		/* Read the incoming filename */
		filename, _ := bufio.NewReader(conn).ReadString('\n')
		/* Remove the newline from filename (because messages end with newline) */
		filename = filename[:len(filename)-1]

		/* Ask if server wants to keep file */
		reader := bufio.NewReader(os.Stdin)
		fmt.Printf("A user wants to send file: %s\n\tDo you wish to accept?(y/N)\n", filename)
		text, _ := reader.ReadString('\n')
		/* If the user does want this file, then move on, if not close connection */
		if (text[0] == 'y' || text[0] == 'Y') {
			/* Tell client we do want their file...by quoting 60's batman */
			conn.Write([]byte("Roger, Ready to move out!\n"))
			/* Open the file for writing */
			file,err := os.Create(filename)
			check(err)
			/* Close it if there are any problems, or when we exit this method */
			defer file.Close()
			io.Copy(file, conn)
		}else{
			/*Tell client we do not want their file */
			conn.Write([]byte("NaNaNa"))
		}
		/* File transfer is done, close this connection and wait for more */
		conn.Close()
		fmt.Println("File arrived successfully\n\nServer is ready, waiting for incoming connections")
	}
}

///////////////////////////////////////CLIENT  ///////////////////////////////////////////////////////

func client(server_conn net.Conn, full_filename string) {
	/* Open the file (to be sure it can be read before bothering with anything else) */
	file, err := os.Open(strings.TrimSpace(full_filename))
	check(err)
	defer file.Close()
	fmt.Println("Contacting Server")
	/* Send the filename (remove path) to server and await reply */
	filename := strings.Split(full_filename, "/")
	fmt.Fprintf(server_conn, filename[len(filename)-1] + "\n")
	reply, _ := bufio.NewReader(server_conn).ReadString('\n')
	if (reply == "NaNaNa") {/* They do not want file */
		fmt.Println("Server does not wish to accept file at this time\nCLOSING")
	} else {/* They do want it */
		fmt.Println("Server will accept the file, sending it now")
		/* Create the buffer (only send a max of this many bytes at a time) */
		buf := make([]byte, 1024)
		n, err := io.CopyBuffer(server_conn, file, buf)
		check(err)
		fmt.Printf("%d bytes of data were sent to the server\n",n)
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

func main(){
	/*********************
	*    SERVER          *
	*********************/
	if len(os.Args) == 3 && os.Args[1] == "server" {
		fmt.Println("Getting Server Ready")
		/* Listen at selected port */
		ServerConn, err := net.Listen("tcp", ":" + os.Args[2])
		check(err)
		/* Close the server later (whenever main closes including in a panic) */
		defer ServerConn.Close()
		fmt.Println("Server is ready, waiting for incoming connections")
		server(ServerConn)
		os.Exit(0)
	}
	/*********************
	*    CLIENT          *
	*********************/
	if len(os.Args) == 5 && os.Args[1] == "client" {
		/* Create the socket */
		Conn, err := net.Dial("tcp", os.Args[2] + ":" + os.Args[3])
		check(err)
		/* Close the socket when the method exits */
		defer Conn.Close()
		client(Conn, os.Args[4])
		os.Exit(0)
	}
	/*********************
	*      ERROR         *
	*********************/
	/* This should never get ran unless the input args are wrong */
	fmt.Fprintf(os.Stderr, "Usage: ./TCP_FT  client or server\n" +
						   "       ./TCP_FT server <source port>\n" +
						   "       ./TCP_FT client <destination ip> <destionation port> <Input File>\n")
	os.Exit(1)
}
