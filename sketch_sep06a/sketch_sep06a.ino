//Librerías pantalla LCD
#include <Wire.h>
#include <LiquidCrystal_I2C.h>


#define PIN_BOTON_A 2
#define PIN_BOTON_B 3

  int pulsos_a = 0;
  int pulsos_b = 0;

LiquidCrystal_I2C lcd(0x3F, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display
 
  boolean anterior_a;
  boolean  anterior_b;

void setup() {
  
  pinMode(PIN_BOTON_A, INPUT_PULLUP);
  pinMode(PIN_BOTON_B, INPUT);
    
    Serial.begin(9600);
      Serial.println(F("Inicializando pantalla..."));

    boolean anterior_a = digitalRead(PIN_BOTON_A);
    boolean anterior_b = digitalRead(PIN_BOTON_B);
    
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Inicializando...");
  delay(200);
  lcd.clear();
 
}

void loop() {
    
    boolean estado_a = digitalRead(PIN_BOTON_A);
    boolean estado_b = digitalRead(PIN_BOTON_B);
  

    if (anterior_a != estado_a) {
      if (estado_a == LOW ) {  //flanco descendente pull-up
        Serial.println(F("Pulsado boton A"));
        pulsos_a++;
        lcd.setCursor(0, 0);
        Serial.println("Numero pulsaciones boton A: " + (String)pulsos_a);
        
        lcd.print("Boton A    "+(String)pulsos_a);
       delay(200);
      }
    }

    if (anterior_b != estado_b) {
      if (estado_b == HIGH) {  //flanco ascendente pull-down
        Serial.println(F("Pulsado boton B"));
        pulsos_b++;
        Serial.println("Numero pulsaciones boton B: " + (String)pulsos_b);
        lcd.setCursor(0, 1);
        lcd.print("Boton B  "+(String)pulsos_b);
        delay(200);
      }
    }
    anterior_a = estado_a;
    anterior_b = estado_b; 
    delay(50); //Evitar rebotes
  }
 
  
