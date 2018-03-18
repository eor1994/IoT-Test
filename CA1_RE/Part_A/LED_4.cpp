//B00072646

#include <unistd.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//set LED Pin to GPIO_50(14)
#define LED_DIR "/sys/class/gpio/gpio50/direction"//set direction of gpio
#define LED_VAL "/sys/class/gpio/gpio50/value" //path to value for led to be turn on/off

int main()
{
    ofstream fs;//use class fstream from std to initlaise the fs function

    fs.open(LED_DIR);//open file to pathway of GPIO direction
    fs << "out";//set direction of GPIO pin to output
    fs.close();//close file

	while(1)
    	{
    		fs.open(LED_VAL);//open file to pathway of led value
   		fs << "1";//write a 1 to file
    		fs.close();//close file
    		sleep(1);//sleep one second using 

    		fs.open(LED_VAL);//using the define to pass a fstream of 0 to the direction
    		fs << "0";//led is off
    		fs.close();//close file stream
   		sleep(1);
   	}

	//exit and end program
	return 0;
}

