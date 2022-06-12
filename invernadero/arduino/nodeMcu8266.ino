// Made by Jesus Tello @800869 in GitHub
// Agradecimientos a GitHub Copilot por documentar el codigo linea por linea :D

#include "SPI.h" // Libreria para la comunicacion SPI

void setup() {
   digitalWrite(SS, HIGH);  
   SPI.begin();
   SPI.setClockDivider(SPI_CLOCK_DIV4);
}
 
void loop() {
   char c;
   digitalWrite(SS, LOW); 
   for (const char * p = "Prueba de comunicacionn\r" ; c = *p; p++) 
   {
      SPI.transfer(c);
   }
   digitalWrite(SS, HIGH); 
   delay(2000);
}