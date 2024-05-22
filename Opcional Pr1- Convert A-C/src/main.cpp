#include <Arduino.h>

const int pinADC = 34; // Pin de entrada ADC
const int pinDAC = 25; // Pin de salida DAC
const int pinSerialTx = 1; // Pin TX del puerto serie

void setup() {
  Serial.begin(9600);
  
  pinMode(pinADC, INPUT);
  pinMode(pinDAC, OUTPUT);
}

void loop() {
  int valorADC = analogRead(pinADC);
  
  Serial.print("Valor ADC: ");
  Serial.println(valorADC);

  dacWrite(pinDAC, valorADC >> 2); 
  
  delay(1000); 