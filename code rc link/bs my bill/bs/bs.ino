/*
 
 
*/


#include <Servo.h>

Servo myservo; 

int pos = 0;

unsigned long thr;
unsigned long ali;
unsigned long elv;
unsigned long rud;
unsigned long aux; 

int gear = 1;


int st = 0;


void setup() {

  Serial.begin(9600);

    myservo.attach(13);  

    
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

  digitalWrite(29, HIGH);   
  digitalWrite(27, LOW);   
  digitalWrite(25, LOW);   
 digitalWrite(23, LOW);   
 
}
else if(gear == 2){

  digitalWrite(27, HIGH);
  digitalWrite(29, LOW);   
  digitalWrite(25, LOW);  
  digitalWrite(23, LOW);   
 
 }
else if(gear == 3){

  digitalWrite(25, HIGH);
  digitalWrite(29, LOW);   
  digitalWrite(27, LOW);  
 digitalWrite(23, LOW);   
 
}

else if(gear == 0){

digitalWrite(23, HIGH);
delay(200);
digitalWrite(23, LOW);
  digitalWrite(29, LOW);   
  digitalWrite(27, LOW);   
  digitalWrite(25, LOW);   
}

else if(gear == -1){

digitalWrite(23, HIGH);
  digitalWrite(29, LOW);  
  digitalWrite(27, LOW);   
  digitalWrite(25, LOW);   

  
}

pos = map(thr, 1103, 1888, 0, 180);

myservo.write(pos);              

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
