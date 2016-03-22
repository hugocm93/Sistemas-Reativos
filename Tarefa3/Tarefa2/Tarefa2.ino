#include "event_driven.h"

#define BUTTON1 2
#define BUTTON2 4
#define LED 13
#define LEAP 50
#define INTERVAL 1000
#define TOLERANCE 500

long int interval = INTERVAL;
bool pressed[2] = {false, false};

void initialize () {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);
  button_listen(BUTTON1);
  button_listen(BUTTON2);
  timer_set (1, interval);
}


void button_changed (int pin, int v) {
  if (v) {
    switch (pin) {
      case BUTTON1:
        interval += LEAP;
        if (!pressed[0]) {
          pressed[0] = true;
          timer_set (2, TOLERANCE);
        }
        break;

      case BUTTON2:
        interval -= LEAP;
        if (interval < 0) {
          interval = 0;
        }
        if (!pressed[1]) {
          pressed[1] = true;
          timer_set (2, TOLERANCE);
        }
        break;
    }
    if (pressed[0] == true && pressed[1] == true) {
      digitalWrite(LED, LOW);
      while (true);
    }
  }
}


void timer_expired (int timerNumber) {
  switch (timerNumber) {
    case 1:
      if (digitalRead(LED) == HIGH) {
        digitalWrite(LED, LOW);
      }
      else {
        digitalWrite(LED, HIGH);
      }
      timer_set (1, interval);
      break;

    case 2:
      pressed[0] = false;
      pressed[1] = false;
      break;

  }

}
