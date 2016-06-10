# SuperSmallTimer
A very small timer for Arduino. Define a function to be executed at an interval in milliseconds.
Based on the timer created by: Marcello Romani (http://playground.arduino.cc/Code/SimpleTimer)

## Mode of use

	-Import #include <SuperSmallTimer.h>
	-Define a timer object `SSTimer timer;`
	-Setup function to be repeated `timer.setInterval(secondsToUpdateDB * 1000, myFunct);`
	-Run `timer.run()` once per loop


## Example
	
```c

#include <SuperSmallTimer.h>

SSTimer timer;

long secondsToUpdateDB = 600;

void blink(){
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13, LOW);
}

void setup() {
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
  // define the interval function
  timer.setInterval(secondsToUpdateDB * 1000, blink);

}

void loop() {
  timer.run(); 
}

```
