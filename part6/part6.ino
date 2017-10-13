
const static int Rows = 4;
const static int Cols = 3;

char keymap[Rows][Cols]=
{
{'1', '2', '3'},
{'4', '5', '6'},
{'7', '8', '9'},
{'*', '0', '#'}
};


//  a char array is defined as it can be seen on the above


//keypad connections to the arduino terminals is given as:

byte rPins[Rows]= {18,19,20,21}; //Rows 0 to 3
byte cPins[Cols]= {15,16,17}; //Columns 0 to 2

void iSR1() {
  noInterrupts();
  pinMode(rPins[0], OUTPUT);
  for (int i = 0; i < Cols; i++) {
    pinMode(cPins[i], INPUT_PULLUP); 
  }
  digitalWrite(rPins[0],LOW);

  if (!digitalRead(cPins[0]))
    Serial.println("1");
  if (!digitalRead(cPins[1]))
    Serial.println("2");
  if (!digitalRead(cPins[2]))
    Serial.println("3");
  for (int i = 0; i < Cols; i++) {
    pinMode(cPins[i], OUTPUT);
    digitalWrite(cPins[i],LOW); 
  }
  pinMode(rPins[0], INPUT_PULLUP);
  interrupts();
}
void iSR2() {
  noInterrupts();
  pinMode(rPins[1], OUTPUT);
  for (int i = 0; i < Cols; i++) {
    pinMode(cPins[i], INPUT_PULLUP); 
  }
  digitalWrite(rPins[1],LOW);

  if (!digitalRead(cPins[0]))
    Serial.println("4");
  if (!digitalRead(cPins[1]))
    Serial.println("5");
  if (!digitalRead(cPins[2]))
    Serial.println("6");
  for (int i = 0; i < Cols; i++) {
    pinMode(cPins[i], OUTPUT);
    digitalWrite(cPins[i],LOW); 
  }
  pinMode(rPins[1], INPUT_PULLUP);
  interrupts();
}
void iSR3() {
  noInterrupts();
  pinMode(rPins[2], OUTPUT);
  for (int i = 0; i < Cols; i++) {
    pinMode(cPins[i], INPUT_PULLUP); 
  }
  digitalWrite(rPins[2],LOW);

  if (!digitalRead(cPins[0]))
    Serial.println("7");
  if (!digitalRead(cPins[1]))
    Serial.println("8");
  if (!digitalRead(cPins[2]))
    Serial.println("9");
  for (int i = 0; i < Cols; i++) {
    pinMode(cPins[i], OUTPUT);
    digitalWrite(cPins[i],LOW); 
  }
  pinMode(rPins[2], INPUT_PULLUP);
  interrupts();
}
void iSR4() {
    noInterrupts();
  pinMode(rPins[3], OUTPUT);
  for (int i = 0; i < Cols; i++) {
    pinMode(cPins[i], INPUT_PULLUP); 
  }
  digitalWrite(rPins[3],LOW);

  if (!digitalRead(cPins[0]))
    Serial.println("*");
  if (!digitalRead(cPins[1]))
    Serial.println("0");
  if (!digitalRead(cPins[2]))
    Serial.println("#");
  for (int i = 0; i < Cols; i++) {
    pinMode(cPins[i], OUTPUT);
    digitalWrite(cPins[i],LOW); 
  }
  pinMode(rPins[3], INPUT_PULLUP);
  interrupts();
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(rPins[0], INPUT_PULLUP); 
  attachInterrupt(  digitalPinToInterrupt(rPins[0]),
                    iSR1,
                    LOW);
  pinMode(rPins[1], INPUT_PULLUP); 
  attachInterrupt(  digitalPinToInterrupt(rPins[1]),
                    iSR2,
                    LOW);
  pinMode(rPins[2], INPUT_PULLUP); 
  attachInterrupt(  digitalPinToInterrupt(rPins[2]),
                    iSR3,
                    LOW);
  pinMode(rPins[3], INPUT_PULLUP); 
  attachInterrupt(  digitalPinToInterrupt(rPins[3]),
                    iSR4,
                    LOW);

  
  for (int i = 0; i < Cols; i++) {
    pinMode(cPins[i], OUTPUT); 
    digitalWrite(cPins[i],LOW);
  }
  

}



void loop() {
  // put your main code here, to run repeatedly:

}
