#define trigPin 44     // Trigger Pin for all sensors
#define echoPin1 46      // Echo Pin for sensor 1
#define echoPin2 48   // echo pin for sensor 2
#define echoPin3 50   // echo pin for sensor 3
#define echoPin4 52   // echo pin for sensor 4

void setup() {
 Serial.begin (9600);
 pinMode(trigPin, OUTPUT);      // trigger pin defined
 pinMode(echoPin1, INPUT);      // for sensor 1 echo defin
 pinMode(echoPin2, INPUT);      // for sensor 2 echo define
 pinMode(echoPin3, INPUT);      // for sensor 3 echo define
 pinMode(echoPin4, INPUT);      // for sensor 4 echo define
 
                             pinMode(22, OUTPUT);          // motor 2  forward
                             pinMode(26, OUTPUT);          // motor 2 reverse
                             pinMode(30, OUTPUT);          // motor 1 forward
                             pinMode(34, OUTPUT);          // motor 1 reverse
                             
 digitalWrite(26,LOW);        // initially motor forward so 26 and 34 low
 digitalWrite (34,LOW);
 digitalWrite(22, HIGH);      // initially motor forward so 22 and 30 low
 digitalWrite(30, HIGH);
 delay(1500);
 
 digitalWrite(22, LOW);      // for testiing these 2 lines are added
 digitalWrite(30, LOW);
 
}
void loop(){
  int duration1, duration2, duration3, duration4, distance1, distance2, distance3, distance4;     // varibles for sensors distance
  
  digitalWrite (trigPin, HIGH);          // trigger high
  delayMicroseconds(1000);
  digitalWrite (trigPin, LOW);          // trigger low
  
  duration1 = pulseIn(echoPin1, HIGH);         // duration measurments
  duration2 = pulseIn(echoPin2, HIGH);
  duration3 = pulseIn(echoPin3, HIGH);
  duration4 = pulseIn(echoPin4, HIGH);
  
 distance1=(duration1/58.2);                  // distance meaurments
 distance2=(duration2/58.2);
 distance3=(duration3/58.2);
 distance4=(duration4/58.2);
 
 if (distance1 > 0 && distance1 < 10){    // for sensor 1
 
   digitalWrite(22, HIGH);
   digitalWrite(30, HIGH);
   delay(1500);
   digitalWrite(22, LOW);
   digitalWrite(30, LOW);
  }
  
if (distance2 > 0 && distance2 < 10){      // for sensor 2
 
   digitalWrite(30, HIGH);
   delay(820);
   digitalWrite(22, HIGH);
   delay(1000)
   digitalWrite(22, LOW);
   digitalWrite(30, LOW);
   
  }

if (distance3 > 0 && distance3 < 10){      // for sensor 3
 
   digitalWrite(26, HIGH);
   digitalWrite(34, HIGH);
   delay(1500);
   digitalWrite(26, LOW);
   digitalWrite(34, LOW);
  }  
  
if (distance1 > 0 && distance1 < 10){        // for sensor 4
 
   digitalWrite(22, HIGH);
   delay(820);
   digitalWrite(34, HIGH);
   delay(1000)
   digitalWrite(22, LOW);
   digitalWrite(30, LOW);
   
  }
}
