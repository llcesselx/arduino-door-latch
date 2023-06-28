#include <Keypad.h>
#include <Servo.h>
  
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS]={4,5,3,2}; //connect to the row pinouts of the keypad
byte colPins[COLS]={9,8,7,6}; //conect to the cols pinouts of the keypad
Keypad keypad = Keypad(makeKeymap(keys),rowPins,colPins,ROWS,COLS);

Servo myservo;

unsigned int pass = 1234;
unsigned int guess;
bool passOK = false;
  
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  myservo.attach(12);
  Serial.begin(9600);
  myservo.write(0);
}


void loop()
{
  digitalWrite(LED_BUILTIN, LOW);
  char key = keypad.getKey();
    
  if ((key == '*' || key == '#') && passOK == false)
  	{
        if (guess == pass)
        {
          passOK = true;
          myservo.writeMicroseconds(1500);
          digitalWrite(10, HIGH);
          delay(100);
          digitalWrite(10, LOW);
          delay(100);
          digitalWrite(10, HIGH);
          delay(100);
          digitalWrite(10, LOW);
          delay(100);
          digitalWrite(10, HIGH);
          delay(100);
          digitalWrite(10, LOW);
          delay(3000);
          passOK = false;
          myservo.writeMicroseconds(0);
          guess = 0;
        }
        else
        {
          passOK = false;
          guess = 0;
          digitalWrite(11, HIGH);
          delay(100);
          digitalWrite(11, LOW);
          delay(100);
          digitalWrite(11, HIGH);
          delay(100);
          digitalWrite(11, LOW);
          delay(100);
          digitalWrite(11, HIGH);
          delay(100);
          digitalWrite(11, LOW);
        }
      }
  
  if (passOK == false && key >= '0' && key <= '9')
    {
    	digitalWrite(10, HIGH);
        guess = guess * 10 + (key - '0');
    	delay(100);
    	digitalWrite(10, LOW);
    }
  }
