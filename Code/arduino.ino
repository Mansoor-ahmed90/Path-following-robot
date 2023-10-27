
//NOTE:: GROUND & Vcc FOR ULTRASONICs HAVE NOT BEEN USED,AS THEY WILL BE DIRECTLY PROVIDED FROM REGULATOR 
 ///////////////////////Defining variables/////////////////////////////
 int L_M_1= 23;  //IF 22+VE & 26-VE  THEN FORWARD
 int L_M_2= 22; 
 int R_M_1= 25; // IF 30+VE AND 34-VE FORWARD
 int R_M_2= 24; 
 
 int trigPin_f=49;  //pins for ultrasonic sensors//44
 int echoPin_f=48;//45
 int trigPin_rf=41;
 int echoPin_rf=40;
 int trigPin_rb=50;
 int echoPin_rb=51;
 int trigPin_lf=47;
 int echoPin_lf=46;
 int trigPin_lb=52;
 int echoPin_lb=53;
 
 int x=0;
 int turn=450;
 long duration_f,duration_rf,duration_rb,duration_lf,duration_lb;;
 long distance_f,distance_rf,distance_rb,distance_lf,distance_lb;  //long to  fill in with distance,,,,and duration used to find 
boolean entry,left_border,front_border_bnb,path_a,path_b,path_c; //for entry check

boolean a1,a2,a3,a4,a5,a6;    //for one time  repeat at A path
 
/////////////////////variable ,end/......setup start///////////////////////////




void setup() {
  
Serial.begin (9600);//baud rate for serial communication

pinMode(L_M_1, OUTPUT);//left motor pins 
pinMode(L_M_2, OUTPUT);
pinMode(R_M_1, OUTPUT);
pinMode(R_M_2, OUTPUT);

pinMode(trigPin_f, OUTPUT);//ultrsonic Front sensor
pinMode(echoPin_f, INPUT);
 
pinMode(trigPin_rf, OUTPUT);//ultrsonic right forward sensor
pinMode(echoPin_rf, INPUT);

pinMode(trigPin_rb, OUTPUT);//ultrsonic right back sensor
pinMode(echoPin_rb, INPUT);
 
pinMode(trigPin_lf, OUTPUT);//ultrsonic left forward sensor
pinMode(echoPin_lf, INPUT);

pinMode(trigPin_lb, OUTPUT);//ultrsonic left back sensor
pinMode(echoPin_lb, INPUT);
 

pinMode(13, OUTPUT);//LED  13

entry=1;left_border=1;front_border_bnb=1;path_a=0;path_b=0;path_c;

//Checks
a1=1;a2=1;a3=1;a4=2;a5=1;a6=1;
}//end od setup function





///////////////////setup end/..............loop main start//////////////////////////
void loop(){

/////////////////////////////////////FIRST CONDIOTION FOR ENTRY,,,ie enter stop and turn left////////////////////////////////////////////////
if(entry==1){///moving inside entry
while(1){
forward();
distance_f=ultrasonic_f();
delay(40);

if(distance_f<20){      ///break condition to break out of loop.
  entry=0;
  stop_motor();
  
  left();////to turn left  after first milestone at entry
  delay(turn);
  stop_motor();
  break;}
}//end of while
}//end of if entry
 /////////////////////////////////////END OF FIRST CONDITION///////////////////////////////////////////////////////////////////
   
 //////////////////////////////////START  OF SECOND CONDITION,STOP,CORRECTION,SECOND BORDER//////////////////////////////////////////////////////////////////   
if(left_border==1){///moving inside entry
while(1){
forward(); 
distance_f=ultrasonic_f();
delay(40);

if(distance_f<20){      ///break condition to break out of loop.
  left_border=0;
  stop_motor();
  
  right();      //turning right to face blocks
  delay(turn);
  stop_motor();
  break;}

}//end of if entry

 ///////////////////////////////////////////////END OF SECOND BORDER /////////////////////////////////////////////////////////
 
  //////////////////////////////////START  OF 3rd CONDITION,check if block or not and forward //////////////////////////////////////////////////////////////////   
if(front_border_bnb==1){
  
  
    //-------------------start--------if A open.........-----------------------------
    if((distance_f=ultrasonic_f())>160){/// for when there is a block //distance_f >120 && 
    while(1){ 
    delay(40);//delay used above bcz there is also an ultrasonic input in function condition
    distance_f=ultrasonic_f();
    distance_lf=ultrasonic_lf();
    distance_lb=ultrasonic_lb();
    distance_rf=ultrasonic_rf();
    forward();
if(a1==1){
    if(distance_f<167 && distance_f>164){///so correctio will occur at only at 165 cm away from left border
    a1=0;
    }} 

if(a2==1){
    if(distance_f<95 && distance_f>92){///so correctio will occur at 93,94cm away from left border
    stop_motor();//with above
    a2=0;}}//end of correction,end of if statement
    
    
 if(a3==1){
    if(distance_f<63 && distance_f>60){///so correctio will occur at 60,61 cm away from left border
  a3=0;}}//end of correction,end of if statement
    
    
if(a4>0){ //a4 has value of 2 as it is used for two turns
    if(distance_f<20){      ///break condition to break out of loop....,,will execute 2 time,,, 1st at A  2nd at entry to ramp//putting 2 time limit is must
    front_border_bnb=0;
    stop_motor();
    right();
    delay(turn);
    stop_motor();
    a4--;
    }}//end of IF

if(a5==1){    
    if(distance_lb>250 && distance_f<140){    // left and right  sensors are in millimeters,,,before entering into ramp entery
    stop_motor();    
    left();
    delay(turn);
    stop_motor();
  a5=0;}}//end of if
    
if(a6==1){
    if(distance_f<16 && distance_lb<200 && distance_rf<200 ){      ///before  ramp
    stop_motor();
    delay(20000);
    a6=0;
    break;   //robot has cleared A and turned right
    }}//end of IF
    
    }//end of while
    }//end of if entry  
     } // end of if statement for third 
    }//end of if
  
}
//  //------------------end--------if A open......block A is present-----------------------------
//  
//  
//      //-------------------start--------if A oblock,,,closed........-----------------------------
///*    if((distance_f=ultrasonic_f())<160){/// for when there is a block //distance_f >120 && 
//    while(1){ 
//    delay(40);//delay used above bcz there is also an ultrasonic input in function condition
//    distance_f=ultrasonic_f();
//
//
//    if(distance_f<97 && distance_f>94){///so correctio will occur at 95 cm away from left border
//    
//    forward();
//    if(distance_f <44){      ///break condition to break out of loop.
//    front_border_bnb=0;
//    stop_motor();
//    right();
//    break;}
//    }//end of while
//    }//end of if entry  
//     } // end of if statement for third 
//    }//end of void  
//    */
////-------------------END----------if block A is present-----------------------------
// ///////////////////////////////////////////////END OF S3rd conditon,ie with and withou block  /////////////////////////////////////////////////////////
///*
//right();
// delay(1100);
// stop_motor();
// 
// forward();
// delay(2000);
// stop_motor();
// 
// left();
// delay(1100);
// stop_motor();
// 
// reverse();
// delay(3000);
// stop_motor();
//*/
// 
//  /*
//  
////for ultrasonic
//digitalWrite(46, LOW);// ground of ultra
//digitalWrite(52, HIGH); //vcc for  ultra
//
////Serial.println(ultrasonic_f());
//Serial.print(ultrasonic_rf());
//Serial.print("\t");  
//Serial.println(ultrasonic_lf());
//Serial.print(ultrasonic_rb());
//Serial.print("\t");  
//Serial.println(ultrasonic_lb());
//Serial.println("\t");  
//Serial.println("\t");  
//delay(500);
//
//*/
////END OF LOOP
//
//
//




