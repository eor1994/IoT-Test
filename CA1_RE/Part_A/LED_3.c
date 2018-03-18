#include <stdio.h>//standard c functions and declarations
#include <unistd.h>//used for usleep
#include <string.h>//used for MACRO = NULL

//defined Paths for LED pin GPIO_31(13)
#define LED_PATH "/sys/class/gpio/gpio31/value" //led output direction
#define LED_DIR "/sys/class/gpio/gpio31/direction"//set direction as output

int main(void)
{

//set up declarations
	char str_Out[] = "out";//set direction as out, string

//open file named Button
        FILE *Button;

//set direction of LED
        Button = fopen(LED_DIR, "w");//write to file direction
        fwrite(str_Out, 1, sizeof(str_Out), Button);//set as output
        fclose(Button);

	while(1)
	{
		//turn on LED
		Button = fopen(LED_PATH,"w");//open and write ti file path
                fprintf(Button, "1");//write a 1 to turn on LED
                fclose(Button);//close file

		sleep(1);//sleep for 1 second

		//turn off LED
		Button = fopen(LED_PATH,"w");//open and write to path
                fprintf(Button, "0");//turn LED off
                fclose(Button);//close file
		sleep(1);
	}

	return 0;
}
