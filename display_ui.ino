// ===============================

// Branch: feature/display-ui
// ===============================

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// -------------------------------
// DISPLAY CONFIG
// -------------------------------
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// -------------------------------
// MENU ITEMS
// -------------------------------
const char* menuItems[] = {
  "View Parameters",
  "Temp Settings",
  "Humidity Settings",
  "Voltage Settings"
};

const int menuLength = sizeof(menuItems) / sizeof(menuItems[0]);
int menuIndex = 0;

// External values (will come from Member 1 & 3 later)
float temperature = 25.0f;
float humidity = 60.0f;
float voltage = 3.3f;

// ===============================
// SETUP
// ===============================
void setup() {
  Serial.begin(115200);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED FAILED");
    while (true);
  }

  display.clearDisplay();
  display.display();
}

// ===============================
// MAIN LOOP
// ===============================
void loop() {
  renderMenu();
  delay(150);
}

// ===============================
// MAIN MENU RENDERING
// ===============================
void renderMenu() {
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setTextWrap(false);

  // Title
  display.setCursor(0, 0);
  display.println("MAIN MENU");

  display.println("----------------");

  // Menu list
  for (int i = 0; i < menuLength; i++) {
    if (i == menuIndex) {
      display.print("> ");   // highlight selection
    } else {
      display.print("  ");
    }

    display.println(menuItems[i]);
  }

  display.println("----------------");

  // Live sensor preview (UI feature)
  display.print("T:");
  display.print(temperature, 1);
  display.print(" H:");
  display.print(humidity, 1);

  display.print(" V:");
  display.println(voltage, 1);

  display.display();
}