#include<iostream>
#include<wiringPi.h>

using namespace std;
int main()
{
    wiringPiSetup();
    int pinRIP = 1;
    int pinLED = 25;
    pinMode(pinRIP, INPUT);
    pinMode(pinLED, OUTPUT);
    digitalWrite(pinLED, LOW);
    while(1)
    {
        cout<<digitalRead(pinRIP)<<endl;
        if(digitalRead(pinRIP)==1){
            printf("detect\n");
            digitalWrite(pinLED, HIGH);
            delay(500);
        }
        else
        {
            printf("no detect\n");
            digitalWrite(pinLED, LOW);
            delay(500);
        }
        
    }
}