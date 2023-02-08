#include <NewPing.h>  // Ultraschall

#define LED_PIR_PIN 6  // led pin
#define PIR_PIN 14     // pir sensor pin
#define TRIG_PIN 5     // sonar trigger pin
#define ECHO_PIN 4     // sonar echo pin
#define MAX_DIST 400   // sonar maximal distance

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DIST);  // initialize NewPing.h

void setup() {
  pinMode(LED_PIR_PIN, OUTPUT);
  pinMode(PIR_PIN, INPUT_PULLDOWN);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  Serial.begin(115200);
}

void loop() {
  delay(50);
  unsigned int distanceCM = sonar.ping_cm();
  Serial.print(distanceCM);
  Serial.println("cm");

  int read_pir = digitalRead(PIR_PIN);

  if (read_pir == 1) {
    // Serial.println(read_pir);
    digitalWrite(LED_PIR_PIN, HIGH);
    delay(50);

  } else {
    // Serial.println(read_pir);
    digitalWrite(LED_PIR_PIN, LOW);
    delay(50);
  }
}
