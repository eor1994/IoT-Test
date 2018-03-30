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
#define BUTTON "/sys/class/gpio/gpio30/value" //button is input direction
#define LED_DIR "/sys/class/gpio/gpio60/direction"//set direction as output
#define BUTTON_IN "/sys/class/gpio/gpio30/direction"//set button direction as input

int main(void)//creates a pointer of argv passes a char
{
//set direction
	char str_In[] = "in";
        char str_Out[] = "out"; 

	int pid;
//assigned button condition
	int oldButtonVal = 0;
	int buttonVal = 0;
//open file named Button
	FILE *Button;

//set direction of LED
	Button = fopen(LED_DIR, "w");
	fwrite(str_Out, 1, sizeof(str_Out), Button);
	fclose(Button);

//set direction of button
	Button = fopen(BUTTON_IN,"w");
	fwrite(str_In, 1, sizeof(str_In), Button);
	fclose(Button);

//fork
//child process
	pid = fork();//pid is now forked into two programs (parent && child)

	if (pid == 0) //if equal to zero, its child proocess and it will toggle LED
	{
		for(int i=0; i<1000; i++)//10 seconds loop - multiplies microsecond
		{
			//Button read
        		Button = fopen(BUTTON, "r+");//opened file path reads gpio60 and updates 
        		fscanf(Button, "%i", &buttonVal);//scans a int number to buttonVal
       			fclose(Button);//close

			printf("Button = %d\n",buttonVal);//print on terminal the button pressed or not 

			if(buttonVal != oldButtonVal)//if present value isnt equal to new do this
			{

				if(oldButtonVal== 0 && buttonVal ==1)//if old value is 0 and new value is 1 (Low to HIGH)
				{
					Button = fopen(LED_PATH,"w"); //open file to led path
                			fprintf(Button, "1");//turn on led
                			fclose(Button);//close file
				}
				else//else high to low then turn off led
				{
					Button = fopen(LED_PATH,"w");
                			fprintf(Button, "0");
                			fclose(Button);
				}

				oldButtonVal = buttonVal;//update old value to new value
			}

		usleep(10000);//1 second
		}
	}//finish child

//parent process
	else if (pid > 0) //if greater its the parent process
       	{
               	wait NULL;	 //wait till child finishe
	}

	return 0;
}//finished 
