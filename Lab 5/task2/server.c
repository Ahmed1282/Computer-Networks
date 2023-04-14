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
	int client_socket;
	
    while (strcmp(buf, "Exit" != 0)){

        printf("\n Connecting\n");
        client_socket = accept(server_socket, NULL, NULL);  
        printf("\nClinet %d Connected\n", client_socket);

        pid_t PID = fork();

        if(PID == 1) //Parent
        {
            wait(NULL);

        }
        if (PID == 0) //Child
        {        
            recv(client_socket, &buf, sizeof(buf), 0);
            printf("\nMessage Received: %s \n", buf);

            //Reverse
            size_t l = strlen(buf);
            char* message = (char*)malloc ( (l+1) * sizeof(char));
            message[l] = '\0';
            int i;
            for(int i = 0;i < l; i++) {
                message[i] = buf[l - 1 - i];
            }

            printf("RS: %s\n", message);
            
            // send the message
            send(client_socket, server_message, sizeof(server_message), 0);
        }
        
    }
	
	// close the socket
	close(server_socket);
	
	return 0;
}