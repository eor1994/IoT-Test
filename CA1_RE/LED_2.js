//load bonescript module

var b = require('bonescript');//use library 

var led = "GPIO_30";//set output of gpio pin

var i; //init i

console.log("Blinky"); //show on console

for(i=1; i<100; i++)//loop 99 times
{
	LED_on();//change to high
	sleep();//delay program by 1 second 
	
	LED_off();//chnage to low
	sleep();//delay program by 1 second
}

function LED_on()
{
	b.digitalWrite(led,1);//send on to led (HIGH)
}

funciton LED_off()
{
	b.digitalWrite(led,0);//send off to led(LOW)
}

function sleep()//function to toggle led and check 
{
	setTimeout(function()
	{
	}, 1000);
}

process.exit(0);//finish
