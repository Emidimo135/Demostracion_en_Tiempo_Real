#include "HX711.h"

// Pines para la conexión del HX711
const int LOADCELL_DOUT_PIN = 5; // Pin D5 de la ESP32
const int LOADCELL_SCK_PIN = 6;  // Pin D6 de la ESP32

HX711 scale;

void setup() {
  Serial.begin(115200);
  // Inicializa el sensor HX711
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  
  // Si quieres realizar una tara automática, puedes descomentar la siguiente línea:
  // scale.set_scale();
  // scale.tare();  // Resetea la balanza al valor 0
}

void loop() {
  // Verifica si hay una nueva lectura disponible
  if (scale.is_ready()) {
    long reading = scale.read();  // Lee el valor bruto
    Serial.print("Lectura del sensor: ");
    Serial.println(reading);
  } else {
    Serial.println("Esperando al sensor...");
  }
  
  delay(1000);  // Lee cada segundo
}
