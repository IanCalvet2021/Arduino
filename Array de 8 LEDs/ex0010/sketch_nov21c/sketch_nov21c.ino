/**********************************************************************************
**                                                                               **
**                              Array de 8 LEDs                                  **
**                                                                               **
**                                                                               **
**********************************************************************************/

//********** Includes *************************************************************

//********** Variables ************************************************************
const byte ledPin[] = {5, 6, 7, 8, 9, 10, 11, 12};  
const byte buttonPin[] = {2, 3};
boolean buttonEstat[] = {LOW, LOW};

int ledNum = 8;
int buttonNum = 2;
byte num = 0;               

//********** Setup ****************************************************************
void setup()
{
  for(int i = 0; i < ledNum; i++) 
  {
    pinMode(ledPin[i], OUTPUT);
  }
  for(int i = 0; i < buttonNum; i++)
  {
    pinMode(buttonPin[i], OUTPUT);
  }
  for(int j = 0; j < ledNum ; j++)  
  {
    digitalWrite(ledPin[j], 0);
  }
}

//********** Loop *****************************************************************
void loop()
{
  buttonEstat[0] = digitalRead(buttonPin[0]);
  buttonEstat[1] = digitalRead(buttonPin[1]);
 
  if (buttonEstat[0] == HIGH) 
  {
    num = num + 1;                 
    for(int j = 0; j < ledNum ; j++)   
    {
      digitalWrite(ledPin[j], bitRead(num, j));
    }
    delay(500);   
  }
 
  if (buttonEstat[1] == HIGH)  // disminuir
  {
    num = num - 1;                 
    for(int j = 0; j < ledNum ; j++)   
    {
      digitalWrite(ledPin[j], bitRead(num, j));
    }
    delay(500);   
  }
}

//********** Funcions *************************************************************
