const int tempPin = A0;
const int ledPin = 8;
const int buzzerPin = 9;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  int sensorValue = analogRead(tempPin);

  float voltage = sensorValue * (5.0 / 1023.0);

  float temperature = (voltage - 0.5) * 100;

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");

  if (temperature >= 30) {

    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, 1000);

  } else {

    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);
  }

  delay(500);
}
