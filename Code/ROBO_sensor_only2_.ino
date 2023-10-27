
#define echoPin1 8 // Echo Pin for sensor 1
#define trigPin 10 // Trigger Pin for sensor 1 & 2
//#define echoPin2 52 // echo pin for sensor 2

void setup() {
 Serial.begin (9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin1, INPUT);
 //pinMode(echoPin2, INPUT);
 pinMode(22, OUTPUT);
 pinMode(26, OUTPUT);
 pinMode(30, OUTPUT);
 pinMode(34, OUTPUT);
  digitalWrite(26,LOW);
   digitalWrite (34,LOW);
 digitalWrite(22, HIGH);
 digitalWrite(30, HIGH);
 delay(2000);
}
void loop(){
  int duration1, duration2, distance1,distance2;
  digitalWrite (trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite (trigPin, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
   //duration2 = pulseIn(echoPin2, HIGH);
 distance1=(duration1/58.2);
 //distance2=(duration2/58.2);
 if (distance1 >0 && distance1 < 10){
    digitalWrite(22, LOW);
 digitalWrite(30, LOW);
 delay(500);
   digitalWrite(26,HIGH);
   digitalWrite (34,HIGH);
   delay(500);}
  //digitalWrite(22,HIGH);
  //digitalWrite (30,HIGH);
 //}
// else{
// digitalWrite(22,HIGH);
//   digitalWrite (30,HIGH);
// }
 
// if (distance2 < 10){
 //digitalWrite(30,HIGH);
  // digitalWrite (22,LOW);
   //delay(850);
   //digitalWrite(30,HIGH);
 //  digitalWrite (22,HIGH);
 }
//   else{
//   digitalWrite(30,HIGH);
//   digitalWrite (22,LOW);
//   }
 
//delay(250);
//digitalWrite(22, HIGH);
//digitalWrite(30,HIGH);
//}
 
