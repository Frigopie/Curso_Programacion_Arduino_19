#include <Wire.h>
#include <LiquidCrystal_I2C.h>


#define PIN_BOTON_A 2

  int a = 0;
   int pulsos_a = 0;

  boolean anterior_a;
  boolean  anterior_b;


LiquidCrystal_I2C lcd(0x3F, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display

#include <Servo.h>
Servo miservo;

#define PIN_SERVO 9


void setup() {
   Serial.begin(9600);
      Serial.println(F("Inicializando pantalla..."));
 lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Inicializando...");
  delay(200);
  lcd.clear();

  miservo.attach(PIN_SERVO);
  boolean anterior_a = digitalRead(PIN_BOTON_A);
}

void loop() {

boolean estado_a = digitalRead(PIN_BOTON_A);
  
  if (anterior_a != estado_a) {
      if (estado_a == LOW ) {  //flanco descendente pull-up
        Serial.println(F("Pulsado boton A"));
        pulsos_a++;
        
        if (a>160){
      a=0;}
        
        a=a+10;
        lcd.setCursor(0, 0);
        Serial.println("Numero pulsaciones boton A: " + (String)pulsos_a);
        
        lcd.print("Boton A   "+(String)pulsos_a);
       delay(100);
      }
    }
    
 
  
  miservo.write(a);
  delay(20);
  
anterior_a = estado_a;
lcd.setCursor(0, 1);
lcd.print("Grados "+(String)a);
lcd.print((char)223);


}
