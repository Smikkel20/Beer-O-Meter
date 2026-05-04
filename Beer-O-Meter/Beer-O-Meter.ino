#include <Arduino.h>
#include <TM1637Display.h>

// Module connection pins (Digital Pins)
#define CLK 4
#define DIO 3


#define BUTTON 2

TM1637Display display(CLK, DIO);
int HasTimed = 0;

int delaytime = 2000;
bool displayOn = true;
int delaystart = 0;

void setup() {
  // set up the display
  display.setBrightness(0, true);
  display.showNumberDecEx(0, (0x80 >> 1), true);   // Display initial value "0" on the screen

  // set up the pressure plate
  pinMode(BUTTON, INPUT_PULLUP);
}

void loop() {
  int Switch = digitalRead(BUTTON);   // Read current state of the pressure plate

  if (Switch == 1 && millis() - delaystart > delaytime) {
    HasTimed = 0;
  }


  while(Switch == 0 && HasTimed == 0){

    display.showNumberDecEx(0, (0x80 >> 1), true);   // Show "0" on display while waiting
    delay(100);

    Switch = digitalRead(BUTTON);

    if (Switch == 1) {  // Button has been released - start timing process
      unsigned long start = millis();

      while (Switch == 1) {
        Switch = digitalRead(BUTTON);
        unsigned long time = (millis() - start)/10;
        display.showNumberDecEx(time, (0x80 >> 1), true);   // Display current elapsed time
      }

      // Button has been released - stop the timer
      unsigned long time = (millis() - start)/10;

      HasTimed = 1;
      display.showNumberDecEx(time, (0x80 >> 1), true);   // Show the final measured time on display

      delaystart = millis();
    }
  }
}

