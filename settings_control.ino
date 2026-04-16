// ===============================
// MEMBER 3: SETTINGS CONTROL
// ===============================

// Current values
float temp = 25;
float humidity = 60;
float voltage = 3.3;

// Limits
float tempLow = 20, tempHigh = 30;
float humLow = 40, humHigh = 70;
float voltLow = 3.0, voltHigh = 3.6;

// 0 = LOW, 1 = HIGH
int selectedSetting = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  simulateEncoderInput();
  delay(300);
}

// -------------------------------
// Simulated adjustment logic
// -------------------------------
void simulateEncoderInput() {

  int encoderDirection = 1; // change to -1 to decrease

  if (selectedSetting == 0) {
    tempLow += encoderDirection;
    Serial.print("Temp Low: ");
    Serial.println(tempLow);
  }
  else if (selectedSetting == 1) {
    tempHigh += encoderDirection;
    Serial.print("Temp High: ");
    Serial.println(tempHigh);
  }
}

// -------------------------------
// Switch between LOW / HIGH
// -------------------------------
void toggleSetting() {
  selectedSetting = !selectedSetting;
}
// Added comment for PR demonstration