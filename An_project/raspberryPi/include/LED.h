#ifndef LED_H
#define LED_H
#include<iostream>
#include<wiringPi.h>

using namespace std;

class LED
{
    public:
        LED() = default;
        LED(int pin){ 
            _pin = pin; 
            _check = 0;
            pinMode(_pin , OUTPUT);
        }
        void LEDturnOn()
        {
            digitalWrite(_pin, HIGH);
            _check = 1;
        }
        void LEDturnOff()
        {
            digitalWrite(_pin, LOW);
            _check = 0;
        }

        int get_pin() const { return _pin; }
        void set_pin(int changePin) { _pin = changePin;}
        int get_check() const { return _check; }
    private:
        int _pin;
        int _check;
};
#endif