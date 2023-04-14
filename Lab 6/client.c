#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>


#define PORT 4444

int main()
{

int clientSocket, ret;


struct sockaddr_in cliAddr;
struct sockaddr_in serverAddr;



char cmsg[200];
char buffer[1024];

clientSocket = socket(AF_INET,
SOCK_STREAM, 0);




memset(&cliAddr, '\0', sizeof(cliAddr));

serverAddr.sin_family = AF_INET;
serverAddr.sin_port = htons(PORT);

serverAddr.sin_addr.s_addr= inet_addr("127.0.0.1");

ret = connect(clientSocket,(struct sockaddr*)&serverAddr,sizeof(serverAddr));


printf("Connected to Server.\n");

while (strcmp(cmsg,"exit")!=0) {

memset(buffer, '\0', sizeof(buffer));
      recv(clientSocket, &buffer, sizeof(buffer), 0);
   printf("\n %s \n", buffer);
   printf("\n Enter mess to send \n");
       
         scanf("%s",cmsg);
send(clientSocket, cmsg, sizeof(cmsg), 0);

}

return 0;
}