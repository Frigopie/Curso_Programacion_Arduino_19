#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#include <Servo.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display

#include <Servo.h>
Servo miservo;

#define PIN_POT A0
#define PIN_SERVO 9
int pot;
int ant_pot;
void setup() {
   Serial.begin(9600);
      Serial.println(F("Inicializando pantalla..."));
 lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Inicializando...");
  delay(200);
  lcd.clear();
int ant_pot;

  miservo.attach(PIN_SERVO);
}

void loop() {
 Serial.println(analogRead(PIN_POT));
int pot=analogRead(PIN_POT);
delay(100);
int pot_10=pot/20; // Para que no parpadee mucho 
int servpot = map(pot, 0, 1023, 10, 170);
  
  miservo.write(servpot);
  delay(20);
 

if(ant_pot != pot_10)
{
delay(100);
lcd.clear();
ant_pot=pot_10;
}

lcd.setCursor(0, 0);
lcd.print("POT "+(String)pot);
lcd.setCursor(0, 1);
lcd.print("Grados "+(String)servpot);
lcd.print((char)223);


}
