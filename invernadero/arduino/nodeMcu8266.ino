// Made by Jesus Tello @800869 in GitHub :D

#include <Wire.h>
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "NodeMCU";       
const char* password = "123456789"; 

ESP8266WebServer server(80);

int h=0;
int t=0;
int h2=0;
int t2=0;
int luminosidad=0;
int humedadTierra=0;

char c;

void setup() {
  Serial.begin(9600);
  pinMode(D4, OUTPUT); 
  WiFi.softAP(ssid, password);

  IPAddress myIP = WiFi.softAPIP();
  
  server.begin();
}

void loop() {

  while (Serial.available() > 0) {
    c = Serial.read();

    if(c == 'A'){
      h = Serial.parseInt();
    }
    if(c == 'B'){
      t = Serial.parseInt();
    }
    if(c == 'C'){
      h2 = Serial.parseInt();
    }
    if(c == 'D'){
      t2 = Serial.parseInt();
    }
    if(c == 'E'){
      luminosidad = Serial.parseInt();
    }
    if(c == 'F'){
      humedadTierra = Serial.parseInt();
    }
  }
  
/////////////////////////////////////
   /*INCOMPLETO*/
/////////////////////////////////////
}
