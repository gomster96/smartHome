#ifndef MOTOR_H
#define MOTOR_H

#include <wiringPi.h>
#include <iostream>
using namespace std;

class Motor
{
    public:
        Motor() = default;
        Motor(int pin1, int pin2, int pin3, int pin4)
        {     
            _pin[0] = pin1;
            pinMode(pin1 , OUTPUT);
            _pin[1] = pin2;
            pinMode(pin2 , OUTPUT);
            _pin[2] = pin3;
            pinMode(pin3 , OUTPUT);
            _pin[3] = pin4;
            pinMode(pin4 , OUTPUT);
            _check = 1;
        }
        void motorTurnRight()
        {
            for(int i=0; i<=128; i++)
            {
                for(int step =0; step<8; step++)
                {
                    for(int pin =0; pin<4; pin++)
                    {
                        digitalWrite(_pin[pin], seq[step][pin]);
                    }
                    delay(10);
                }
            }
        }
        void motorTurnLeft()
        {
            for(int i=0; i<=128; i++)
            {
                for(int step = 7; step>=0; step--)
                {
                    for(int pin =3; pin>=0; pin--)
                    {
                        digitalWrite(_pin[pin], seq[step][pin]);
                    }
                    delay(10);
                }
            }
        }
        void motorTurnOff()
        {
            _interrupt = 1;
        }

        int get_check() const { return _check; }
    private:
        int _pin[4];
        int _check = 0;
        int _interrupt = 0;
        int seq[8][4] = { {1,0,0,0}, {1,1,0,0}, {0,1,0,0}, {0,1,1,0}, {0,0,1,0}, {0,0,1,1}, {0,0,0,1}, {1,0,0,1} };
};

#endif