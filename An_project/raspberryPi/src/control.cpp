#include "../include/control.h"
#include <thread>

void Control::start()
{
    //LED temp = LED(25);
    this->_LEDItems[0] = LED(27);
    this->_LEDItems[1] = LED(28);
    this->_LEDItems[2] = LED(29);
    this->_ripSensor = RIP(0,26);
    this->_humiditySensor = Hum(1);
    //this->_MotorItems[0] = Motor(22,23,24,25);
    this->_DCMotorItems[0] = DCMotor(21,22);
}

int Control::decode(char* buff_rcv)
{
    char* temp = strtok(buff_rcv, " ");
    char* order = new char(strlen(temp));
    strcpy(order, temp);
    printf("1: %s\n", order);
    printf("1: %s\n", temp);
    temp = strtok(NULL, " ");
    
    if(strcmp(temp, "LED")==0)
    {
        temp = strtok(NULL, " ");
        this->decodeLED(order, atoi(temp));
    }
    else if(strcmp(temp, "Motor")==0)
    {
        temp = strtok(NULL, " ");
        this->decodeMotor(order, atoi(temp));
    }
    else if(strcmp(temp, "DCMotor")==0)
    {
        temp = strtok(NULL, " ");
        this->decodeDCMotor(order, atoi(temp));
    }
    else if(strcmp(temp, "Hum")==0)
    {
        this->decodeHum(order);
        return 2; // the signal about send data to client.
    }
    else
    {
        return 0;
    }
    

    delete order;
    return 1;
}

void Control::decodeMotor(char* order, int num)
{
    if(strcmp(order, "on")==0)
    {
        this->_DCMotorItems[num-1].motorTurnOn();
        //std::thread t(&Motor::motorTurnOn, &this->_MotorItems[num-1]);
        
    }
    else if(strcmp(order, "off")==0)
    {
        this->_DCMotorItems[num-1].motorTurnOff();
    }
}

void Control::decodeMotor(char* order, int num)
{
    if(strcmp(order, "on")==0)
    {
        this->_MotorItems[num-1].motorTurnOn();
        //std::thread t(&Motor::motorTurnOn, &this->_MotorItems[num-1]);
        
    }
    else if(strcmp(order, "off")==0)
    {
        this->_MotorItems[num-1].motorTurnOff();
    }
}
void Control::decodeLED(char* order, int num)
{
    if(strcmp(order, "on")==0)
    {
        this->_LEDItems[num-1].LEDturnOn();
    }
    else if(strcmp(order, "off")==0)
    {
        this->_LEDItems[num-1].LEDturnOff();
    }
}

void Control::decodeHum(char* order)
{
    if(strcmp(order, "read")==0)
    {
        if(this->_humiditySensor.read_hum()==1)
        {
            this->HumCheck = 1;
        }
        else
        {
            this->HumCheck = 0;
        }
        
    }
}

