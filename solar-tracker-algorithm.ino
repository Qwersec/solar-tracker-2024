const byte in1 = 13;
const byte in2 = 12;
const byte in3 = 11;
const byte in4 = 10;
const byte in5 = 7;
const byte in6 = 6;
const byte in7 = 5;
const byte in8 = 4;



void setup() {  
  Serial.begin(1200);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    pinMode(in5, OUTPUT);
    pinMode(in6, OUTPUT);
    pinMode(in7, OUTPUT);
    pinMode(in8, OUTPUT);
  
}

void loop() {
  // photoresistor readings
  int p1 = analogRead(A0);
  int p2 = analogRead(A1);
  int p3 = analogRead(A2);
  int p4 = analogRead(A3);

  int avg = (p1 + p2 + p3 + p4)/4; // optimally all photoresistors will have the exact same reading

  int limit = 40; // limit represents the minimum difference in lighting to activate the motor

  // each motor activates to move photoresistor values closer to the average
    if (abs(p1 - avg) > limit && p1 > avg){
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
    } else {
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
    }
    
    if (abs(p2 - avg) > limit && p2 > avg) {
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
    } else {
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
    }

    if (abs(p3 - avg) > limit && p3 > avg){
      digitalWrite(in5, LOW);
      digitalWrite(in6, HIGH);
    } else {
      digitalWrite(in5, LOW);
      digitalWrite(in6, LOW);
    } 

    if (abs(p4 - avg) > limit && p4 > avg){
      digitalWrite(in7, LOW);
      digitalWrite(in8, HIGH);
    } else {
      digitalWrite(in7, LOW);
      digitalWrite(in8, LOW);
    }

  //voltage reading of the solar panel for testing
  float reading = analogRead(A4) * 5.0 / 1023.0 * 10.0 / 2.2;
  Serial.println(reading);
}
