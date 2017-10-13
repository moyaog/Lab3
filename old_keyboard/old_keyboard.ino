                  
/* the tutorial code for 3x4 Matrix Keypad with Arduino is as
This code prints the key pressed on the keypad to the serial port*/

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

char buff[10];

//  a char array is defined as it can be seen on the above


//keypad connections to the arduino terminals is given as:

byte rPins[Rows]= {A3,A4,A5,A6}; //Rows 0 to 3
byte cPins[Cols]= {A0,A1,A2}; //Columns 0 to 2

// command for library forkeypad
//initializes an instance of the Keypad class
Keypad kpd= Keypad(makeKeymap(keymap), rPins, cPins, Rows, Cols);

void setup()
{
     Serial.begin(9600);  // initializing serail monitor
     digitalWrite(LED_BUILTIN, HIGH);
}

//If key is pressed, this key is stored in 'keypressed' variable
//If key is not equal to 'NO_KEY', then this key is printed out
void loop()
{
    int i = 0;
    char keypressed=0; 
    Serial.println("starting main");
    while(keypressed = kpd.getKey() != '#' && i < 10) {
      if ((int)keypressed != 1) {
        buff[i] = keypressed;
        i++;
      }
    }

    for(int l = 0; l < 10; l++) {
      Serial.print(buff[l]);
      Serial.print(',');  
    }
    Serial.println("out");
    
    int input = atoi(buff);

    Serial.print("converted int ");
    Serial.println(input);

    for(int j = 0; j < input; j++) {
      digitalWrite(LED_BUILTIN, LOW);
      delay(10);
      digitalWrite(LED_BUILTIN, HIGH);
      delay(10);
    }

    for(int k = 0; k < 10; k++) {
      buff[k] = 0;
    }
}

