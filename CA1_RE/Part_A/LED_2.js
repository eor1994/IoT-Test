/*
*b00072646
*/

var b = require('bonescript');

   var led = "P9_12";
   var i;
   b.pinMode(led, b.OUTPUT);

          for(i = 0; i < 5; i++){//loop 5 times -test
          ledOn();//turn led on with function
          sleep(1000);//sleep 1 second
          ledOff();//turn led off
          sleep(1000);//sleep 1 second
          }

 function sleep(ms){//funciton sleep in mili-seconds
          // calling funtion date, that gets the system time.
          //getTime gets the number of miliseconds since 1970 00:00:00
          // returns the number of miliseconds and the specific date.
          //adds ms from set in sleep.
          ms = ms + new Date().getTime();
          while (new Date() < ms){
          }
   }

   function ledOn(){//writes to the gpio to turn on
          b.digitalWrite(led, 1);
          }

   function ledOff(){//writes to the gpio in to turn off
          b.digitalWrite(led, 0);
          }

   process.exit(0);//finish

