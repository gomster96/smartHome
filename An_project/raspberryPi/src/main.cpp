#include <iostream>
#include "../include/server.h"

int main()
{
    wiringPiSetup();
    Server a;
    a.init();
    a.work();
    return 0;
}