
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  if(!Serial.available()){
    return;
  }
  char data =Serial.read();
  int pinNumber;
  int pinData;
  switch(data){
    case 'D':
      pinNumber=Serial.parseInt();
      pinMode(pinNumber,INPUT);
      Serial.println("The Digital data on pin "+String(pinNumber)+" is "+ String(digitalRead(pinNumber)));
    break;
    case 'd':
      pinNumber=Serial.parseInt();
      pinData=Serial.parseInt();
      Serial.println("Setting digital data on pin "+String(pinNumber)+" to "+ (pinData>0?"1":"0"));
      pinMode(pinNumber,OUTPUT);
      digitalWrite(pinNumber,pinData>0);
    break;
    case 'A':
      pinNumber=Serial.parseInt();
      pinMode(pinNumber,INPUT);
      Serial.println("The analog data on pin "+String(pinNumber)+" is "+ String(analogRead(pinNumber)));
    break;
    case 'a':
      pinNumber=Serial.parseInt();
      pinData=Serial.parseInt();
      Serial.println("Setting analog data on pin "+String(pinNumber)+" to "+ String(pinData));
      analogWrite(pinNumber,pinData);
    break;
  }
  // put your main code here, to run repeatedly:

}
