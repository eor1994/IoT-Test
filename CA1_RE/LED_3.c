#include <stdio.h>
#include <stdlib.h>
#include <string.h>//used for MACRO = NULL

#define LED "/sys/class/gpio/gpio5/value"
//#define PATH

void sleep();//funciton to delay prorgam by one second

int main(void)
{	
	int i; 

	FILE *fp;//point to some file

	fp = fopen(LED, "w");//make file writable
	//if error and cant open
	if(fp == NULL)
	{
		exit(-1);//system error
	}

//set up led
	for(i=0; i<100; i++)
	{
	fp = fopen(PATH,"w");//open and write to led
	fprintf(fp, "%s", "1");//set to HIGH
	fclose(fp);//close High

	sleep();//wait 1 second

	fp = fopen(PATH,"w");
	fprintf(fp, "%s", "0");//set to LOW
	fclose(fp);//close Low

	sleep();//wait 1 second

	}//loop

	return 0;
}

void sleep()
{

}
