#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>


#define PORT 4444
int getnum (char string2[200])
{
int num;
if(strcmp("One", string2) == 0)
{
num = 1;
}
else if ( strcmp("Two", string2) == 0)
{
num = 2;

}
else if ( strcmp("Three", string2) == 0)
{
num = 3;

}
else if ( strcmp("Four", string2) == 0)
{
num = 4;

}
else if ( strcmp("Five", string2) == 0)
{
num = 5;

}
else if ( strcmp("Six", string2) == 0)
{

num = 6;
}
else if ( strcmp("Seven", string2) == 0)
{
num = 7;

}
else if ( strcmp("Eight", string2) == 0)
{
num = 8;

}
else if ( strcmp("Nine", string2) == 0)
{

num = 9;
}
else if ( strcmp("Ten", string2) == 0)
{
num= 10;

}

return num;
}




int main()
{
char msg[200] = "";
int sockfd, ret;


struct sockaddr_in serverAddr;

int clientSocket;


struct sockaddr_in cliAddr;

socklen_t addr_size;


pid_t childpid;


sockfd = socket(AF_INET, SOCK_STREAM, 0);



memset(&serverAddr, '\0',sizeof(serverAddr));

serverAddr.sin_family = AF_INET;
serverAddr.sin_port = htons(PORT);


serverAddr.sin_addr.s_addr= inet_addr("127.0.0.1");


ret = bind(sockfd,(struct sockaddr*)&serverAddr,sizeof(serverAddr));



if (listen(sockfd, 5) == 0) {
printf("Listening...\n\n");
}

int cnt = 0;
while (1) {


clientSocket = accept(sockfd, (struct sockaddr*)&cliAddr,&addr_size);

if (clientSocket < 0 ) {
exit(1);
}


printf("Connection accepted from %s:%d\n",inet_ntoa(cliAddr.sin_addr),ntohs(cliAddr.sin_port));

printf("Clients connected: %d\n\n",++cnt);

if ((childpid = fork()) == 0) {


close(sockfd);
                            char string1[200]="";
 char string2[200]="";
printf("in child");
strncpy(msg,"hello please enter a number",200);connect(clientSocket,(struct sockaddr*)&serverAddr,sizeof(serverAddr));
send(clientSocket,msg,
strlen(msg), 0);
                      recv(clientSocket, &msg, sizeof(msg), 0);
                     int num = atoi(msg);
if(num==1 || num==3 || num==2||num==5){
                        strncpy(msg,"hello please enter string1",200);
send(clientSocket,msg,strlen(msg), 0);
                             recv(clientSocket, &string1, sizeof(string1), 0);
                          strncpy(msg,"hello please enter string2",200);
                         send(clientSocket,msg,strlen(msg), 0);
                             recv(clientSocket, &string2, sizeof(string2), 0);

}
                            if(num==1){
                           strcat(string1,string2);
                           send(clientSocket,string1,strlen(string1), 0);
                           
                          }else if(num==3){
                        int result= strcmp(string1, string2);
                         if (result==0){
                          strncpy(msg,"strings are equal",200);
                         send(clientSocket,msg,strlen(msg), 0);
                         }else{
                              strncpy(msg,"strings are not equal",200);
                         send(clientSocket,msg,strlen(msg), 0);

                        }
                         
                         }else if(num==2){
                               int result= strcspn(string1,string2);
                                   printf("%d",result);
                                  strncpy(msg,"string found at: ",200);
                                      char res[20];
                                     sprintf(res, "%d",result);
                                    strcat(msg,res);
                                 
                         send(clientSocket,msg,strlen(msg), 0);
                               
                          }else if(num==4){
                             strncpy(msg,"hello please enter a string",200);
                         send(clientSocket,msg,strlen(msg), 0);
                             recv(clientSocket, &string2, sizeof(string2), 0);
                             int len=0;
                             int index=0;
                         char temp[2]=".";
                        strcat(string2,temp);
                             while(string2[index]!='.'){
                                len++;
                                 index++;
                                }
                              printf("%d", len);
                                int flag=0;
                              for(int i=0;i < len ;i++){
                               if(string2[i] != string2[len-i-1]){
   flag = 1;
   break;
            }
        }
   
   if (flag==1) {
     strncpy(msg,"string is not palindrome",200);
send(clientSocket,msg,strlen(msg), 0);
   }    
   else {
      strncpy(msg,"is a palindrome",200);
send(clientSocket,msg,strlen(msg), 0);
   }

                       }else if(num==5){
                        int num1= getnum(string1);
                            int num2= getnum(string2);  
                        int result= num1+ num2;
                         if(result==1)
{
strncpy(msg,"Result is: One",200);
send(clientSocket,msg,strlen(msg), 0);
}
else if(result==2)
{
strncpy(msg,"Result is: Two",200);
send(clientSocket,msg,strlen(msg), 0);
}
else if(result==3)
{
strncpy(msg,"Result is: Three",200);
send(clientSocket,msg,strlen(msg), 0);
}
else if(result==4)
{
strncpy(msg,"Result is: Four",200);
send(clientSocket,msg,strlen(msg), 0);
}
else if(result==5)
{
strncpy(msg,"Result is: Five",200);
send(clientSocket,msg,strlen(msg), 0);
}
else if(result==6)
{
strncpy(msg,"Result is: Six",200);
send(clientSocket,msg,strlen(msg), 0);
}
else if(result==7)
{
strncpy(msg,"Result is: Seven",200);
send(clientSocket,msg,strlen(msg), 0);
}
else if(result==8)
{
strncpy(msg,"Result is: Eight",200);
send(clientSocket,msg,strlen(msg), 0);
}
else if(result==9)
{
strncpy(msg,"Result is: Nine",200);
send(clientSocket,msg,strlen(msg), 0);
}
else if(result==10)
{
strncpy(msg,"Result is: Ten",200);
send(clientSocket,msg,strlen(msg), 0);
}
                       
                       
                     }


}
}


close(clientSocket);
return 0;
}