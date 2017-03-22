/*
Edge avoider robot 
Two IR sensor which gain : 
==> under 100 if there is no edge 
==> over 100 if there is an edge 
Motor driver L298N 
Enable1 ==> pin 6 
Enable2 ==> pin 9 

input {1,2,3,4} ==> Arduino{2,3,4,5}

Ir sensor 1 ==> A0 
Ir sensor 2 ==> A1 

*/

/*
======= Algorithim Here ======
 

*/
int rightMotor1 = 2 ; 
int rightMotor2 = 3 ;
int leftMotor1 = 4 ; 
int leftMotor2 = 5 ; 
int enb1 = 6 ; 
int enb2 = 9 ; 
int irR = A0 ; 
int irL = A1 ;  
void setup() {
  pinMode(rightMotor1,OUTPUT);
  pinMode(rightMotor2,OUTPUT);
  pinMode(leftMotor1,OUTPUT);
  pinMode(leftMotor2,OUTPUT);
  pinMode(enb1,OUTPUT);
  pinMode(enb2,OUTPUT);
  pinMode(irR,INPUT);
  pinMode(irL,INPUT);
  Serial.begin(9600);

}

void loop() {
  checkEdge();
  handle();

}

void checkEdge(){
    int valR = sensorR();
    int valL = sensorL();
    if((valR <= 100) && (valL > 100)){
        halt();
        turnleft();
        delay(20);
      }else if((valR > 100) && (valL <= 100)){
          halt();
          turnright();
          delay(20);   
  }else if((valR < 100) && (valL < 100)){
          halt();
          delay(100);
            back();
            delay(100);
            handle();
          }else{
            forward();
            }
}
  void handle(){
    int valR = sensorR();
    int valL = sensorL();
    delay(50);
     valR = sensorR();
     valL = sensorL();
      turnleft();
      if((valR < 100 )&& (valL< 100)){
        turnright();
        delay(200);
        }
    }

int sensorR(){
  int valR = analogRead(A0);
  return valR ; 
  }
  int sensorL(){
  int valL = analogRead(A1);
  return valL ; 
  }

  void forward(){
  digitalWrite(rightMotor1,HIGH);
  digitalWrite(rightMotor2,LOW);
  digitalWrite(leftMotor1,HIGH);
  digitalWrite(leftMotor2,LOW);
  analogWrite(enb1,220);
  analogWrite(enb2,220);
    Serial.println("Forward");
    }

     void turnright(){
        digitalWrite(rightMotor1,LOW);
  digitalWrite(rightMotor2,HIGH);
  digitalWrite(leftMotor1,HIGH);
  digitalWrite(leftMotor2,LOW); 
  analogWrite(enb1,220);
  analogWrite(enb2,220);
  Serial.println("right");
    
    }
         void turnleft(){
  digitalWrite(rightMotor1,HIGH);
  digitalWrite(rightMotor2,LOW);
  digitalWrite(leftMotor1,LOW);
  digitalWrite(leftMotor2,HIGH);
  analogWrite(enb1,220);
  analogWrite(enb2,220);
  Serial.println("left");    
    }
         void halt(){
  digitalWrite(rightMotor1,LOW);
  digitalWrite(rightMotor2,LOW);
  digitalWrite(leftMotor1,LOW);
  digitalWrite(leftMotor2,LOW);
  Serial.println("stop");
    
    }
    void back(){
  digitalWrite(rightMotor1,LOW);
  digitalWrite(rightMotor2,HIGH);
  digitalWrite(leftMotor1,LOW);
  digitalWrite(leftMotor2,HIGH);
  analogWrite(enb1,220);
  analogWrite(enb2,220);
  Serial.println("back");
    
    }

