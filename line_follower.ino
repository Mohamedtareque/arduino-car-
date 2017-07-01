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
int rightMotor1 = 3 ; 
int rightMotor2 = 4 ;
int leftMotor1 = 8; 
int leftMotor2 = 9 ; 
int enb1 = 6 ; 
int enb2 = 5 ; 
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
  checkLine();
}


void checkLine(){
    int sensorRight = sensorR();
    int sensorLeft = sensorL();
    if((sensorRight) > 800 && (sensorLeft > 800) ){
        forward();
      }else if((sensorRight<800)&&(sensorLeft>800)){
          halt();
          delay(20);
          turnright();
          delay(50);
          
        }else if((sensorRight>800)&&(sensorLeft<800)){
          halt();
          delay(20);
          turnleft();
          delay(50);
        }else{
          
            halt();
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
  analogWrite(enb1,255);
  analogWrite(enb2,255);
    Serial.println("Forward");
    }

     void turnleft(){
        digitalWrite(rightMotor1,LOW);
  digitalWrite(rightMotor2,HIGH);
  digitalWrite(leftMotor1,HIGH);
  digitalWrite(leftMotor2,LOW); 
  analogWrite(enb1,255);
  analogWrite(enb2,255);
  Serial.println("right");
    
    }
         void turnright(){
  digitalWrite(rightMotor1,HIGH);
  digitalWrite(rightMotor2,LOW);
  digitalWrite(leftMotor1,LOW);
  digitalWrite(leftMotor2,HIGH);
  analogWrite(enb1,255);
  analogWrite(enb2,255);
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
  analogWrite(enb1,255);
  analogWrite(enb2,255);
  Serial.println("back");
    
    }
