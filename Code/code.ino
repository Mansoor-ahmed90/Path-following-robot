#define trigPin1 47         // Trigger Pin for sensors 1
#define echoPin1 46        // Echo Pin for sensor 1
#define trigPin2 44         // Trigger Pin for sensors 2
#define echoPin2 45        // echo pin for sensor 2
#define trigPin3 43         // Trigger Pin for sensors 3
#define echoPin3 42        //echo pin for sensor 3
#define trigPin4 50         // Trigger Pin for sensors 4
#define echoPin4 51        //echo pin for sensor 4
#define trigPin5 49         // Trigger Pin for sensors 5
#define echoPin5 48        // echo pin for sensor 5
#define trigPin6 52         // Trigger Pin for sensors 6
#define echoPin6 53        // echo pin for sensor 6
#define trigPin7 41         // Trigger Pin for sensors 7
#define echoPin7 40        // echo pin for sensor 7


void setup() {
 Serial.begin (9600);
 
 pinMode(trigPin1, OUTPUT);      // trigger pin defined 1
 pinMode(trigPin2, OUTPUT);      // trigger pin defined 2
 pinMode(trigPin3, OUTPUT);      // trigger pin defined 3
 pinMode(trigPin4, OUTPUT);      // trigger pin defined 4
 pinMode(trigPin5, OUTPUT);      // trigger pin defined 5 
 pinMode(trigPin6, OUTPUT);      // trigger pin defined 6
 pinMode(trigPin7, OUTPUT);      // trigger pin defined 7

 
 pinMode(echoPin1, INPUT);      // for sensor 1 echo defin
 pinMode(echoPin2, INPUT);      // for sensor 2 echo defin
 pinMode(echoPin3, INPUT);      // for sensor 3 echo defin
 pinMode(echoPin4, INPUT);      // for sensor 4 echo defin
 pinMode(echoPin5, INPUT);      // for sensor 5 echo defin
 pinMode(echoPin6, INPUT);      // for sensor 6 echo defin
 pinMode(echoPin7, INPUT);      // for sensor 7 echo defin
 
 
                             pinMode(22, OUTPUT);          // motor 2  revers
                             pinMode(23, OUTPUT);          // motor 2 forward
                             pinMode(24, OUTPUT);          // motor 1 reverse
                             pinMode(25, OUTPUT);          // motor 1 forward
                         
                             
// digitalWrite(23,LOW);        // initially motor forward so 26 and 34 low
// digitalWrite (25,LOW);
 //digitalWrite(23, HIGH);      // initially motor forward so 22 and 30 low
 //digitalWrite(25, HIGH);
//delay(1000);
// digitalWrite(22, LOW);      // for testiing these 2 lines are added
// digitalWrite(24, LOW);
 
}
void loop(){
  int duration1, distance1, duration2, distance2, duration3, distance3, duration4, distance4, duration5, distance5, duration6, distance6;
  
  //   **************** for sensor 1 *******************
  digitalWrite (trigPin1, LOW);          // trigger high
  delayMicroseconds(2);
   digitalWrite (trigPin1, HIGH);          // trigger high
  delayMicroseconds(10);
  digitalWrite (trigPin1, LOW);          // trigger low
  duration1 = pulseIn(echoPin1, HIGH);         // duration measurments
  distance1=(duration1/58.2);                  // distance meaurments
  
  //   **************** for sensor 2 *******************
 digitalWrite (trigPin2, LOW);          // trigger high
  delayMicroseconds(2);
 digitalWrite (trigPin2, HIGH);          // trigger high
  delayMicroseconds(10);
  digitalWrite (trigPin2, LOW);          // trigger low
  duration2 = pulseIn(echoPin2, HIGH);
   distance2=(duration2/58.2);
   
   // **************** for sensor 3 *******************
digitalWrite (trigPin3, LOW);          // trigger high
 delayMicroseconds(2);
digitalWrite (trigPin3, HIGH);          // trigger high
delayMicroseconds(10);
digitalWrite (trigPin3, LOW);          // trigger low
 duration3 = pulseIn(echoPin3, HIGH);
distance3=(duration3/58.2);

  //   **************** for sensor 4 *******************
 digitalWrite (trigPin4, LOW);          // trigger high
  delayMicroseconds(2);
 digitalWrite (trigPin4, HIGH);          // trigger high
  delayMicroseconds(10);
  digitalWrite (trigPin4, LOW);          // trigger low
  duration4 = pulseIn(echoPin4, HIGH);
   distance4=(duration4/58.2);



 //**************** for sensor 5 *******************
digitalWrite (trigPin5, LOW);          // trigger high
delayMicroseconds(2);
 digitalWrite (trigPin5, HIGH);          // trigger hig
 delayMicroseconds(10);
 digitalWrite (trigPin5, LOW);          // trigger low
duration5 = pulseIn(echoPin5, HIGH);
  distance5=(duration5/58.2);
  

   
   // Condition  
  
  if(distance1 > 10 && distance2 > 10 && distance3 > 10 && distance4 > 10 && distance5 > 10){
    //000000

 digitalWrite(23, HIGH);      // initially motor forward so 22 and 30 low
 digitalWrite(25, HIGH);
}

 if(distance1 > 10 && distance2 < 10 && distance3 > 10 && distance4 > 10 && distance5 > 10){
    //000005

 digitalWrite(23, HIGH);      // initially motor forward so 22 and 30 low
 digitalWrite(25, LOW);
}

if(distance1 > 15 && distance2 > 15 && distance3 > 15 && distance4 < 15 && distance5 > 15){
    //000040

 digitalWrite(25, LOW);      // initially motor forward so 22 and 30 low
 digitalWrite(23, HIGH);
}

 /*if(distance1 > 10 && distance2 > 10 && distance3 > 10 && distance4 < 10 && distance5 > 10){
    //000450

 digitalWrite(23, HIGH);      // initially motor forward so 22 and 30 low
 digitalWrite(25, LOW);
}*/

 if(distance1 > 10 && distance2 > 10 && distance3 < 10 && distance4 > 10 && distance5 > 10){
    //000300

 digitalWrite(23, LOW);      // initially motor forward so 22 and 30 low
 digitalWrite(25, HIGH);
}

if(distance1 > 10 && distance2 > 10 && distance3 > 10 && distance4 > 10 && distance5 < 10){
    //02000

 digitalWrite(23, LOW);      // initially motor forward so 22 and 30 low
 digitalWrite(25, HIGH);
}

if(distance1 < 10 && distance2 > 10&& distance3 > 10 && distance4 > 10 && distance5 > 10){
    //100000

 digitalWrite(23, LOW);      // initially motor forward so 22 and 30 low
 digitalWrite(25, LOW);
}

}
