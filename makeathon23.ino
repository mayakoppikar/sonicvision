#include <Servo.h>
int smallval;
  int v = 150;
   long duration1,  cm1;
    long duration2,  cm2;
     long duration3,  cm3;
     long prevcm1, prevcm2, prevcm3 = 200;
     int distval = 50; //set this value do math and wtv. see stack exchange bookmark for more info.
     const float alpha = 0.5;

//set up for servo 1
const int servo1pingPin = 7; // Trigger Pin of Ultrasonic Sensor
const int servo1echoPin = 6; // Echo Pin of Ultrasonic Sensor
Servo servo1;
int servo1Pin = 8;
int angle1 = 0;    // variable to store the servo position
int period1 = 200; // oscillation period in milliseconds (1 second)

//set up for servo 2
// const int servo2pingPin = 3; // Trigger Pin of Ultrasonic Sensor
// const int servo2echoPin = 4; // Echo Pin of Ultrasonic Sensor
// Servo servo2;
// int servo2Pin = 5;
// int angle2 = 0;    // variable to store the servo position
// int period2 = 200; // oscillation period in milliseconds (1 second)

// //set up for servo 3
// const int servo3pingPin = 11; // Trigger Pin of Ultrasonic Sensor
// const int servo3echoPin = 10; // Echo Pin of Ultrasonic Sensor
// Servo servo3;
// int servo3Pin = 9;
// int angle3 = 0;    // variable to store the servo position
// int period3 = 200; // oscillation period in milliseconds (1 second)


//some new rando variables-idk if this is gonna work
int cm1count, cm2count, cm3count;
long cm1total, cm2total, cm3total;


void setup() {
  pinMode(servo1pingPin, OUTPUT);
  pinMode(servo1echoPin, INPUT);
  //  pinMode(servo2pingPin, OUTPUT);
  // pinMode(servo2echoPin, INPUT);
  //  pinMode(servo3pingPin, OUTPUT);
  // pinMode(servo3echoPin, INPUT);
   Serial.begin(9600); // Starting Serial Terminal
  servo1.attach(servo1Pin);
  // servo2.attach(servo2Pin);
  // servo3.attach(servo3Pin);

}

void loop()
{

 //code to find smallest distance-only change 
 if((millis() % 300) < 50){

  digitalWrite(servo1pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(servo1pingPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(servo1pingPin, LOW);
  duration1 = pulseIn(servo1echoPin, HIGH);
  cm1 = duration1 * 0.0343 / 2;
  cm1 = alpha * cm1 + (1 - alpha) * prevcm1;


// digitalWrite(servo2pingPin, LOW);
//   delayMicroseconds(2);
//   digitalWrite(servo2pingPin, HIGH);
//   delayMicroseconds(10);
//   digitalWrite(servo2pingPin, LOW);
//   duration2 = pulseIn(servo2echoPin, HIGH);
//   cm2 = duration2 * 0.0343 / 2;
//   cm2 = alpha * cm2 + (1 - alpha) * prevcm2;

// digitalWrite(servo3pingPin, LOW);
//   delayMicroseconds(2);
//   digitalWrite(servo3pingPin, HIGH);
//   delayMicroseconds(10);
//   digitalWrite(servo3pingPin, LOW);
//   duration3 = pulseIn(servo3echoPin, HIGH);
//   cm3 = duration3 * 0.0343 / 2;
//   cm3 = alpha * cm3 + (1 - alpha) * prevcm3;
  

//   prevcm1 = cm1;
//     prevcm2 = cm2;
//   prevcm3 = cm3;


  Serial.println((float)cm1);
  //   Serial.println((float)cm2);
  // Serial.println((float)cm3);
Serial.println();

  // smallval = smallest(cm1,cm2,cm3);
  //again 1am code prob wrong
  // smallval = smallest((cm1total + cm1)/(cm1count+1),(cm2total+cm2)/(cm2count+1),(cm3total+cm3/cm3count+1) );
  // cm1total = cm2total = cm3total = cm1count= cm2count = cm3count = 0;
  // Serial.println(smallval);
 }
 else{
  // cm1total += cm1;
  // cm1count++;
  //   cm2total += cm2;
  // cm2count++;
  //   cm3total += cm3;
  // cm3count++;
 }

//code maya wrote at 1 am to see if i can smooth the data(this is prob not gonna be right)


//  if(smallval == 1){
//     float frequency1 = map(cm1, 11, v, 0, 500);
//   frequency1 = (-frequency1 +500)/500;
//   float time1 = millis();
//   float period1 = 1.0 / frequency1 * 1000.0; // calculate period from frequency
//   float normalizedTime1 = fmod(time1, period1) / period1;
//   angle1 = int(sin(2 * PI * normalizedTime1) * 45) + 90; // Oscillate between 70 and 110 degrees
        
//          //heres some more code maya wrote at 1am-this is the dist - xy thing kadhir was talking abt yday at kins
//   //i do the same thing with cm2 and 3

//   // if((cm1 - prevcm1) > distval){

//   // }
//   // else{
//   servo1.write(angle1);  // sets the servo position according to the calculated angle
//   delay(20);
//   // }

//  } else if(smallval == 2){
//     float frequency2 = map(cm2, 11, v, 0, 500);
//   frequency2 = (-frequency2 +500)/500;
//   float time2 = millis();
//   float period2 = 1.0 / frequency2 * 1000.0; // calculate period from frequency
//   float normalizedTime2 = fmod(time2, period2) / period2;
//   angle2 = int(sin(2 * PI * normalizedTime2) * 45) + 90; // Oscillate between 70 and 110 degrees

//   // if((cm2 - prevcm2) > distval){

//   // }
//   // else{
//   servo2.write(angle2);  // sets the servo position according to the calculated angle
//   delay(20);
//   // }
//  }else if(smallval == 3){
//     float frequency3 = map(cm3, 11, v, 0, 500);
//   frequency3 = ((-frequency3 +500))/500;
//   float time3 = millis();
//   float period3 = 1.0 / frequency3 * 1000.0; // calculate period from frequency
//   float normalizedTime3 = fmod(time3, period3) / period3;
//   angle3 = int(sin(2 * PI * normalizedTime3) * 45) + 90; // Oscillate between 70 and 110 degrees
//   //  if((cm3 - prevcm3) > distval){

//   // }
//   // else{
//    servo3.write(angle3);  // sets the servo position according to the calculated angle
//   delay(20);
//   // }
  
//  }
 
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}

int smallest(long x, long y, long z){
  if((x>v)&&(y>v)&&(z>v)){
  return 0;
  }
  return x < y ? (x < z ? 1 : 3) : (y < z ? 2 : 3);

}


