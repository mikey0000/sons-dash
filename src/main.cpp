#include "wiring_digital.c"
#include "convert_binary.h"
#include "sound_lib.h"
#include "lights_lib.h"

void setup();
void loop();

void setup(){
  byte count;

  for (count=2;count<6;count++) {
    pinMode(count, INPUT);
  }

  serial_SD_setup();
  sound_setup();
  lights_setup();
  Serial.println("main setup done");  
}

uint8_t debounce = 0;
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 500; 

bool debounced(uint8_t port) {
  if(port == debounce && ((millis() - lastDebounceTime) < debounceDelay)) {
    return true;
  } else {
    debounce = port;
    lastDebounceTime = millis();
    return false;
  }
}

void loop(){
  if(Serial.available()){
    int incomingByte = Serial.read();
    //Serial.println(incomingByte, DEC);    
    if(incomingByte == 'A'){ //send the letter p over the serial monitor to start playback
      Serial.println("debug");
      digitalWrite(GREEN, HIGH);
      digitalWrite(RED, HIGH);
      digitalWrite(YELLOW, HIGH);
      digitalWrite(BLUE, HIGH);
      digitalWrite(WHITE, HIGH);
    }
    if(incomingByte == 'B') {
      digitalWrite(GREEN, LOW);
      digitalWrite(RED, LOW);
      digitalWrite(YELLOW, LOW);
      digitalWrite(BLUE, LOW);
      digitalWrite(WHITE, LOW);
    }
    if(incomingByte == 'C') {
      setVolume(0);
    }
    if(incomingByte == 'D') {
      setVolume(5);
    }
    if(incomingByte == 'r') {
      play_red();
    }
    if(incomingByte == 'j') {
      play_joystick();
    }
  }
  
  //read in the 4 ports and get back the count
  uint8_t port_num = convert_binary(2,3,4,5);
  if(port_num != 0 && debounced(port_num)) {
    //Serial.printf("Number %d\n\n", port_num);
    play_car_sound(port_num);
  }
  light_loop_tasks();
}
