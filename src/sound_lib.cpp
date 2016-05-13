//play from a list of sounds based on the pin number
#include <SD.h>                      // need to include the SD library
//#define SD_ChipSelectPin 53  //example uses hardware SS pin 53 on Mega2560
#define SD_ChipSelectPin 8  //using digital pin 2 on arduino nano 328, can use other pins
#include <SPI.h>
#include <TMRpcm.h> //  also need to include this library...

#include "lights_lib.h"

// afconvert -d UI8 -f 'WAVE' -b 11025 fire-engine-ringtone.mp3 fire-engine-ringtone-low.wav

//tmrpcm.play("car_x.wav"); //the sound file "music" will play each time the arduino powers up, or is reset
#define SOUND_1 (char *)"horn.wav" // green
#define SOUND_2 (char *)"crash.wav" // yellow change this
#define SOUND_3 (char *)"start.wav" // white
#define SOUND_4 (char *)"fire.wav" //blue
#define SOUND_5 (char *)"police.wav" // joystick left
#define SOUND_6 (char *)"sports.wav" // joystick up
#define SOUND_7 (char *)"start.wav"
#define SOUND_8 (char *)"english.wav" // red
#define SOUND_9 (char *)"start.wav"
#define SOUND_10 (char *)"skid.wav" // joystick right
#define SOUND_11 (char *)"start.wav"
#define SOUND_12 (char *)"rev.wav" // joystick down
#define SOUND_13 (char *)"start.wav"
#define SOUND_14 (char *)"start.wav"
#define SOUND_15 (char *)"start.wav"

TMRpcm tmrpcm;   // create an object for use in this sketch

void serial_SD_setup() {
  Serial.begin(9600);
   while (!Serial) {
     //Serial.println("waiting"); 
     // wait for serial port to connect. Needed for Leonardo only
  }
  if (!SD.begin(SD_ChipSelectPin)) {  // see if the card is present and can be initialized:
    Serial.println("SD fail");  
    return;   // don't do anything more if not
  }
  Serial.println("initialization done.");
}

void sound_setup() {
    pinMode(9, OUTPUT);
    tmrpcm.speakerPin = 9; //5,6,11 or 46 on Mega, 9 on Uno, Nano, etc
    tmrpcm.setVolume(5);
}

void setVolume(int vol) {
    tmrpcm.setVolume(vol);
}


void play_car_sound(int num) {
    switch(num) {
        case 1:
        if(!tmrpcm.isPlaying()) {
            tmrpcm.play(SOUND_1);// green
        }
        play_green();
        break;
        case 2:
        if(!tmrpcm.isPlaying()) {
            tmrpcm.play(SOUND_2);// yellow
        }
        play_yellow();
        break;
        case 3:
        if(!tmrpcm.isPlaying()) {
            tmrpcm.play(SOUND_3);// white
        }
        play_white();
        break;
        case 4:
        if(!tmrpcm.isPlaying()) {
            tmrpcm.play(SOUND_4);//blue
        }
        play_blue();
        break;
        case 5:
        if(!tmrpcm.isPlaying()) {
            tmrpcm.play(SOUND_5);// joystick left
        }
        play_joystick();
        break;
        case 6:
        if(!tmrpcm.isPlaying()) {
            tmrpcm.play(SOUND_6);// joystick up
        }
        break;
        case 7:
        tmrpcm.play(SOUND_7);
        break;
        case 8:
        if(!tmrpcm.isPlaying()) {
            tmrpcm.play(SOUND_8);// red
        }
        play_red();
        break;
        case 9:
        if(!tmrpcm.isPlaying()) {
            tmrpcm.play(SOUND_9);
        }
        break;
        case 10:
        if(!tmrpcm.isPlaying()) {
            tmrpcm.play(SOUND_10);// joystick right
        }
        play_joystick();
        break;
        case 11:
        tmrpcm.play(SOUND_11);
        break;
        case 12:
        if(!tmrpcm.isPlaying()) {
            tmrpcm.play(SOUND_12); // joystick down
        }
        break;
        case 13:
        tmrpcm.play(SOUND_13);
        break;
        case 14:
        tmrpcm.play(SOUND_14);
        break;
        case 15:
        tmrpcm.play(SOUND_15);
        break;
        default:
        break;
    }
}

