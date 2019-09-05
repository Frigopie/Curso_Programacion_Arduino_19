
#define PIN_LDR A1

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
 Serial.println(F("Preparando lectura de LDR"));
}
int maximo = 0;
  int minimo = 3500;

void loop() {
  
int ValorLDR=analogRead(PIN_LDR);

if (maximo<ValorLDR){
  maximo=ValorLDR;
}
if (minimo>ValorLDR){
 minimo=ValorLDR;
}


Serial.println(ValorLDR);
     Serial.print(",");
    Serial.print(maximo);
    Serial.print(",");
    Serial.println(minimo);
delay(200);


}
