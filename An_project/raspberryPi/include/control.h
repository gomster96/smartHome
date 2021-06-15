#ifndef CONTROL_H
#define CONTROL_H

#include<iostream>
#include "LED.h"
#include "Motor.h"
#include "Hum.h"
#include "RIP.h"
#include <new>
#include <string.h>
#include "DCMotor.h"

using namespace std;

class Control
{
    public:
        void start();
        int decode(char* buff_rcv);
        void decodeLED(char* order, int num);
        void decodeMotor(char* order, int num);
        void decodeHum(char* order);
        void decodeDCMotor(char* order, int num);
        int get_HumCheck(){return HumCheck; }
        Hum get_humiditySensor(){return _humiditySensor;}
        RIP get_ripSensor(return _ripSensor;)
    private:
        LED _LEDItems[3];
        Motor _MotorItems[2];
        Hum _humiditySensor;
        RIP _ripSensor;
        DCMotor _DCMotorItems[2];
        int HumCheck = 0;

};

#endif