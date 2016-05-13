#include "lights_lib.h"

void setColor(uint8_t color);
void flash_joystick();

unsigned long previousMillis = 0;        // will store last time LED was updated

uint8_t LIGHT = 0;
int STATE = LOW;


void lightsWrite(uint8_t pin, uint8_t val)
{
    uint8_t bit = digitalPinToBitMask(pin);
    uint8_t port = digitalPinToPort(pin);
    volatile uint8_t *out;

    out = portOutputRegister(port);

    uint8_t oldSREG = SREG;
    cli();

    if (val == LOW) {
        *out &= ~bit;
    } else {
        *out |= bit;
    }

    SREG = oldSREG;
}

// constants won't change :
const long interval1000 = 1000;
const long interval400 = 400;
const long interval500 = 500;
const long interval200 = 200;


void flash();

void lights_setup() {
    pinMode(GREEN, OUTPUT);
    pinMode(RED, OUTPUT);
    pinMode(YELLOW, OUTPUT);
    pinMode(BLUE, OUTPUT);
    pinMode(WHITE, OUTPUT);

    digitalWrite(GREEN, LOW);
    digitalWrite(RED, LOW);
    digitalWrite(YELLOW, LOW);
    digitalWrite(BLUE, LOW);
    digitalWrite(WHITE, LOW);
}

void light_loop_tasks() {

    if(previousMillis != 0 && LIGHT != 0) {
        if(LIGHT == 255) {
            flash_joystick();
        } else {
            flash();
        }
    }
}


void play_green() {
    setColor(GREEN);
}

void play_red() {
    setColor(RED);
}

void play_yellow() {
    setColor(YELLOW);
}

void play_blue() {
    setColor(BLUE);
}

void play_white() {
    setColor(WHITE);
}

void play_joystick() {
    setColor(255);
}

void setColor(uint8_t color) {
    if(LIGHT != 0) {
        return;
    }
    //Serial.println(color);

    previousMillis = millis();
    LIGHT = color;
}

void flash_joystick() {
    unsigned long currentMillis = millis();
    unsigned long difference = (currentMillis - previousMillis);

    //Serial.printf("%lu\n\n", difference);

    if(difference <= interval500 && STATE != HIGH) {
        lightsWrite(RED, HIGH);
        lightsWrite(GREEN, HIGH);
        STATE = HIGH;
    }

    else if (difference >= interval500 && STATE != LOW
        && difference <= (interval500*2)) {
        lightsWrite(RED, LOW);
        lightsWrite(GREEN, LOW); 
        STATE = LOW;
    }

    else if (difference >= interval500*2 && STATE != HIGH
        && difference <= (interval500*2 + interval200)) {
        lightsWrite(RED, HIGH);
        lightsWrite(GREEN, HIGH);
        STATE = HIGH;
    }

    else if (difference >= (interval500*2 + interval200) && STATE != LOW
        && difference <= (interval500*2 + interval200*2)) {
        lightsWrite(RED, LOW);
        lightsWrite(GREEN, LOW); 
        STATE = LOW;
    }

    else if (difference >= (interval500*2 + interval200*2) && STATE != HIGH
        && difference <= (interval500*2 + interval200*4)) {
        lightsWrite(RED, HIGH);
        lightsWrite(GREEN, HIGH);
        STATE = HIGH;
    }

    else if (difference >= (interval500*2 + interval200*4) && STATE != LOW
        && difference <= (interval500*2 + interval200*6)) {
        lightsWrite(RED, LOW);
        lightsWrite(GREEN, LOW); 
        STATE = LOW;
    }

    else if (difference >= (interval500*2 + interval200*6) && STATE != HIGH
        && difference <= (interval500*2 + interval200*8)) {
        lightsWrite(RED, HIGH);
        lightsWrite(GREEN, HIGH);
        STATE = HIGH;
    }

    else if (difference >= (interval500*2 + interval200*8) && STATE != LOW
        && difference <= (interval500*2 + interval200*10)) {
        lightsWrite(RED, LOW);
        lightsWrite(GREEN, LOW); 
        STATE = LOW;
    }

    else if (difference >= (interval500*2 + interval200*10) && STATE != HIGH
        && difference <= (interval500*2 + interval200*13)) {
        lightsWrite(RED, HIGH);
        lightsWrite(GREEN, HIGH);
        STATE = HIGH;
    }


    else if (difference >= (interval500*2 + interval200*13)){
        lightsWrite(RED, LOW);
        lightsWrite(GREEN, LOW);
        STATE = LOW;
        LIGHT = 0;
    }
}

void flash() {
    unsigned long currentMillis = millis();
    unsigned long difference = (currentMillis - previousMillis);

    //Serial.printf("%lu\n\n", difference);

    if(difference <= interval400 && STATE != HIGH) {
        lightsWrite(LIGHT, HIGH);
        STATE = HIGH;
    }

    else if (difference >= interval400 && STATE != LOW
        && difference <= (interval400*2)) {
        lightsWrite(LIGHT, LOW);
        STATE = LOW;
    }

    else if (difference >= (interval400*2) && STATE != HIGH
        && difference <= (interval400*2 + interval200)) {
        lightsWrite(LIGHT, HIGH);
        STATE = HIGH;
    }

    else if (difference >= (interval400*2 + interval200)) {
        lightsWrite(LIGHT, LOW);
        LIGHT = 0;
        STATE = LOW;
    }
}