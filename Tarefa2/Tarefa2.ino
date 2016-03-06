/*  Piscar o LED a cada 1 segundo.
    Botão 1: Acelerar o pisca­pisca a cada pressionamento.
    Botão 2: Desacelerar a cada pressionamento.
    Botão 1+2 (em menos de 500ms): Parar.
*/

#include<limits.h>
#define LED 12
#define leap 40
#define tolerance 5000

short interval = 1000;
int lastTime = millis();
int currentTime;

char buttons[2] = {2, 4};
bool pressed[2] = {false, false};
bool released[2] = {true, true};
int stampRelease[2] = {INT_MIN, INT_MIN};

void setup() {

  Serial.begin(9600);

  // put your setup code here, to run once:
  for (int i = 0; i < 2; i++) {
    pinMode(buttons[i], INPUT);
  }
  pinMode(LED, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  //Serial.println(interval);


  for (int i = 0; i < 2; i++) {
    
    //Checks if the buttoni was pressed.
    if ( digitalRead(buttons[i]) == LOW) {
      released[i] = false;
      pressed[i] = true;
    }

    //Checks if the buttoni was released.
    if ( digitalRead(buttons[i]) == HIGH && pressed[i] == true) {
      released[i] = true;
      pressed[i] = false;
      if (i == 0) {
        interval += 40;
      }
      else {
        interval -= 40;
      }
      stampRelease[i] = millis();
    }
  }

  if(Serial.println(abs(stampRelease[0] - stampRelease[1])) && abs(stampRelease[0] - stampRelease[1]) <= tolerance && stampRelease[0] != INT_MIN && stampRelease[1] != INT_MIN){
     digitalWrite(LED, LOW);
     Serial.println("Both pressed");
     while(true);
  }

  currentTime = millis();
  if (currentTime >= lastTime + interval) {
    lastTime = currentTime;
    if (digitalRead(LED) == HIGH) {
      digitalWrite(LED, LOW);
    }
    else {
      digitalWrite(LED, HIGH);
    }
  }
}
