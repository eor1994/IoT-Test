/*
Student Name: Eoin O Reilly
Student ID: B00072646
Q: 1
*/

#include <stdio.h> // for fscanf and fprintf
#include <unistd.h> //used for system API
#include <sys/wait.h>
#include <sys/types.h>

#define LED_PATH "/sys/class/gpio/gpio60/value" //led output direction
#define BUTTON "/sys/class/gpio/gpio32/value" //button is input direction

int ledOn(int j);//function, turn on
int ledOff(int x);//function, turn off

int main(void)//creates a pointer of argv passes a char
{

	int pid;
//assigned button condition
	int oldButtonVal = 0;
	int buttonVal=0;
//open file named Button
	FILE *Button;

//fork
	pid = fork();//pid is now forked into two programs(parent && child)

	if (pid == 0) //if equal to zero, its child proocess and it will toggle LED
	{

		//Button
        		Button = fopen(BUTTON, "r+");//opened file path reads gpio60 and updates 
        		fscanf(Button, "%i", &buttonVal);//scans a int number to buttonVal
        		fclose(Button);//close file

			
        		if(buttonVal != oldButtonVal)//if not equal, change
        		{
			
				if(oldButtonVal == 0)
				{
					printf("Button: %i\n",oldButtonVal);
					Button = fopen(LED_PATH, "w");
					fprintf(Button,"1");
					fclose(Button);
				}
			
				else if(oldButtonVal == 1)
				{
					printf("Button: %i\n",oldButtonVal);
					Button = fopen(LED_PATH, "w");  
                                        fprintf(Button,"0");
                                        fclose(Button);
				}
			
			usleep(10000);
			}
	}

	else if (pid > 0) //if greater its the parent process
       	{
               	wait NULL;	 //wait till child finishe
	}

	return 0;
}
