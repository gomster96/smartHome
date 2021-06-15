#ifndef DCMOTOR_H
#define DCMOTOR_H

#include <wiringPi.h>
#include <iostream>
using namespace std;

class DCMotor
{
    public:
        DCMotor() = default;
        DCMotor(int pin1, int pin2)
        {     
            _pin1 = pin1;
            pinMode(pin1 , OUTPUT);
            _pin2 = pin2;
            pinMode(pin2 , OUTPUT);
        }
        void motorTurnOn()
        {
            // Turn motor to right direction
            digitalWrite(this->_pin1, HIGH);
            digitalWrite(this->_pin2, LOW);
            delay(500);
            setState();
            
        }
        void motorTurnOff()
        {
            // Turn motor to left direction
            digitalWrite(this->_pin1, LOW);
            digitalWrite(this->_pin2, HIGH);
            delay(500);
            setState();
        }
        void setState()
        {
            digitalWrite(this->_pin1, HIGH);
            digitalWrite(this->_pin2, LOW);
        }

        int get_check() const { return _check; }
    private:
        int _pin1;
        int _pin2;
        
};

#endif