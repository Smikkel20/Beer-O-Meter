#include <Arduino.h>
#include <TM1637Display.h>

// Module connection pins (Digital Pins)
#define CLK 2
#define DIO 3

#define pressureplate A3

TM1637Display display(CLK, DIO);
int HasTimed = 0;

int delaytime = 2000;
bool displayOn = true;
int lasttime = 0;
int delaystart = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  // set up the display
  display.setBrightness(0, true);
  display.showNumberDecEx(0, (0x80 >> 1), true);

  // set up the pressure plate
  pinMode(pressureplate, INPUT);
}

void loop() {
  int Pressureplate = analogRead(pressureplate);
  
  if (Pressureplate > 500 && millis() - delaystart > delaytime) {
    HasTimed = 0;
  }
  while (Pressureplate < 500 && HasTimed == 0) {

    display.showNumberDecEx(0, (0x80 >> 1), true);
    delay(100);
    Pressureplate = analogRead(pressureplate);
    if (Pressureplate > 500) {
      // start timer
      unsigned long start = millis();
      while (Pressureplate > 500) {
        Pressureplate = analogRead(pressureplate);
        unsigned long time = (millis() - start)/10;
        Serial.println(time);
        display.showNumberDecEx(time, (0x80 >> 1), true);
      }
      //stop timer
      unsigned long time = (millis() - start)/10;
      Serial.print("End Time: ");
      Serial.println(time);
      HasTimed = 1;
      display.showNumberDecEx(time, (0x80 >> 1), true);
      lasttime = time;
      delaystart = millis();
    }
  }
  

}
