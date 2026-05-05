// ----------- PIN DEFINITIONS -----------
#define TEMP_PIN A1
#define GAS_PIN A0
#define VIB_PIN 3
#define TILT_PIN 4

#define GREEN 11
#define RED 13

// ----------- SETUP -----------
void setup() {
  Serial.begin(9600);

  pinMode(VIB_PIN, INPUT_PULLUP);
  pinMode(TILT_PIN, INPUT_PULLUP);

  pinMode(GREEN, OUTPUT);
  pinMode(RED, OUTPUT);
}

// ----------- LOOP -----------
void loop() {

  // 🌡️ Temperature (TMP36)
  int tempReading = analogRead(TEMP_PIN);
  float voltage = tempReading * (5.0 / 1023.0);
  float temperature = (voltage - 0.5) * 100;

  // ⛽ Gas
  int gas = analogRead(GAS_PIN);

  // 📳 Vibration
  int vibration = digitalRead(VIB_PIN);

  // 🧱 Tilt (Stress)
  int tilt = digitalRead(TILT_PIN);

  // ----------- DISPLAY DATA -----------
  Serial.println("------ SENSOR DATA ------");

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Gas Level: ");
  Serial.println(gas);

  Serial.print("Vibration: ");
  Serial.println(vibration == LOW ? "DETECTED" : "NORMAL");

  Serial.print("Stress (Tilt): ");
  Serial.println(tilt == LOW ? "TILTED" : "STABLE");

  // ----------- RESET LEDs -----------
  digitalWrite(GREEN, LOW);
  digitalWrite(RED, LOW);

  // ----------- ALERT LOGIC -----------

  // 🔴 DANGER
  if (temperature > 45 || gas > 700 || vibration == LOW || tilt == LOW) {
    digitalWrite(RED, HIGH);
    Serial.println("🔴 STATUS: DANGER!");
  }



  // 🟢 SAFE
  else {
    digitalWrite(GREEN, HIGH);
    Serial.println("🟢 STATUS: SAFE");
  }

  Serial.println("--------------------------------\n");

  delay(2000);
}
