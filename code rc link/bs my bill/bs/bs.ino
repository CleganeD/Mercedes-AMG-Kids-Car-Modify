/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO 
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino model, check
  the Technical Specs of your board  at https://www.arduino.cc/en/Main/Products
  
  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
  
  modified 2 Sep 2016
  by Arturo Guadalupi
  
  modified 8 Sep 2016
  by Colby Newman
*/
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;

unsigned long thr;
unsigned long ali;
unsigned long elv;
unsigned long rud;
unsigned long aux; 

int gear = 1;


int st = 0;

// the setup function runs once when you press reset or power the board
void setup() {

  Serial.begin(9600);

    myservo.attach(13);  
  // initialize digital pin LED_BUILTIN as an output.
  

    
    pinMode(8, INPUT);
    pinMode(9, INPUT);
    pinMode(10, INPUT);
    pinMode(11, INPUT);
    pinMode(12, INPUT);
    
    pinMode(23, OUTPUT);
      pinMode(25, OUTPUT);
        pinMode(27, OUTPUT);
          pinMode(29, OUTPUT);
          
          pinMode(31, OUTPUT);  
          pinMode(33, OUTPUT);
 pinMode(47, OUTPUT);



}

// the loop function runs over and over again forever
void loop() {

if(st == 0){
  digitalWrite(51, HIGH);
  delay(5000);
  digitalWrite(51, LOW);
st = 1;
}

thr = pulseIn(12, HIGH);
ali = pulseIn(11, HIGH);
elv = pulseIn(10, HIGH);
rud = pulseIn(9, HIGH);
aux = pulseIn(8, HIGH);



// to long time concept time check sum


if(aux <= 1200){

digitalWrite(47, HIGH);
}
else{
digitalWrite(47, LOW);
 
}

gear = constrain(gear, -1, 3);

if(elv >= 1700){

gear = gear + 1;
delay(200);  
}

if(elv <= 1200){

gear = gear - 1;
delay(200);  
}


if(ali >= 1500){
digitalWrite(33, HIGH);
digitalWrite(31,LOW );

} 

else if(ali <= 1300){

digitalWrite(33,LOW );
digitalWrite(31, HIGH);
}
else{

digitalWrite(33,LOW );
digitalWrite(31, LOW);
  
}

if(gear == 1){

  digitalWrite(29, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(27, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(25, LOW);   // turn the LED on (HIGH is the voltage level)
 digitalWrite(23, LOW);   // turn the LED on (HIGH is the voltage level)
 
}
else if(gear == 2){

  digitalWrite(27, HIGH);
  digitalWrite(29, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(25, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(23, LOW);   // turn the LED on (HIGH is the voltage level)
 
 }
else if(gear == 3){

  digitalWrite(25, HIGH);
  digitalWrite(29, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(27, LOW);   // turn the LED on (HIGH is the voltage level)
 digitalWrite(23, LOW);   // turn the LED on (HIGH is the voltage level)
 
}

else if(gear == 0){

digitalWrite(23, HIGH);
delay(200);
digitalWrite(23, LOW);
  digitalWrite(29, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(27, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(25, LOW);   // turn the LED on (HIGH is the voltage level)
}

else if(gear == -1){

digitalWrite(23, HIGH);
  digitalWrite(29, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(27, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(25, LOW);   // turn the LED on (HIGH is the voltage level)

  
}

pos = map(thr, 1103, 1888, 0, 180);

myservo.write(pos);              // tell servo to go to position in variable 'pos'

Serial.println("GEAR: ");
Serial.println(gear);
Serial.println("");

Serial.println("SERVO: ");
Serial.println(pos);
Serial.println("");


Serial.println("thr: ");
Serial.println(thr);
Serial.println("ali: ");
Serial.println(ali);
Serial.println("elv: ");
Serial.println(elv);
Serial.println("rud: ");
Serial.println(rud);
Serial.println("aux: ");
Serial.println(aux);
Serial.println("END");

  
  



}
