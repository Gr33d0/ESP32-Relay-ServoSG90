#include <ESP32Servo.h>

#define RELAY_PIN 16

Servo meuServo;
void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW); // Relé desligado no início
  meuServo.attach(17);
  Serial.begin(115200);
  
}

void loop() {



  // Liga o relé
  digitalWrite(RELAY_PIN, HIGH);
   delay(500);

  // Verifica o estado atual
  int estado = digitalRead(RELAY_PIN);

  Serial.print("Estado do relé: ");
  Serial.println(estado == HIGH ? "LIGADO" : "DESLIGADO");
  meuServo.write(0);    // Vai para 0 graus
  delay(1000);
  meuServo.write(90);   // Vai para 90 graus
  delay(1000);
  meuServo.write(180);  // Vai para 180 graus
  delay(1000);
    meuServo.write(0);  // Vai para 180 graus
  delay(1000);
  digitalWrite(RELAY_PIN, LOW);
 delay(1000);

  // Verifica novamente
  estado = digitalRead(RELAY_PIN);
  Serial.print("Estado do relé: ");
  Serial.println(estado == HIGH ? "LIGADO" : "DESLIGADO");
  delay(1000);
}
