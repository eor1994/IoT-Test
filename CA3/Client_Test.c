//client test to server
//server to connect address 52.50.78.133 and port is 3000

#include <stdlib.h>
#include <stdio.h>//printf
#include <sys/types.h>
#include <sys/socket.h>//needed for socket
#include <netinet/in.h>//for bind function
#include <string.h>
#include <arpa/inet.h>//??


#define MAXLINE 4096 //max text line length
#define SERV_PORT 5050 //port number

int main(int argc, char *argv[])
{
        //decalre file descriptor name
        int sockfd;

        //Socket Structures
        struct sockaddr_in servaddr;
        //another structure for input address added

	//send text and save text when it comes back
	char sendline[MAXLINE], recvline[MAXLINE];//using echo

	//create socket for client
	if ((sockfd = socket (AF_INET, SOCK_STREAM, 0)) <0)//check if socket is created
	{
		perror("Problem in creating the socket");
		return 1;
	}

//creation of socket for client in detail and type

        //clear struct to all zero's no trash
        memset(&servaddr, 0, sizeof(servaddr));
        //address, this is a internet tyoe, ip address and port number
        servaddr.sin_family = AF_INET;//ip type either ipv
        servaddr.sin_addr.s_addr = inet_addr(argv[1]);//a struct withint a struct for address
        servaddr.sin_port = htons(SERV_PORT);//over 9000! port (super sayan), big endian

	//try to connection of clinet to server
	if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) <0)
	{
		perror("Problem in connecting to the server");
		return 1;//system error for connection
	}
	


	while (fgets(sendline, MAXLINE, stdin) != NULL)
	{
		//send string
		send(sockfd, sendline, sizeof(sendline), 0);

		//read the response 
		if(recv(sockfd, recvline, sizeof(recvline), 0) <0)
		{
			perror("The server terminated prematurely");
			return 1;
		}

		printf("%s", "String recieved:");
		fputs(recvline, stdout);
	}
        exit(0);
}

