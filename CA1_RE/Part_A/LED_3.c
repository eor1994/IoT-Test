#include <stdio.h>
#include <stdlib.h>
#include <string.h>//used for MACRO = NULL
#include <pthread.h>>//used for threading

#define LED_PATH "/sys/class/gpio/gpio60/value" //led output direction
#define BUTTON "/sys/class/gpio/gpio30/value" //button is input direction
#define LED_DIR "/sys/class/gpio/gpio60/direction"//set direction as output
#define BUTTON_IN "/sys/class/gpio/gpio30/direction"//set button direction as input

//#define PATH

void sleep();//funciton to delay prorgam by one second

int main(void)
{
//set up threads
	pthread_t thread1, thread2;
	const char *message1 = "Thread 1";
	const char *message2 = "Thread 2";

//set direction of pins
        char str_In[] = "in";
        char str_Out[] = "out";

//assigned button condition
        int oldButtonVal = 0;
        int buttonVal = 0;

	//create threads
	pthread_create( ,NULL, thred_Button, &value);

	//wait for the thread to terminate
	pthread_join(thread_ID, &func);

	//only main thread runs now
	return 0;
}

int * (void *ptr)
{

}
