//ben code for example. 
#include <stdio.h>
#include <sys/socket.h>//needed for socket
#include <netinet/in.h>//for bind
#include <string.h>//for puts as stirngs are used in code


int main(int argc, char *argv[])
{

	//create file descriptor
	int listenfd, connfd;

	//Socket Structures
	struct sockaddr_in servaddr, cliaddr;//local variable whis is cliaddr and is full of shite.
	//another structure for input address added

	socklen_t clilen = sizeof(cliaddr);

	//clear struct to all zero's no trash
	memset(&servaddr, 0, sizeof(servaddr));

	//address this is a internet socket
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);//just use local address struct within a struct withint a struct
	servaddr.sin_port = htons(9001);//over 9000! port (super sayan)

	char buf[1000];//buffer for recieve

	//manually setting up socket (create socket ())
	listenfd = socket(PF_INET, SOCK_STREAM, 0);

	//now bind socket to, pass listen details, pass address, find size of file and set
	bind(listenfd, (struct sockaddr *)&servaddr, sizeof(struct sockaddr_in));
	//have to use cast in order for it to compile for bind to work. Using cast to do it

	listen(listenfd, 5);//now listen and have max of 5 for buffer

	while(1)
	{
		printf("Waiting for client to connect .......\n");
		accept(listenfd, (struct sockaddr*)&cliaddr, &clilen);

		//client has connected
		printf("Connection made......\n");

		recv(connfd, buf, 1000, 0);
		//low level ascii char is read 
		puts(buf);//put on local screen

		//send data back echo back to the client
		send(connfd, buf, strlen(buf), 0);

		//
	}

	//close(lisetnfd);//close socket.

	return 0;
}
