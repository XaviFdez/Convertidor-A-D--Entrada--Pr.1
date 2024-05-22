# Parte adicional - Práctica 1: Convertidor A/D
En esta parte complementaria de la práctica se pide:
   - leer el valor de un convertidor A/D de entrada ; sacarlo por el puerto serie y sacar el mismo valor por otro pin D/A
## Código: 
```c++
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
```
### Explicación del codigo:
 Se definen tres constantes que representan los números de pin del ADC (entrada analógica), el DAC (salida analógica) y el pin del puerto serie utilizado para enviar datos.
 
 *Función setup():* Esta función se ejecuta una vez al inicio del programa. Aquí se inicia la comunicación serial a una velocidad de 9600 baudios (Serial.begin(9600)).
 
 *Función loop():*
- lee el valor analógico del pin ADC utilizando analogRead(pinADC), que devuelve un valor entre 0 y 4095 (ya que el ESP32 tiene un ADC de 12 bits).
- El valor leído se envía a través del puerto serie utilizando Serial.print() y Serial.println(), lo que lo hace visible para el usuario en el monitor serie.
- El valor también se envía al pin DAC usando dacWrite(pinDAC, valorADC >> 2)
- Finalmente, se realiza una pausa de 1000 milisegundos (1 segundo) utilizando delay(1000).

