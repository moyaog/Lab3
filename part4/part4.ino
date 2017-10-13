
#include <Keypad.h>
#include <stdlib.h>

const byte Rows= 4; //number of rows on the keypad i.e. 4
const byte Cols= 3; //number of columns on the keypad i,e, 3

//we will definne the key map as on the key pad:

char keymap[Rows][Cols]=
{
{'1', '2', '3'},
{'4', '5', '6'},
{'7', '8', '9'},
{'*', '0', '#'}
};

unsigned long startTime = -1;
String specialCode = "2017427";
const int buttonPin = 30;
String buff = "";
boolean triggered = false;

//  a char array is defined as it can be seen on the above


//keypad connections to the arduino terminals is given as:

byte rPins[Rows]= {A3,A4,A5,A6}; //Rows 0 to 3
byte cPins[Cols]= {A0,A1,A2}; //Columns 0 to 2

// command for library forkeypad
//initializes an instance of the Keypad class
Keypad kpd= Keypad(makeKeymap(keymap), rPins, cPins, Rows, Cols);

void setup() {
   Serial.begin(9600);  // initializing serail monitor
   pinMode(LED_BUILTIN, OUTPUT);
   pinMode(buttonPin, INPUT);
   digitalWrite(LED_BUILTIN, LOW);
   kpd.addEventListener(keypadEvent);
}

void loop() {
  // put your main code here, to run repeatedly:
  char key = kpd.getKey();

  while(triggered) {
    Serial.println("ALARM!");
    
    // Blink code
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);

    triggered = !digitalRead(buttonPin);
  }
}

void keypadEvent(KeypadEvent key) {
  if(key == '#') {
    if(kpd.getState() == HOLD) {
      if(startTime < 0) {
        startTime = millis();
      }
      if((millis() - startTime) > 2000) {
        digitalWrite(LED_BUILTIN, HIGH);
        return;
      }
    }
  }
  else if(key == '*') {
    digitalWrite(LED_BUILTIN, LOW);
    startTime = -1;
    if(buff == specialCode) {
      triggered = true;
    }
    buff = "";
  }
  else if(kpd.getState() == PRESSED){
    buff += key;
    startTime = -1;
  }
}

