/*
Student Number: B00072646
CA: ca2 - part 2
*/
#include <sys/types.h>
#include <unistd.h>//used for NULL
#include <stdio.h>//Standard library
#include <stdlib.h> //exit()
#include <sys/wait.h> //wait()

int main(int ac, char *av[])
{
	int pid;//declare pid
	pid = fork();//fork process

//error check
	if(pid < 0)
	{
	 perror("fork() error");//error
	 exit(-1);//system exit
	}

	if(pid != 0)//parent
	{
		//shows the id of parent and child
		printf("Parent %d, my child %d \n",getpid(),getppid());
		wait(NULL); //wait for child
	}
	
	else //child
	{	//shows the parent and child id for test.
		printf("child: %d, my parent is %d \n",getpid(), getppid());
		//execl("/bin/ls","/bin/ls","-r", "-t", "-l", (char*) 0);//execute and wait till finisihed
		execvp("./Button_1",NULL);//executes the file Button_1 in same directory as Button_2
	}

	return 0;//finish
}
