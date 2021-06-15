#include<stdio.h>

int pin = 0;

int main()
{
	wiringPiSetup();
	pinMode(pin, OUTPUT);
	for(;;)
	{
		digitalWrite(0,HIGH); 
		delay(500);
		digitalWrite(0,LOW); 
		delay(500);

	}
	return 0;

}

