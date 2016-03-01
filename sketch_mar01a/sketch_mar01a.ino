#define BUTTON 2
#define LED 13

bool flag = false;

void setup() {
  // put your setup code here, to run once:
  
  pinMode(BUTTON, INPUT);
  pinMode(LED, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  if(digitalRead(BUTTON) == HIGH){
    flag = true;
  }
  
  if(flag == false){
    digitalWrite(LED, HIGH);
    delay(1000);
    digitalWrite(LED, LOW);
    delay(1000);
  }
}
