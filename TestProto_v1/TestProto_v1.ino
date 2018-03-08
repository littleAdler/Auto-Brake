//testing mike branch commit
     //Battushigs V.12.58
     // defines pins numbers
const int trigPin = 9;
const int echoPin = 10;

const int greenLED = 7;
const int yellowLED = 6;
const int redLED = 5;

const int mosTrig =13;

const int releaseTrig =4;

const int cylinderA= 12; //blue LED
const int cylinderB= 11; //white LED

// defines variables
long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  
  pinMode(greenLED,OUTPUT);
  pinMode(yellowLED,OUTPUT);
  pinMode(redLED,OUTPUT);

  pinMode(releaseTrig,OUTPUT);
  
  attachInterrupt(yellowLED,fcn_smallBrake,HIGH); //brake at warning level
  attachInterrupt(redLED,fcn_largeBrake,HIGH); //more air at extreme warning level


  //Create an interrupt for over pressurized brake

  //Create an interrupt for user override
  
  Serial.begin(9600); // Starts the serial communication
}
void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(cylinderA,LOW);
  digitalWrite(cylinderB,LOW);
  
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculating the distance
  distance= duration*0.034/2;

  fcn_LED();
  //fcn_mosBlink();
  
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
}

void fcn_LED(){
  if(distance>100){
      digitalWrite(greenLED,HIGH);
      digitalWrite(yellowLED,LOW);
      digitalWrite(redLED,LOW);
  }else if(distance<=100 && distance>=60){
      digitalWrite(greenLED,LOW);
      digitalWrite(yellowLED,HIGH);
      digitalWrite(redLED,LOW);
      fcn_smallBrake();
  }else{
      digitalWrite(greenLED,LOW);
      digitalWrite(yellowLED,LOW);
      digitalWrite(redLED,HIGH);
      fcn_largeBrake();  
  }
  digitalWrite(cylinderB,HIGH);
  digitalWrite(cylinderA,LOW);
}

void fcn_smallBrake(){
  digitalWrite(cylinderB,LOW);
  
  digitalWrite(cylinderA,HIGH);
  delay(2000);
  digitalWrite(cylinderA,LOW);
  delay(2000);
  
}

void fcn_largeBrake(){
  digitalWrite(cylinderB, LOW);
  
  digitalWrite(cylinderA,HIGH);
  delay(3500);
  digitalWrite(cylinderA,LOW);
  delay(3500);
}


void fcn_mosBlink(){
  digitalWrite(releaseTrig,HIGH);
  delay(1000);
  digitalWrite(releaseTrig,LOW);
  delay(1000);
  }


