#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN         9          // Configurable, see typical pin layout above
#define SS_PIN          10         // Configurable, see typical pin layout above

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display
MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance

//buzzer setting
const int buzzer = 7; //buzzer to arduino pin 9


void setup()
{
  //LCD setup
  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(3,0); //第一列 第四行（格）
  lcd.print("Good morning ");
  lcd.setCursor(2,1); //第二列 第三行（格）
  lcd.print("Door Security");
  lcd.setCursor(0,2); //第三列 第二行（格）
  lcd.print("Door Bell");
  lcd.setCursor(2,3); //第四列 第三行（格）
  lcd.print("Power By Ec-yuan!");

  //MERC setup
  Serial.begin(9600);    // Initialize serial communications with the PC
  while (!Serial);    // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
  SPI.begin();      // Init SPI bus
  mfrc522.PCD_Init();   // Init MFRC522
  delay(4);       // Optional delay. Some board do need more time after init to be ready, see Readme
  mfrc522.PCD_DumpVersionToSerial();  // Show details of PCD - MFRC522 Card Reader details
  Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));
  pinMode(7,OUTPUT);

  //buzzer setup
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output
}


void loop()
{
// Look for new cards
if ( ! mfrc522.PICC_IsNewCardPresent())
{
return;
}
// Select one of the cards
if ( ! mfrc522.PICC_ReadCardSerial())
{
return;
}
//Show UID on serial monitor
Serial.print("UID tag :");

String content= "";
byte letter;
for (byte i = 0; i < mfrc522.uid.size; i++)
{
Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
Serial.print(mfrc522.uid.uidByte[i], HEX);
content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
content.concat(String(mfrc522.uid.uidByte[i], HEX));
}
Serial.println();
Serial.print("Message : ");
content.toUpperCase();


if (content.substring(1) == "03 54 25 97") //change here the UID of the card/cards that you want to give access
{
Serial.println("Authorized access");
Serial.println();

lcd.setCursor(3,0);
lcd.print("Welcome back,");
lcd.setCursor(2,1);
lcd.print("Charlotte!");


  tone(buzzer, 320); 
  delay(300);        // Mi...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500); 
  tone(buzzer, 320); 
  delay(300);        // Mi...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500); 
  tone(buzzer, 341.3); 
  delay(300);        //Fa ...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sec
  tone(buzzer, 384); 
  delay(300);        // So...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500); 
  tone(buzzer, 384); 
  delay(300);        // So...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500); 
  tone(buzzer, 341.3); 
  delay(300);        //Fa ...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sec
  tone(buzzer, 320); 
  delay(300);        // Mi...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500); 
  tone(buzzer, 288); 
  delay(300);        // Re...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500); 

  tone(buzzer, 256); 
  delay(300);        // Do...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500); 
  tone(buzzer, 256); 
  delay(300);        // Do...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500); 
   tone(buzzer, 288); 
  delay(300);        // Re...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500); 
   tone(buzzer, 320); 
  delay(300);        // Mi...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500);
   tone(buzzer, 320); 
  delay(400);        // Mi...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500);
   tone(buzzer, 288); 
  delay(250);        // Re...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(10);        // ...for 1sectone(buzzer, 500); 
   tone(buzzer, 288); 
  delay(250);        // Re...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(1000);        // ...for 1sectone(buzzer, 500); 
  
    tone(buzzer, 320); 
  delay(300);        // Mi...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500); 
  tone(buzzer, 320); 
  delay(300);        // Mi...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500); 
  tone(buzzer, 341.3); 
  delay(300);        //Fa ...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sec
  tone(buzzer, 384); 
  delay(300);        // So...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500); 
  tone(buzzer, 384); 
  delay(300);        // So...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500); 
  tone(buzzer, 341.3); 
  delay(300);        //Fa ...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sec
  tone(buzzer, 320); 
  delay(300);        // Mi...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500); 
  tone(buzzer, 288); 
  delay(300);        // Re...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500); 

  tone(buzzer, 256); 
  delay(300);        // Do...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500); 
  tone(buzzer, 256); 
  delay(300);        // Do...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500); 
   tone(buzzer, 288); 
  delay(300);        // Re...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500); 
   tone(buzzer, 320); 
  delay(300);        // Mi...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500);

   tone(buzzer, 288); 
  delay(400);        // Re...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500); 
  tone(buzzer, 256); 
  delay(250);        // Do...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(10);        // ...for 1sectone(buzzer, 500); 
    tone(buzzer, 256); 
  delay(250);        // Do...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(1000);        // ...for 1sectone(buzzer, 500); 
  
delay(3000);
}
else if (content.substring(1) == "93 6C 3D 05") //change here the UID of the card/cards that you want to give access
{
Serial.println("Authorized access");
Serial.println();

lcd.setCursor(3,0);
lcd.print("Welcome back, ");
lcd.setCursor(2,1);
lcd.print("Sandy!How R U ?");


  tone(buzzer, 320); 
  delay(300);        // Mi...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500); 
  tone(buzzer, 320); 
  delay(300);        // Mi...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500); 
  tone(buzzer, 341.3); 
  delay(300);        //Fa ...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sec
  tone(buzzer, 384); 
  delay(300);        // So...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500); 
  tone(buzzer, 384); 
  delay(300);        // So...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500); 
  tone(buzzer, 341.3); 
  delay(300);        //Fa ...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sec
  tone(buzzer, 320); 
  delay(300);        // Mi...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500); 
  tone(buzzer, 288); 
  delay(300);        // Re...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500); 

  tone(buzzer, 256); 
  delay(300);        // Do...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500); 
  tone(buzzer, 256); 
  delay(300);        // Do...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500); 
   tone(buzzer, 288); 
  delay(300);        // Re...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500); 
   tone(buzzer, 320); 
  delay(300);        // Mi...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500);
   tone(buzzer, 320); 
  delay(400);        // Mi...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500);
   tone(buzzer, 288); 
  delay(250);        // Re...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(10);        // ...for 1sectone(buzzer, 500); 
   tone(buzzer, 288); 
  delay(250);        // Re...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(1000);        // ...for 1sectone(buzzer, 500); 
  
    tone(buzzer, 320); 
  delay(300);        // Mi...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500); 
  tone(buzzer, 320); 
  delay(300);        // Mi...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500); 
  tone(buzzer, 341.3); 
  delay(300);        //Fa ...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sec
  tone(buzzer, 384); 
  delay(300);        // So...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500); 
  tone(buzzer, 384); 
  delay(300);        // So...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500); 
  tone(buzzer, 341.3); 
  delay(300);        //Fa ...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sec
  tone(buzzer, 320); 
  delay(300);        // Mi...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500); 
  tone(buzzer, 288); 
  delay(300);        // Re...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500); 

  tone(buzzer, 256); 
  delay(300);        // Do...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500); 
  tone(buzzer, 256); 
  delay(300);        // Do...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500); 
   tone(buzzer, 288); 
  delay(300);        // Re...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500); 
   tone(buzzer, 320); 
  delay(300);        // Mi...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500);

   tone(buzzer, 288); 
  delay(400);        // Re...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500); 
  tone(buzzer, 256); 
  delay(250);        // Do...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(10);        // ...for 1sectone(buzzer, 500); 
    tone(buzzer, 256); 
  delay(250);        // Do...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(1000);        // ...for 1sectone(buzzer, 500); 

delay(3000);
}
else if (content.substring(1) == "75 2E 22 38") //change here the UID of the card/cards that you want to give access
{
Serial.println("Authorized access");
Serial.println();

lcd.setCursor(3,0);
lcd.print("Welcome back, ");
lcd.setCursor(2,1);
lcd.print("Eileen! Have a nice day !");


  tone(buzzer, 320); 
  delay(300);        // Mi...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500); 
  tone(buzzer, 320); 
  delay(300);        // Mi...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500); 
  tone(buzzer, 341.3); 
  delay(300);        //Fa ...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sec
  tone(buzzer, 384); 
  delay(300);        // So...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500); 
  tone(buzzer, 384); 
  delay(300);        // So...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500); 
  tone(buzzer, 341.3); 
  delay(300);        //Fa ...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sec
  tone(buzzer, 320); 
  delay(300);        // Mi...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500); 
  tone(buzzer, 288); 
  delay(300);        // Re...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500); 

  tone(buzzer, 256); 
  delay(300);        // Do...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500); 
  tone(buzzer, 256); 
  delay(300);        // Do...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500); 
   tone(buzzer, 288); 
  delay(300);        // Re...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500); 
   tone(buzzer, 320); 
  delay(300);        // Mi...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500);
   tone(buzzer, 320); 
  delay(400);        // Mi...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500);
   tone(buzzer, 288); 
  delay(250);        // Re...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(10);        // ...for 1sectone(buzzer, 500); 
   tone(buzzer, 288); 
  delay(250);        // Re...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(1000);        // ...for 1sectone(buzzer, 500); 
  
    tone(buzzer, 320); 
  delay(300);        // Mi...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500); 
  tone(buzzer, 320); 
  delay(300);        // Mi...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500); 
  tone(buzzer, 341.3); 
  delay(300);        //Fa ...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sec
  tone(buzzer, 384); 
  delay(300);        // So...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500); 
  tone(buzzer, 384); 
  delay(300);        // So...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500); 
  tone(buzzer, 341.3); 
  delay(300);        //Fa ...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sec
  tone(buzzer, 320); 
  delay(300);        // Mi...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500); 
  tone(buzzer, 288); 
  delay(300);        // Re...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500); 

  tone(buzzer, 256); 
  delay(300);        // Do...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500); 
  tone(buzzer, 256); 
  delay(300);        // Do...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500); 
   tone(buzzer, 288); 
  delay(300);        // Re...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500); 
   tone(buzzer, 320); 
  delay(300);        // Mi...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500);

   tone(buzzer, 288); 
  delay(400);        // Re...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500); 
  tone(buzzer, 256); 
  delay(250);        // Do...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(10);        // ...for 1sectone(buzzer, 500); 
    tone(buzzer, 256); 
  delay(250);        // Do...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(1000);        // ...for 1sectone(buzzer, 500); 

delay(3000);
}

else {
Serial.println(" Access denied");

lcd.setCursor(3,0);
lcd.print("Leave or I'll ");
lcd.setCursor(2,1);
lcd.print("call the police.");


    tone(buzzer, 384); 
  delay(300);        // So...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500); 
    tone(buzzer, 384); 
  delay(300);        // So...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500); 
    tone(buzzer, 384); 
  delay(300);        // So...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sectone(buzzer, 500); 
    tone(buzzer, 311); 
  delay(600);        // Mi...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(1000);        // ...for 1sectone(buzzer, 500);
    tone(buzzer, 341.3); 
  delay(300);        //Fa ...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sec
    tone(buzzer, 341.3); 
  delay(300);        //Fa ...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sec
    tone(buzzer, 341.3); 
  delay(300);        //Fa ...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sec
    tone(buzzer, 288); 
  delay(600);        // Re...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(1000);        // ...for 1sectone(buzzer, 500); 

delay(3000);
}
}
