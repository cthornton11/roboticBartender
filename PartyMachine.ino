
#include <AFMotor.h>

//#define echoPin 4 // attach pin D4 Arduino to pin Echo of HC-SR04
//#define trigPin 6 //attach pin D6 Arduino to pin Trig of HC-SR04

AF_Stepper motor1(48, 1);
AF_Stepper motor2(48, 2);
int distanceToMove = 0;
int zero=0;
int done=1;
String rumCoke = "rumCoke";

const int  buttonPin = 2;    // the pin that the pushbutton is attached to
const int echoPin = A0;
const int trigPin = 13;
int buttonState = 0;         // current state of the button
int lastButtonState = 0; 
String answer;
int incomingByte = 0; // for incoming serial data

void setup() {
  // put your setup code here, to run once:
motor1.setSpeed(700);
motor2.setSpeed(600);
pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
pinMode(buttonPin, INPUT);

Serial.begin(9600);

}

void shot(){
      motor2.step(2800, BACKWARD, DOUBLE);
      delay(3500);
      motor2.step(2800, FORWARD, DOUBLE);
      motor2.step(1500, BACKWARD, DOUBLE);
      motor2.step(1500, FORWARD, DOUBLE);
      motor2.release();
      delay(800); 
}

void mixer1(){
      motor2.step(2800, BACKWARD, DOUBLE);
      delay(16000);
      motor2.step(2800, FORWARD, DOUBLE);
      motor2.release();
      delay(800); 
}

void mixer2(){
      motor2.step(2800, BACKWARD, DOUBLE);
      delay(6000);
      motor2.step(2800, FORWARD, DOUBLE);
      motor2.release();
      delay(800); 
}

void reset(){
  buttonState = digitalRead(buttonPin); // read the pushbutton input pin:
  while(buttonState == LOW ){
    buttonState = digitalRead(buttonPin);
    if (buttonState == LOW) {
      motor1.step(10, FORWARD, SINGLE); 
    }
  }
  
 motor1.release();
 answer = "";
}

bool isCup(){


// defines variables
  long duration; // variable for the duration of sound wave travel
  int distance; // variable for the distance measurement

  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");
  
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delay(1000);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  return distance > 10;
}

// backwards goes left on the motor
// forwards goes right
void loop() {

if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();
    if(incomingByte== '\n'){
      if(isCup()){
         sendDrink(answer);
      }
      else {
        answer = "";
      }
    }
    else{
      answer = answer + (char) incomingByte;
    }    
  }

}


void sendDrink(String answer) {

  Serial.print(answer);
  
    if(answer.equals("uvBlue")){
      shot();
    }
    else if (answer.equals("pinkW")){
      motor1.step(700, BACKWARD, DOUBLE);
      motor1.release();
      shot();
      reset();
    }
    else if (answer.equals("bacardi")){
      motor1.step(1400, BACKWARD, DOUBLE);
      motor1.release();
      shot();
      reset();
    }
    else if (answer.equals("coke")){
      motor1.step(2290, BACKWARD, DOUBLE);
      motor1.release();
      mixer1();
      reset();
    }
    else if (answer.equals("sprite")){
      motor1.step(3120, BACKWARD, DOUBLE);
      motor1.release();
      mixer1();
      reset();
    }
    else if (answer.equals("lemonade")){
      motor1.step(3820, BACKWARD, DOUBLE);
      motor1.release();
      mixer1();
      reset();
    }
    else if (answer.equals("blue lemonade")){
      shot();
      motor1.step(3820, BACKWARD, DOUBLE);
      motor1.release();
      mixer1();
      reset();
    }
    else if (answer.equals("blue sprite")){
      shot();
      motor1.step(3120, BACKWARD, DOUBLE);
      motor1.release();
      mixer1();
      reset();
    }
    else if (answer.equals("blue coke")){
      shot();
      motor1.step(2290, BACKWARD, DOUBLE);
      motor1.release();
      mixer1();
      reset();
    }
    else if (answer.equals("pink lemonade")){
      motor1.step(700, BACKWARD, DOUBLE);
      motor1.release();
      shot();
      motor1.step(3120, BACKWARD, DOUBLE);
      motor1.release();
      mixer1();
      reset();
    }
    else if (answer.equals("pink sprite")){
      motor1.step(700, BACKWARD, DOUBLE);
      motor1.release();
      shot();
      motor1.step(2420, BACKWARD, DOUBLE);
      motor1.release();
      mixer1();
      reset();
    }
    else if (answer.equals("pink coke")){
      motor1.step(700, BACKWARD, DOUBLE);
      motor1.release();
      shot();
      motor1.step(1590, BACKWARD, DOUBLE);
      motor1.release();
      mixer1();
      reset();
    }
    else if (answer.equals("rum lemonade")){
      motor1.step(1400, BACKWARD, DOUBLE);
      motor1.release();
      shot();
      motor1.step(2420, BACKWARD, DOUBLE);
      motor1.release();
      mixer1();
      reset();
    }
    else if (answer.equals("rum sprite")){
      motor1.step(1400, BACKWARD, DOUBLE);
      motor1.release();
      shot();
      motor1.step(1720, BACKWARD, DOUBLE);
      motor1.release();
      mixer1();
      reset();
    }
    else if (answer.equals("rum coke")){
      motor1.step(1400, BACKWARD, DOUBLE);
      motor1.release();
      shot();
      motor1.step(890, BACKWARD, DOUBLE);
      motor1.release();
      mixer1();
      reset();
    }
    
    else if (answer.equals("bluelemonadesprite")){
      shot();
      motor1.step(3120, BACKWARD, DOUBLE);
      motor1.release();
      mixer2();
      motor1.step(700, BACKWARD, DOUBLE);
      motor1.release();
      mixer2();
      reset();
    }
    else if (answer.equals("bluelemonadecoke")){
      shot();
      motor1.step(2290, BACKWARD, DOUBLE);
      motor1.release();
      mixer2();
      motor1.step(1530, BACKWARD, DOUBLE);
      motor1.release();
      mixer2();
      reset();
    }
    else if (answer.equals("pinklemonadesprite")){
      motor1.step(700, BACKWARD, DOUBLE);
      motor1.release();
      shot();
      motor1.step(2420, BACKWARD, DOUBLE);
      motor1.release();
      mixer2();
      motor1.step(700, BACKWARD, DOUBLE);
      motor1.release();
      mixer2();
      reset();
    }
    else if (answer.equals("pinklemonadecoke")){
      motor1.step(700, BACKWARD, DOUBLE);
      motor1.release();
      shot();
      motor1.step(1590, BACKWARD, DOUBLE);
      motor1.release();
      mixer2();
      motor1.step(1530, BACKWARD, DOUBLE);
      motor1.release();
      mixer2();
      reset();
    }
    else if (answer.equals("rumlemonadesprite")){
      motor1.step(1400, BACKWARD, DOUBLE);
      motor1.release();
      shot();
      motor1.step(1720, BACKWARD, DOUBLE);
      motor1.release();
      mixer2();
      motor1.step(700, BACKWARD, DOUBLE);
      motor1.release();
      mixer2();
      reset();
    }
    else if (answer.equals("rumlemonadecoke")){
      motor1.step(1400, BACKWARD, DOUBLE);
      motor1.release();
      shot();
      motor1.step(890, BACKWARD, DOUBLE);
      motor1.release();
      mixer2();
      motor1.step(1530, BACKWARD, DOUBLE);
      motor1.release();
      mixer2();
      reset();
    }

    else{
      answer = "";
    }
}
