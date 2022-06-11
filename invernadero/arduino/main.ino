// Made by Jesus Tello @800869 in GitHub
// Agradecimientos a GitHub Copilot por documentar el codigo linea por linea :D

#include <LiquidCrystal_I2C.h> // Libreria para el LCD
#include "DHT.h"   // Librería del sensor DHT

#define DHTPIN 9    // Pin del sensor DHT
#define DHTTYPE DHT11   // Definimos el tipo de sensor

DHT dht(DHTPIN, DHTTYPE);    // Creamos el objeto dht


LiquidCrystal_I2C lcd(0x27,20,4);  // Indicamos la direccion 0x27 que representa un LCD con 16 caracteres y 2 lineas

void setup()
{
  Serial.begin(9600);  // Iniciamos el puerto serie
  dht.begin();  // Inicializamos el sensor DHT
  
  lcd.init();  // Inicializamos el LCD
  lcd.backlight(); // Activamos el backlight
}


void loop()
{
  int h = dht.readHumidity();    // Definimos la variable h para almacenar el valor de humedad
  int t = dht.readTemperature();    // Definimos la variable t para almacenar el valor de temperatura

  Serial.print("Humedad: ");  // Imprimimos la palabra Humedad
  Serial.print(h); // Imprimimos el valor de humedad
  Serial.print(" % \t");  // Imprimimos % y un espacio
  Serial.print("Temperatura: ");  // Imprimimos la palabra Temperatura
  Serial.print(t);  // Imprimimos el valor de temperatura
  Serial.println(" C");  // Imprimimos C

  lcd.setCursor(0,0);  // Colocamos el cursor en la posicion 0,0
  lcd.print("Humedad: ");  // Imprimimos la palabra Humedad
  lcd.print(h);  // Imprimimos el valor de humedad
  lcd.print("%");  // Imprimimos %
  lcd.setCursor(0,1);  // Colocamos el cursor en la posicion 0,1
  lcd.print("Temp: ");  // Imprimimos la palabra Temp
  lcd.print(t);  // Imprimimos el valor de temperatura
  lcd.print((char)223);  // Imprimimos el simbolo de grados
  lcd.print("C");  // Imprimimos C
 
  delay(500);  // Esperamos 500 milisegundos
}
