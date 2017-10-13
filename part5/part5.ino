
const static int VCC = 2;
const static int TRIG = 3;
const static int ECHO = 4;
const static int GND = 5;



void setup() {
  // put your setup code here, to run once:
  pinMode(VCC, OUTPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(GND, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(VCC,HIGH);

  long duration, centimeters;
  
  //do a short cycle and clear trig
  digitalWrite(TRIG,LOW);
  delayMicroseconds(2);
  //runtrig, and turn it off
  digitalWrite(TRIG,HIGH);
  delayMicroseconds(5);
  digitalWrite(TRIG,LOW);

  //get a reading
  duration = pulseIn(ECHO, HIGH);

  //convert the data
  centimeters = microsecondsToCentimeters(duration);
  Serial.println(centimeters);

  delay(100);
}

/*
  Convert microseconds to centimeters
*/
long microsecondsToCentimeters(long microseconds) {
  return microseconds/29/2;
}
