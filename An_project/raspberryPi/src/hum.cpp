#include "../include/Hum.h"

#define MAXTIMINGS 83

int Hum::read_hum()
{
    
    uint8_t laststate = HIGH ;
    uint8_t counter = 0 ;
    uint8_t j = 0, i ;
    uint8_t flag = HIGH ;
    uint8_t state = 0 ;
    float f ;
    this->hum_data[0] = this->hum_data[1] = this->hum_data[2] = this->hum_data[3] = this->hum_data[4] = 0;

    pinMode(this->_pin, OUTPUT);
    digitalWrite(this->_pin, LOW);
    // delay(18);
    delay(18);
    digitalWrite(this->_pin, HIGH);
    delayMicroseconds(30);
    //delay(30);
    pinMode(this->_pin, INPUT);
        
    for (i = 0; i < MAXTIMINGS; i++) {
        counter = 0 ;

        while ( digitalRead(this->_pin) == laststate) { 
        
            counter++ ;
            delayMicroseconds(1);
            //delay(1);

            if (counter == 200) break ;
        }

        laststate = digitalRead(this->_pin) ;

        if (counter == 200) break ; // if while breaked by timer, break for

        if ((i >= 4) && (i % 2 == 0)) {

            this->hum_data[j / 8] <<= 1 ;

            if (counter > 20) 
                this->hum_data[j / 8] |= 1 ;
            j++ ;
        }

  }

  if ((j >= 40) && (this->hum_data[4] == ((this->hum_data[0] + this->hum_data[1] + this->hum_data[2] + this->hum_data[3]) & 0xff))) {

    printf("humidity = %d.%d %% Temperature = %d.%d *C \n", this->hum_data[0] , this->hum_data[1] , this->hum_data[2] , this->hum_data[3]) ;
    return 1;
  }

  else {
      // error일 경우 한번 더 해주기 
      printf("Data get failed\n") ;
      return 0;
  }

}