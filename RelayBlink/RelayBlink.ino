//Test the relay switiching with a simple time interval
//MS:10/03/2018

const int rel1 = 12;
const int rel2 = 11;

void setup() {
  pinMode(rel1,OUTPUT);
  pinMode(rel2,OUTPUT);  

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(rel1,HIGH);
  digitalWrite(rel2,LOW);
  delay(2000);
  digitalWrite(rel2,HIGH);
  digitalWrite(rel1,LOW);
  delay(2000);
}
