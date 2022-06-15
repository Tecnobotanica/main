// Made by Jesus Tello @800869 in GitHub :D

#include <LiquidCrystal_I2C.h>  // Libreria para el LCD
#include <SoftwareSerial.h>  // Libreria para mandar datos al NodeMCU
#include <Wire.h>  // Libreria para la comunicacion I2C
#include "DHT.h"   // Librería del sensor DHT

#define DHTPIN 9    // Pin del sensor DHT
#define DHT2PIN 8    
#define DHTTYPE DHT11   // Definimos el tipo de sensor
#define DHTTYPE DHT11   

const int Ldr_PIN = A1;   //Pin del LDR
const int Rele_PIN = 3;  //Pin del Rel
const int HumedadTierra_PIN = A0;  //Pin de la Humedad de la Tierra

int humedadTierra;
int luminosidad;
int DelayLCD = 1000;

DHT dht(DHTPIN, DHTTYPE);    // Creamos el objeto dht
DHT dht2(DHT2PIN, DHTTYPE);    // Creamos el objeto dht

SoftwareSerial monitorSerial(7,6); // 7 ->  RX  y  8 -> TX

LiquidCrystal_I2C lcd(0x27,20,4);  // Indicamos la direccion 0x27 que representa un LCD con 16 caracteres y 2 lineas

void setup(void) {
  
  monitorSerial.begin(9600);  // Iniciamos por que baudios se enviaran los datos al NodeMCU
  Serial.begin(9600);  // Iniciamos el puerto serie
 
  dht.begin();  // Inicializamos el sensor DHT
  dht2.begin();  

  pinMode(Rele_PIN, OUTPUT);  // Configuramos el pin del rele como salida
   
  lcd.init();  // Inicializamos el LCD
  lcd.backlight(); // Activamos el backlight
  }

void loop(void) {

  int h = dht.readHumidity();    // Definimos la variable h para almacenar el valor de humedad
  int t = dht.readTemperature();    // Definimos la variable t para almacenar el valor de temperatura
  int h2 = dht2.readHumidity();   
  int t2 = dht2.readTemperature();    

  luminosidad = analogRead(Ldr_PIN);  // Leemos el valor de la luminosidad
  luminosidad = map(luminosidad, 0, 1023, 0, 100);  // Transformamos el valor de la luminosidad a un valor entre 0 y 100

  humedadTierra = analogRead(HumedadTierra_PIN);  
  humedadTierra = map(humedadTierra, 0, 1023, 100, 0); 

  if(humedadTierra < 30 && luminosidad < 30) {  
  digitalWrite(Rele_PIN, HIGH);
  }
    else{
      digitalWrite(Rele_PIN, LOW);
    }
    
  lcd.setCursor(0,0);  // Colocamos el cursor en la posicion 0,0
  lcd.print("Humedad ");  // Imprimimos la palabra Humedad
  lcd.setCursor(0,1);  // Colocamos el cursor en la posicion 0,1
  lcd.print("interior: ");  // Imprimimos la palabra interior
  lcd.print(h);  // Imprimimos el valor de humedad
  lcd.print("%");  // Imprimimos %
  delay(DelayLCD);  // Esperamos un tiempo
  lcd.clear();  // Limpiamos el LCD
  lcd.setCursor(0,0);  
  lcd.print("Temperatura "); 
  lcd.setCursor(0,1);  
  lcd.print("interior: ");
  lcd.print(t);  
  lcd.print((char)223);  
  lcd.print("C");  
  delay(DelayLCD);  
  lcd.clear(); 
  lcd.setCursor(0,0);  
  lcd.print("Humedad "); 
  lcd.setCursor(0,1); 
  lcd.print("ambiental: ");
  lcd.print(h2);
  lcd.print("%");
  delay(DelayLCD); 
  lcd.clear(); 
  lcd.setCursor(0,0); 
  lcd.print("Temperatura "); 
  lcd.setCursor(0,1);
  lcd.print("ambiental: ");  
  lcd.print(t2); 
  lcd.print((char)223); 
  lcd.print("C");  
  delay(DelayLCD);  
  lcd.clear(); 
  lcd.setCursor(0,0);  
  lcd.print("Humedad "); 
  lcd.setCursor(0,1); 
  lcd.print("tierra: "); 
  lcd.print(humedadTierra);  
  lcd.print("%");  
  delay(DelayLCD);  
  lcd.clear(); 
  lcd.setCursor(0,0); 
  lcd.print("Luminosidad: "); 
  lcd.print(t2); 
  lcd.print("%"); 
  delay(DelayLCD); 
  lcd.clear();  

  monitorSerial.print('A');  // Enviamos el caracter A al NodeMCU
  monitorSerial.println(h);  // Enviamos el valor de humedad al NodeMCU
  
  monitorSerial.print('B');
  monitorSerial.println(t);
  
  monitorSerial.print('C');
  monitorSerial.println(h2);
  
  monitorSerial.print('D');
  monitorSerial.println(t2);
  
  monitorSerial.print('E');
  monitorSerial.println(luminosidad);
  
  monitorSerial.print('F');
  monitorSerial.println(humedadTierra);
}
