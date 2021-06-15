#include<stdio.h>

int pin = 29;

int main()
{
	wiringPiSetup();
	pinMode(pin, OUTPUT);
	for(;;)
	{
		digitalWrite(pin,HIGH); 
		delay(500);
		digitalWrite(pin,LOW); 
		delay(500);

	}
	return 0;

}

