// EV Automatic Fire Fighting System - Arduino UNO
const int tempPin=A0, smokePin=A1, flamePin=2, buzzerPin=8, relayPin=7;
float tempThreshold=50.0;
void setup(){pinMode(flamePin,INPUT); pinMode(buzzerPin,OUTPUT); pinMode(relayPin,OUTPUT); Serial.begin(9600);}
void loop(){
 int t=analogRead(tempPin); float temp=(t*(5.0/1023.0))*100;
 int smoke=analogRead(smokePin); int flame=digitalRead(flamePin);
 if(temp>tempThreshold || smoke>300 || flame==LOW){digitalWrite(buzzerPin,HIGH); digitalWrite(relayPin,HIGH);}
 else{digitalWrite(buzzerPin,LOW); digitalWrite(relayPin,LOW);}
 delay(1000);
}