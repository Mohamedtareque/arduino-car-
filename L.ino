int v = 0;
int ul = 13;
int ur = 12;
int dl = 11;
int dr = 10;
int b = 0;
int d = 0;

void setup() {
  pinMode(ur, OUTPUT);
  pinMode(ul, OUTPUT);
  pinMode(dr, OUTPUT);
  pinMode(dl, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(3, INPUT);
  pinMode(2, INPUT);

  Serial.begin(9600); 
}

void loop() {
  v = analogRead(A0); 
  b = digitalRead(2); 
  d = digitalRead(3); 

  if(b==1){
    if(v >= 0 && v<=260 && d==1){
      //north east 
      digitalWrite(13,HIGH);
      digitalWrite(12,LOW);
      digitalWrite(11,LOW);
      digitalWrite(10,LOW);
      Serial.println("north east");
    }
    else if(v >= 0 && v<=260 && d==0){
      //south east 
      digitalWrite(13,LOW);
      digitalWrite(12,HIGH);
      digitalWrite(11,LOW);
      digitalWrite(10,LOW);
      Serial.println("south east");

    }
    else if(v <= 1023 && v>=770 && d==1){
      //north west
      digitalWrite(13,LOW);
      digitalWrite(12,LOW);
      digitalWrite(11,HIGH);
      digitalWrite(10,LOW);   
      Serial.println("north west");

    }
    else if(v <= 1023 && v>=770 && d==0){
      //south west
      digitalWrite(13,LOW);
      digitalWrite(12,LOW);
      digitalWrite(11,LOW);
      digitalWrite(10,HIGH); 
      Serial.println("south west");  
    }
    else if(v >=270 && v<=760 && d==1){
      //north
      digitalWrite(13,HIGH);
      digitalWrite(12,LOW);
      digitalWrite(11,HIGH);
      digitalWrite(10,LOW); 
      Serial.println("north");  
    }
    else if(v >=270 && v<=760 && d==0){
      //south
      digitalWrite(13,LOW);
      digitalWrite(12,HIGH);
      digitalWrite(11,LOW);
      digitalWrite(10,HIGH); 
      Serial.println("south");  
    }

    else{
      digitalWrite(13,LOW);
      digitalWrite(12,LOW);
      digitalWrite(11,LOW);
      digitalWrite(10,LOW);  
      Serial.println("stoped");  
    }
  }
  else{
    digitalWrite(13,LOW);
    digitalWrite(12,LOW);
    digitalWrite(11,LOW);
    digitalWrite(10,LOW);
    Serial.println("car is off");  
  }
}









