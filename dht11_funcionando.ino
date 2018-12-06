#include "DHT.h"
 
// Uncomment whatever type you're using!
#define DHTTYPE DHT11   // DHT 11
#include  <LiquidCrystal.h>
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)
 
// Connect pin 1 (on the left) of the sensor to +5V
// NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1
// to 3.3V instead of 5V!
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor
 
const int DHTPin = 22;     // what digital pin we're connected to
const int sensorPin1 = A0;
const int sensorPin2 = A1;
const int sensorPin3 = A2;
DHT dht(DHTPin, DHTTYPE);
LiquidCrystal lcd2(7, 6, 5, 4, 3, 2);
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
 
void setup() {
   Serial.begin(9600);
   dht.begin();
   // INDICAMOS QUE TENEMOS CONECTADA UNA PANTALLA DE 16X2
  lcd.begin(16, 2);
  // MOVER EL CURSOR A LA PRIMERA POSICION DE LA PANTALLA (0, 0)
  lcd.home();
  // IMPRIMIR "Hola Mundo" EN LA PRIMERA LINEA
 //lcd.print("BIENVENIDO!");


  // MOVER EL CURSOR A LA SEGUNDA LINEA (1) PRIMERA COLUMNA (0)
 // lcd.setCursor ( 0, 1 );
  // IMPRIMIR OTRA CADENA EN ESTA POSICION
//  lcd.print("GEEKFACTORY");
  // ESPERAR UN SEGUNDO
  delay(1000);
}
 
void loop() {
   // Wait a few seconds between measurements.
   delay(2000);
 
   // Reading temperature or humidity takes about 250 milliseconds!
   int h1 = dht.readHumidity();
   float t1 = dht.readTemperature();
 
   if (isnan(h1) || isnan(t1)) {
      Serial.println("Failed to read from DHT sensor!");
      return;
   }

    int humedad1 = analogRead(sensorPin1);
    int humedad2 = analogRead(sensorPin2);
    int humedad3 = analogRead(sensorPin3);
  
   if(humedad1 < 500)
   {
      Serial.println("Encendido");  
      //hacer las acciones necesarias
   }
   delay(1000);
   Serial.print("HS1: ");
   Serial.print(humedad1);
   Serial.print(" \t");
   Serial.print("HS2: ");
   Serial.print(humedad2);
   Serial.print(" \t");
   Serial.print("HS3: ");
   Serial.print(humedad3);
   Serial.print(" \t");
   Serial.print("HR: ");
   Serial.print(h1);
   Serial.print(" %\t");
   Serial.print("T: ");
   Serial.print(t1);
   Serial.print(" *C ");
   Serial.print(" %\n");

   // EN EL CICLO PRINCIPAL SOLAMENTE RECORREMOS EL MENSAJE DE UN LADO A OTRO
  // VARIABLE PARA CONTROL DE CICLOS
  //int i;

//  // DESPLAZAR LA PANTALLA A LA DERECHA 2 VECES
//  for ( int i = 0; i < 5; i++ ) {
//    lcd.scrollDisplayRight();
//    delay (1000);
//  }
//
//  // DESPLAZAR LA PANTALLA A LA IZQUIERDA 2 VECES
//  for ( int i = 0; i < 5; i++ ) {
//    lcd.scrollDisplayLeft();
//    delay (1000);
//  }


//  lcd.setCursor(0,0);
//  lcd.print("H1: ");
//  lcd.setCursor ( 0, 1 );
//  lcd.print(humedad1);
//    lcd.setCursor(5,0);
//  lcd.print("H2: ");
//  lcd.setCursor ( 5,1 );
//  lcd.print(humedad2);
//  lcd.setCursor ( 11,0 );
//  lcd.print("H3: ");
//  lcd.setCursor ( 11,1 );
//  lcd.print(humedad3);
//  
//respaldo para impresion de 4 magnitudes
  lcd.setCursor(0,0);
  lcd.print("H1: ");
  lcd.setCursor ( 3, 0 );
  lcd.print(humedad1);
  lcd.setCursor(9,0);
  lcd.print("H2: ");
  lcd.setCursor ( 12,0 );
  lcd.print(humedad2);
  lcd.setCursor ( 0,1 );
  lcd.print("H3: ");
  lcd.setCursor ( 3,1 );
  lcd.print(humedad3);
  lcd.setCursor ( 9,1 );
  lcd.print("HR1:");
  lcd.setCursor ( 13,1 );
  lcd.print(h1);
  lcd.setCursor ( 15,1 );
  lcd.print("%");
//segunda pantalla
  lcd2.setCursor(0,0);
  lcd2.print("H1: ");
  lcd2.setCursor ( 3, 0 );
  lcd2.print(humedad1);
//  lcd2.setCursor(9,0);
//  lcd2.print("H2: ");
//  lcd2.setCursor ( 12,0 );
//  lcd2.print(humedad2);
//  lcd2.setCursor ( 0,1 );
//  lcd2.print("H3: ");
//  lcd2.setCursor ( 3,1 );
//  lcd2.print(humedad3);

  
}