/////////////////////////////////////SUBROUTINES///////////////////////////////////////////////////////////////
////////////////Subroutines for motor motion///////////////////////////////////////////////////////////////////
void forward(){
digitalWrite(L_M_1, HIGH);
digitalWrite(L_M_2, LOW);
digitalWrite(R_M_1, HIGH);
digitalWrite(R_M_2, LOW);
}//end of forward function

void reverse(){
digitalWrite(L_M_1, LOW);
digitalWrite(L_M_2, HIGH);
digitalWrite(R_M_1, LOW);
digitalWrite(R_M_2, HIGH);

}//end of reverse function

void right(){
digitalWrite(L_M_1, HIGH);
digitalWrite(L_M_2, LOW);
digitalWrite(R_M_1, LOW);
digitalWrite(R_M_2, HIGH);
//delay(1100);   // 155 for shadman ,,,,deleted delay bcz we will be also using this fuction for  angle correction
}//end of right function

void left(){
digitalWrite(L_M_1, LOW);
digitalWrite(L_M_2, HIGH);
digitalWrite(R_M_1, HIGH);
digitalWrite(R_M_2, LOW);
//delay(1100);       // 155 for shadman ,,,,deleted delay bcz we will be also using this fuction for  angle correction
}//end of left function

void stop_motor(){
digitalWrite(L_M_1, LOW);
digitalWrite(L_M_2, LOW);
digitalWrite(R_M_1, LOW);
digitalWrite(R_M_2, LOW);
delay(500);
}//end of stop_motor function


////////////////////////////////////////////// subrotines for ultrasonics///////////////////////////////////////
long ultrasonic_f(){
 digitalWrite(trigPin_f, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPin_f, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin_f, LOW);
 duration_f = pulseIn(echoPin_f, HIGH);
 
 //Calculate the distance (in mm) based on the speed of sound.
 distance_f = duration_f/58.2;
 return distance_f;
}//end of ultrasonic _f



long ultrasonic_rf(){
 digitalWrite(trigPin_rf, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPin_rf, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin_rf, LOW);
 duration_rf = pulseIn(echoPin_rf, HIGH);
 
 //Calculate the distance (in mm) based on the speed of sound.
 distance_rf = duration_rf/5.82;
 return distance_rf;
}//end of ultrasonic _rf



long ultrasonic_rb(){
 digitalWrite(trigPin_rb, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPin_rb, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin_rb, LOW);
 duration_rb = pulseIn(echoPin_rb, HIGH);
 
 //Calculate the distance (in mm) based on the speed of sound.
 distance_rb = duration_rb/5.82;
 return distance_rb;
}//end of ultrasonic _rb



long ultrasonic_lf(){
 digitalWrite(trigPin_lf, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPin_lf, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin_lf, LOW);
 duration_lf = pulseIn(echoPin_lf, HIGH);
 
 //Calculate the distance (in mm) based on the speed of sound.
 distance_lf = duration_lf/5.82;
 return distance_lf;
}//end of ultrasonic_lf



long ultrasonic_lb(){
 digitalWrite(trigPin_lb, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPin_lb, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin_lb, LOW);
 duration_lb = pulseIn(echoPin_lb, HIGH);
 
 //Calculate the distance (in mm) based on the speed of sound.
 distance_lb = duration_lb/5.82;
 return distance_lb;
}//end of ultrasonic_lb






///////////end of ultra sonic subroutines//////////////////////////////////////////////
