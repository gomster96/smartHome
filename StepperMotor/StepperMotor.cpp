
#include <wiringPi.h>
#include <iostream>
using namespace std;
void Sleep()
{
    for (int i = 0; i < 1000; i++)
    {
    }
}
int main(void)
{
    wiringPiSetup();
    const int pin1 = 5;
    const int pin2 = 6;
    const int pin3 = 10;
    const int pin4 = 11;
    pinMode (pin1, OUTPUT);
    digitalWrite (pin1, 0);
    pinMode (pin2, OUTPUT);
    digitalWrite (pin2, 0);
    pinMode (pin3, OUTPUT);
    digitalWrite (pin3, 0);
    pinMode (pin4, OUTPUT);
    digitalWrite (pin4, 0);
    int seq[8][4] = { {1,0,0,0}, {1,1,0,0}, {0,1,0,0}, {0,1,1,0}, {0,0,1,0}, {0,0,1,1}, {0,0,0,1}, {1,0,0,1} };
    for (int i = 0; i <= 512; i++)
    {
        for (int step = 0; step < 8; step++)
        {
            for (int pin = 0; pin < 4; pin++)
            {
                if(pin == 0)
                    {
                    digitalWrite(pin1, seq[step][pin]);
                    delay(1);
                    cout << "slept pin1 \n";
                    }
                if(pin == 1)
                    {
                    digitalWrite(pin2, seq[step][pin]);
                    delay(1);
                    cout << "slept pin2 \n";
                    }
                if(pin == 2)
                    {
                    digitalWrite(pin3, seq[step][pin]);
                    delay(1);
                    cout << "slept pin3 \n";
                    }
                if(pin == 3)
                    {
                    digitalWrite(pin4, seq[step][pin]);
                    delay(1);
                    cout << "slept pin4 \n";
                    }

            }

        }
    }


    return 0;
}
 