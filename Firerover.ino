 //Firerover //
//*------ Arduino Fire Fighting Robot Code----- *//
//By ~ RHYTHM SHAH //
#include <NewPing.h> 
#include <Servo.h>
Servo myservo;
Servo servo;
int pos = 0; 
boolean fire = false;
/*-------defining Inputs------*/
#define Left_S 2 // left sensor
#define Right_S 3 // right sensor
#define Forward_S 4 //forward sensor
#define ena 13
#define enb 44 
#define TRIGGER_PIN A2
#define ECHO_PIN A3
/*-------defining Outputs------*/
#define IN1 9 // left motor
#define IN2 10 // left motor
#define IN3 11 // right motor
#define IN4 12 // right motor
#define pump 5
int i = 130;
const int sensorMin = 0; // sensor minimum
const int sensorMax = 1024; // sensor maximum
#define max_distance 50
NewPing sonar(TRIGGER_PIN, ECHO_PIN, max_distance);
int distance = 0;
int leftDistance;
int rightDistance;
boolean object;
void setup()
{
 pinMode(Left_S, INPUT);
 pinMode(Right_S, INPUT);
 pinMode(Forward_S, INPUT);
 pinMode(IN1, OUTPUT);
 pinMode(IN2, OUTPUT);
 pinMode(IN3, OUTPUT);
 pinMode(IN4, OUTPUT);
 pinMode(ena, OUTPUT);
 pinMode(enb, OUTPUT);
 pinMode(pump, OUTPUT);
 myservo.attach(6);
 myservo.write(90); 
 servo.attach(7);
 servo.write(0); 
}
void stopp() {
digitalWrite(IN1, HIGH);
digitalWrite(IN2, HIGH);
digitalWrite(IN3, HIGH);
digitalWrite(IN4, HIGH);
}
void put_off_fire()
{
 delay (380);
 stopp(); delay(10);
 digitalWrite(pump, HIGH); delay (800);
 for (pos = 50; pos <= 130; pos += 1) 
 { 
 myservo.write(pos);
 delay(10); 
 }
 for (pos = 130; pos >= 50; pos -= 1) { 
 myservo.write(pos);
 delay(10);
 }
digitalWrite(pump, LOW); 
 myservo.write(90);
 
 fire=false;
}
void objectAvoid() {
 distance = getDistance();
 if (distance <= 15) 
 {
 stopp();
 lookLeft();
 lookRight();
 delay(100);
 if (rightDistance <= leftDistance) {
 //left
 object = true;
 turn();
 
 } else {
 //right
 object = false;
 turn();
 
 }
 delay(100);
 }
 else {
 //forword
 moveForward();
 }
}
int getDistance() {
 delay(50);
 int cm = sonar.ping_cm();
 if (cm == 0) {
 cm = 100;
 }
 return cm;
}
int lookLeft () {
 //look left
 servo.write(150);
 delay(500);
 leftDistance = getDistance();
 delay(100);
 servo.write(90);
 return leftDistance;
 delay(100);
}
int lookRight() {
 //look right
 servo.write(30);
 delay(500);
 rightDistance = getDistance();
 delay(100);
 servo.write(90);
 return rightDistance;
 delay(100);
}
void turn() {
 if (object == false) {
 
 moveLeft();
 delay(700);
 moveForward();
 delay(800);
 moveRight();
 delay(900);
 if (digitalRead(Right_S) ==0) {
 loop();
 } else {
 moveForward();
 }
 }
 else {
 moveRight();
 delay(700);
 moveForward();
 delay(800);
 moveLeft();
 delay(900);
 if (digitalRead(Left_S) ==0) {
 loop();
 } else {
 moveForward();
 }
 }
}
void moveRight() {
   speedcontrol();   
 digitalWrite(IN1, HIGH);
 digitalWrite(IN2, LOW);
 digitalWrite(IN3, LOW);
 digitalWrite(IN4, HIGH);
}
void moveLeft() {
    speedcontrol();
digitalWrite(IN1, LOW);
digitalWrite(IN2, HIGH);
digitalWrite(IN3, HIGH);
digitalWrite(IN4, LOW);
}
void moveForward() {
   speedcontrol(); 
 digitalWrite(IN1, HIGH);
 digitalWrite(IN2, LOW);
 digitalWrite(IN3, HIGH);
 digitalWrite(IN4, LOW);
}
void speedcontrol() {
analogWrite (ena, i);
analogWrite (enb, i);
  delay(10);
}

void loop()
{
 myservo.write(90); //Sweep_Servo(); 
 // read the sensor on analog A0:
int sensorReading = analogRead(A0); int range = map(sensorReading, sensorMin, sensorMax, 0, 3); 
 if (digitalRead(Left_S) ==1 && digitalRead(Right_S)==1 && digitalRead(Forward_S) ==1) //If Fire not detected all sensors are zero
 {
 //Do not move the robot
 stopp() ;
 }
 
 else if (digitalRead(Forward_S) ==0) //If Fire is straight ahead
 {
 fire = true;
 moveForward(); //Move the robot forward
 objectAvoid();
 }
 else if (digitalRead(Left_S) ==0) //If Fire is to the left
 {
 //Move the robot left
 objectAvoid();
 moveLeft();
 }
 
 else if (digitalRead(Right_S) ==0) //If Fire is to the right
 {
 //Move the robot right
 objectAvoid();
 moveRight(); 
 }
 
delay(300); //Slow down the speed of robot
 while (fire == true)
 {
 put_off_fire();
 }
}
