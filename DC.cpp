#include<iostream>

#include<wiringPi.h>

using namespace std;

#define MotorPin1 28
#define MotorPin2 29

int main()
{
    wiringPiSetup();

    pinMode(MotorPin1, OUTPUT);
    pinMode(MotorPin2, OUTPUT);

    int a = 0;
    while(a != 4){
        digitalWrite(MotorPin1, HIGH);
        digitalWrite(MotorPin2, LOW);
        delay(500);
        digitalWrite(MotorPin1, LOW);
        digitalWrite(MotorPin2, HIGH);
        delay(500);
        a++;
    }

    digitalWrite(MotorPin1, LOW);
    digitalWrite(MotorPin2, LOW);  
    return 0;
}