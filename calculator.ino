                                                    /*CALCULATOR*/
/* Components required:
1. Arduino Uno
2. 4x4 Keypad
3. 16x2 LCD */

/**********************************************/

#include<Keypad.h> //To operate keypad
#include<Wire.h> //To connect wires btw arduino & lcd
#include<LiquidCrystal.h> //To operate lcd display

LiquidCrystal lcd(13,12,11,10,9,8);

long first=0; //First number
long second=0;//Second number
float total=0;//Final value

char myKey;
const byte ROWS=4;//Connect to rowpins of keypad
const byte COLS=4;//Connect to column pins of keypad

char keys [ROWS] [COLS]={{'1','2','3','+'}, //A corresponds to addition operation
                         {'4','5','6','-'}, //B corresponds to subtraction operation
                         {'7','8','9','*'}, //C corresponds to multiplication operation
                         {'C','0','=','/'}}; //D corresponds to division operation,* corresponds to clear operation,# corresponds to equal operator

byte rowPins[ROWS]={7,6,5,4};
byte colPins[COLS]={3,2,1,0};

Keypad myKeypad=Keypad(makeKeymap(keys),rowPins,colPins,ROWS,COLS);//Initialize keypad

//makeKeymap(keys)initializes the internal keymap to be equal to user defined keymap
//rowPins and colPins are arduino pins to which rows & columns of keypad are connected
//ROWS & COLS are no of rows & columns of the keypad

void setup()
{
  lcd.begin(16,2);
  for(int i=0;i<=3;i++)
  lcd.setCursor(0,0);
  lcd.print("CALCULATOR");
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print("Enter Numbers");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
}

void loop()
{
  myKey= myKeypad.getKey();//getKey() is used to read the values from keypad and display it on lcd 
  switch(myKey)
  {
    case '0':
      lcd.setCursor(0,0);
      first=(first*10)+(myKey-'0');
      lcd.print(first);
      break;
    case '1':
      lcd.setCursor(0,0);
      first=(first*10)+(myKey-'0');
      lcd.print(first);
      break;
    case '2':
      lcd.setCursor(0,0);
      first=(first*10)+(myKey-'0');
      lcd.print(first);
      break;
    case '3':
      lcd.setCursor(0,0);
      first=(first*10)+(myKey-'0');
      lcd.print(first);
      break;
    case '4':
      lcd.setCursor(0,0);
      first=(first*10)+(myKey-'0');
      lcd.print(first);
      break;
    case '5':
      lcd.setCursor(0,0);
      first=(first*10)+(myKey-'0');
      lcd.print(first);
      break;
    case '6':
      lcd.setCursor(0,0);
      first=(first*10)+(myKey-'0');
      lcd.print(first);
      break;
    case '7':
      lcd.setCursor(0,0);
      first=(first*10)+(myKey-'0');
      lcd.print(first);
      break;
     case '8':
      lcd.setCursor(0,0);
      first=(first*10)+(myKey-'0');
      lcd.print(first);
      break;
     case '9':
      lcd.setCursor(0,0);
      first=(first*10)+(myKey-'0');
      lcd.print(first);
      break;
      
    case '+':
      first=(total!=0?total:first);
      lcd.print("+");
      second=secondNumber();
      total=first+second;
      lcd.setCursor(0,3);
      lcd.print("=");
      lcd.print(total);
      first=0,second=0;
      break;

      case '-':
      first=(total!=0?total:first);
      lcd.print("-");
      second=secondNumber();
      total=first-second;
      lcd.setCursor(0,3);
      lcd.print("=");
      lcd.print(total);
      first=0,second=0;
      break;

      case '*':
      first=(total!=0?total:first);
      lcd.print("*");
      second=secondNumber();
      total=first*second;
      lcd.setCursor(0,3);
      lcd.print("=");
      lcd.print(total);
      first=0,second=0;
      break;

      case '/':
      first=(total!=0?total:first);
      lcd.print("/");
      second=secondNumber();
      lcd.setCursor(0,3);
      second==0?lcd.print("Invalid"):total=(float)first/(float)second;
      lcd.print("=");
      lcd.print(total);
      first=0,second=0;
      break;

      case 'C':
        total=0;
        lcd.clear();
        break;
  }
}

long secondNumber()
{
  while( 1 )
  {
    myKey=myKeypad.getKey();
    if(myKey>='0' && myKey<='9')
    {
      second=(second*10)+(myKey-'0');
      lcd.setCursor(3,0);
      lcd.print(second);
    }
    if(myKey== '=') break;
  }
 return second;
}
