#define BUTTON1 2
#define LED 12

//Flag that controls the state of the button. False means it was never pressed.
bool flag = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(BUTTON1, INPUT);
  pinMode(LED, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  //Checks if the button was pressed. 
  if( digitalRead(BUTTON1) == LOW){
    flag = true;
  }

  //Blinks LED if button was never pressed. Otherwise the button remains in the HIGH state.
  if(flag == false){
    digitalWrite(LED, LOW);
    delay(1000);
    digitalWrite(LED, HIGH);
    delay(1000);
  }
}
