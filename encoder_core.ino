// ===============================
// MEMBER 1: ROTARY ENCODER CORE
// Branch: feature/encoder-core
// ===============================

#define CLK 32
#define DT 33
#define SW 25

int lastCLK;
int encoderValue = 0;
bool buttonPressed = false;

void setup() {
  Serial.begin(115200);

  pinMode(CLK, INPUT);
  pinMode(DT, INPUT);
  pinMode(SW, INPUT_PULLUP);

  lastCLK = digitalRead(CLK);
}

void loop() {
  handleEncoder();
  handleButton();

  delay(5);
}

// -------------------------------
// Detect rotation direction
// -------------------------------
void handleEncoder() {
  int currentCLK = digitalRead(CLK);

  if (currentCLK != lastCLK) {
    if (digitalRead(DT) != currentCLK) {
      encoderValue++;  // clockwise
      Serial.println("UP");
    } else {
      encoderValue--;  // counterclockwise
      Serial.println("DOWN");
    }

    Serial.print("Value: ");
    Serial.println(encoderValue);
  }

  lastCLK = currentCLK;
}

// -------------------------------
// Detect button press
// -------------------------------
void handleButton() {
  if (digitalRead(SW) == LOW) {
    delay(200); // debounce
    buttonPressed = true;
    Serial.println("BUTTON PRESSED");
  } else {
    buttonPressed = false;
  }
}
