// Server side implementation of UDP client-server model
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT	 8080
#define MAXLINE 1024

// Driver code
int main() {
	int sockfd;
	char buffer[MAXLINE];
	char *hello[MAXLINE];
	struct sockaddr_in servaddr, cliaddr;
	
	// Creating socket file descriptor
	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}
	
	//memset(&servaddr, 0, sizeof(servaddr));
	//memset(&cliaddr, 0, sizeof(cliaddr));
	
	// Filling server information
	servaddr.sin_family = AF_INET; // IPv4
	servaddr.sin_addr.s_addr = INADDR_ANY;
	servaddr.sin_port = htons(PORT);
	
	// Bind the socket with the server address
	if ( bind(sockfd, (const struct sockaddr *)&servaddr,
			sizeof(servaddr)) < 0 )
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
	
	int len, n;

	//LOOP

	while (strcmp(hello, "exit") != 0) {
	//-------------------------------------------------------//
	len = sizeof(cliaddr); //len is value/resuslt

	n = recvfrom(sockfd, (char *)buffer, MAXLINE,
				0, ( struct sockaddr *) &cliaddr,
				&len);
	buffer[n] = '\0';
	printf("Client : %s\n", buffer);

	//reverse
  size_t l = strlen(buffer);
  char* r = (char*)malloc((l + 1) * sizeof(char));
  r[l] = '\0';
  int i;
  for(i = 0; i < l; i++) {
    r[i] = buffer[l - 1 - i];
  }
  printf("normal: %s\n", buffer);
  printf("reverse: %s", r);
 
	//----//

	sendto(sockfd, (const char *)r, strlen(r),
		0, (const struct sockaddr *) &cliaddr,
			len);
	printf("\nHello message sent.\n");
	 free(r);
	//-------------------------------------------------------//
	}
	
	
	return 0;
}
