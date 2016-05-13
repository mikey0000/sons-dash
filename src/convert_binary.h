#include <math.h>


uint8_t port_binary(uint8_t pin) {
  uint8_t port = digitalPinToPort(pin);
  uint8_t bit = digitalPinToBitMask(pin);
  if (*portInputRegister(port) & bit) return 1;
  return 0;
}

//0001 
uint8_t convert_binary(uint8_t first,uint8_t second,uint8_t third,uint8_t forth) {
    uint8_t count = 0;

    //Serial.printf("Ports %d %d %d %d\n", port_binary(first), port_binary(second), port_binary(third), port_binary(forth));

    uint8_t intArray[4] = {port_binary(forth), port_binary(third), port_binary(second), port_binary(first)};

    for(int i = 0; i < 4; i++) {
        if(intArray[i] == 1) {
          //because we are type casting from a double to an int
          //we need to turn 3.9999999 into a 4
          //why true pow works this way I don't know
            count += ceil(pow(2, i));
        }
    }
    return count;
}


