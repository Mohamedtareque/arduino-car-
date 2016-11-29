char data = 0;               
void setup() 
{
  Serial.begin(9600);         
  pinMode(13, OUTPUT);        
  pinMode(12, OUTPUT);        
  pinMode(11, OUTPUT);        
  pinMode(10, OUTPUT);        
  pinMode(9, OUTPUT);        
  pinMode(8, OUTPUT);        
  pinMode(7, OUTPUT);        
  pinMode(6, OUTPUT);        
}
void blinking(int pinNo ){
  digitalWrite(pinNo,HIGH);
  delay(500);
  digitalWrite(pinNo,LOW);
  delay(500);
}
void loop()
{
  if(Serial.available() > 0)  
  {
    data = Serial.read();      
    Serial.print(data);        
    Serial.print("\n");         
    if(data == 'F'){      
      digitalWrite(13, HIGH);
      digitalWrite(12, LOW);
      digitalWrite(11, HIGH);
      digitalWrite(10, LOW);
    }  
    else if(data == 'B') {      
      digitalWrite(13, LOW);
      digitalWrite(12, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(10, HIGH);
    }     
    else if(data == 'R') {      
      digitalWrite(13, HIGH);
      digitalWrite(12, LOW);
      digitalWrite(11, LOW);
      digitalWrite(10, LOW);
      blinking(8);
    }       
    else if(data == 'L') {      
      digitalWrite(13, LOW);
      digitalWrite(12, LOW);
      digitalWrite(11, HIGH);
      digitalWrite(10, LOW);
      blinking(9);
    } 
    else if(data == 'U') {      
      digitalWrite(13, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(7, HIGH);

    }  
    else if(data == 'u') {      
      digitalWrite(13, LOW);
      digitalWrite(12, LOW);
      digitalWrite(11, LOW);
      digitalWrite(10, LOW);
      digitalWrite(7, LOW);

    }
    else if(data == 'W') {      
      digitalWrite(6, HIGH);

    }
    else if(data == 'w') {      
      digitalWrite(6, LOW);

    }


  }
}






