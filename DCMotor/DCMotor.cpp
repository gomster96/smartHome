#include<iostream>
#include<wiringPi.h>

using namespace std;

int main()
{
    
    int DCPin21 = 29;
    
    wiringPiSetup();
    pinMode(DCPin21, OUTPUT);
    int i =0;
    while(i!=10)
    {
        digitalWrite(DCPin21,HIGH);
        cout<< i<<"st cycle" <<endl;
        delay(2000);
        i++;
    }
}