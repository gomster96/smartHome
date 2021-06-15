#ifndef RIP_H
#define RIP_H
#include<iostream>
#include<wiringPi.h>

using namespace std;

class RIP
{
    public:
        RIP() = default;
        RIP(int inputPin, int outputPin){
            this->_inputPin = inputPin;
            this->_outputPin = outputPin;
            pinMode(_inputPin, INPUT);
            pinMode(_outputPin, OUTPUT);
            digitalWrite(_outputPin, LOW);
        }
        int get_check() const {return _check; }
        void ripRun()
        {
            if(digitalRead(this->_inputPin)==1){
                printf("detect\n");
                digitalWrite(this->_outputPin, HIGH);
                this->_check = 1;
                // delay(500);
                // consider about delay
        }
            else
        {
            printf("no detect\n");
                digitalWrite(this->_outputPin, LOW);
                this->_check = 0;
                //delay(500);
                //consider about delay
        }
        }
    private:
        int _inputPin;
        int _outputPin;
        int _check = 0;
};

#endif