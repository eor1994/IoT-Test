var b = require ('bonescript');
var led = "GPIO_60";//set output of gpio pin to pin 60 (12)
var i;

for(i=1; i<100; i++)//loop 99 times
{
	LED_on();//change to high
	sleep(1000);//delay program by 1 second 
	
	LED_off();//chnage to low
	sleep(1000);//delay program by 1 second
}

//Functions

function LED_on()
{
	b.digitalWrite(led,1);//send on to led (HIGH)
}

function LED_off()
{
	b.digitalWrite(led,0);//send off to led(LOW)
}

//function sleep(ms)//function to toggle led and check 
//{
//	setTimeout(function()
//	{
//	}, ms);
//}

 
function sleep(ms){
          // calling funtion date, that gets the system time.
          ms = ms + new Date().getTime();
          while (new Date() < ms){
          }
}

function LED_Dir()
{
	b.pinMode (led, b.OUTPUT);
}


//finish
process.exit(0);//finish
