//just using threading

#include <pthread.h>
#include <stdio.h> //for printd and scanf
#include <stdlib.h>
#include <unistd.h> //used for system API
#include <sys/wait.h> //wait()
#include <sys/types.h>

#define NUM_THREADS 2

#define LED_PATH "/sys/class/gpio/gpio60/value" //led output direction
#define BUTTON "/sys/class/gpio/gpio30/value" //button is input direction
#define LED_DIR "/sys/class/gpio/gpio60/direction"//set direction as output
#define BUTTON_IN "/sys/class/gpio/gpio30/direction"//set button direction as input

void *thread_LED();//thread using function to toggle led
void *thread_Button();//thread used to check button condition

//pthread_mutex_lock(&mutex_But);

int main(void)
{

	pthread_t thread_ID;//id number of thread
	void *exit_status;//exit of NULL

	//initialise mutex and conditon variables
	pthread_mutex_init(&,NULL);
	pthread_cond_inti (&,NULL);

	//create thread here
	pthread_create(&thread_ID, NULL, thread_function, 0);
	//wait for thread to terminate
	pthread_join(thread_ID, &exit_status);

	return 0;
}

//thread one but points to function which is void.
void *thread_function(void)
{
//set direction
        char str_In[] = "in";//set value to in
        char str_Out[] = "out";//set value to out

//assigned button condition
        int oldButtonVal = 0;//old button value and compare to new value
        int buttonVal = 0;//current value of button

//Create and open file named Button
        FILE *Button;

//set direction of LED by writing to file
        Button = fopen(LED_DIR, "w");
        fwrite(str_Out, 1, sizeof(str_Out), Button);
        fclose(Button);

//set direction of button
        Button = fopen(BUTTON_IN,"w");//write to file and filepath
        fwrite(str_In, 1, sizeof(str_In), Button);//write string to button path
        fclose(Button);//close file


	for(int i=0; i<1000; i++)//10 seconds
        {
        	//Button read
                        Button = fopen(BUTTON, "r+");//opened file path reads gpio60 and$
                        fscanf(Button, "%i", &buttonVal);//scans a int number to buttonV$
                        fclose(Button);//close

                        printf("Button = %d\n",buttonVal);
                        //wait for rising edge

                        if(buttonVal != oldButtonVal)//if current button is not equal then check
                        {

                                if(oldButtonVal== 0 && buttonVal ==1)//if change happens from low to high then do
                                {
                                        Button = fopen(LED_PATH,"w");//write a 1 to file (LED = HIGH)
                                        fprintf(Button, "1");
                                        fclose(Button);//close file
                                }
                                else//else if high to low then (LED = LOW)
                                {
                                        Button = fopen(LED_PATH,"w");
                                        fprintf(Button, "0");
                                        fclose(Button);//close file
                                }

                                oldButtonVal = buttonVal;//update old button to new and loop again
                        }

         	       usleep(10000);//1 second
	}
	return NULL;//return back to thread
}
