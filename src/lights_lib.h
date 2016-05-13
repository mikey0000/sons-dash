#include <Arduino.h>

#define GREEN (uint8_t)A5
#define WHITE (uint8_t)A2
#define RED (uint8_t)A4
#define BLUE (uint8_t)A1
#define YELLOW (uint8_t)A3

void lights_setup();

void play_green();
void play_red();
void play_blue();
void play_yellow();
void play_white();

void play_joystick();

void light_loop_tasks();