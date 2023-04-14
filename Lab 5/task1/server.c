#include <stdio.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>

int main() {

	char server_message[256] = "Hi, Yes you have reached the server!";
	char buf[200];
	// create the server socket
	int server_socket;
	server_socket = socket(AF_INET, SOCK_STREAM, 0);

	
	// define the server address
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(3001);
	server_address.sin_addr.s_addr = INADDR_ANY;

	// bind the socket to our specified IP and port
	bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));
	listen(server_socket, 5);
	int client_socket[2];

	for(int i=0; i<2; i++){
	client_socket[i] = accept(server_socket, NULL, NULL);
	}
	// send the message
	while(strcmp(buf, "exit") != 0){
	recv(client_socket[0], &buf, sizeof(buf), 0);
	//rintf("\n %s \n", buf);
	send(client_socket[1], buf, sizeof(buf), 0);
	}
	// close the socket
	close(server_socket);
	
	return 0;
}