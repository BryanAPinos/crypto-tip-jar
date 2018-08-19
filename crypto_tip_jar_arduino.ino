const int ledPin1 = 8;
const int ledPin2 = 2;
const int ledPin3 = 4;
const int ledPin4 = 7;

void setup() {
Serial.begin(9600); // set the baud rate
Serial.println("Ready"); // print "Ready" once
}

void loop() {
  char inByte = ' '; 
  
  if(Serial.available()){ // only send data back if data has been sent
    inByte = Serial.read(); // read the incoming data
    Serial.println(inByte); // send the data back in a new line so that it is not all one long line

  if(inByte == '0'){
    digitalWrite(ledPin4,LOW);
    digitalWrite(ledPin3,LOW);
    digitalWrite(ledPin2,LOW);
    digitalWrite(ledPin1,LOW); 
  }
  
  if(inByte == '1'){
    digitalWrite(ledPin4,LOW);
    digitalWrite(ledPin3,LOW);
    digitalWrite(ledPin2,LOW);
    digitalWrite(ledPin1,HIGH);
  }

  if(inByte == '2'){
    digitalWrite(ledPin4,LOW);
    digitalWrite(ledPin3,LOW);
    digitalWrite(ledPin2,HIGH);
    digitalWrite(ledPin1,HIGH);
  }

  if(inByte == '3'){
    digitalWrite(ledPin4,LOW);
    digitalWrite(ledPin3,HIGH);
    digitalWrite(ledPin2,HIGH);
    digitalWrite(ledPin1,HIGH);
  }

  if(inByte == '4'){
    digitalWrite(ledPin4,HIGH);
    digitalWrite(ledPin3,HIGH);
    digitalWrite(ledPin2,HIGH);
    digitalWrite(ledPin1,HIGH);
   
  }

    }
   
  delay(100); // delay for 1/10 of a second
}
