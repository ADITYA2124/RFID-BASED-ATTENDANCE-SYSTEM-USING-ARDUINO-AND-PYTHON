#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <MFRC522.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define SS_PIN 10
#define RST_PIN 9
#define green 2
#define red 3
#define BUZZER 4
MFRC522 rfid(SS_PIN, RST_PIN);

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET    -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
   pinMode(red, OUTPUT);
   pinMode(green, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  noTone(BUZZER);
  // Start serial communication
  Serial.begin(9600);
  while (!Serial) {
    ; // Wait for serial port to connect
  }

  // Initialize the OLED display
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  
  // Clear the buffer
  display.clearDisplay();

  // Set text size
  display.setTextSize(1);      // Normal 1:1 pixel scale
  // Set text color
  display.setTextColor(SSD1306_WHITE); // Draw white text
  // Set cursor position
  display.setCursor(0,0);     // Start at top-left corner
  
  // Display text
  display.println(F("Ready to read RFID!"));
  
  // Display everything on the screen
  display.display();

  // Initialize RFID reader
  SPI.begin();
  rfid.PCD_Init();
  Serial.println(F("RFID reader ready"));
}

void loop() {
  // Look for new cards
  if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
    Serial.print("Card UID: ");
    for (byte i = 0; i < rfid.uid.size; i++) {
      Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
      Serial.print(rfid.uid.uidByte[i], HEX);
    }
    Serial.println();
    
    // Display UID on OLED
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println(F("Card UID:"));
    for (byte i = 0; i < rfid.uid.size; i++) {
      display.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
      display.print(rfid.uid.uidByte[i], HEX);
    }
    display.display();

    // Send UID over serial
    for (byte i = 0; i < rfid.uid.size; i++) {
      Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
      Serial.print(rfid.uid.uidByte[i], HEX);
    }
    Serial.println();
    
    delay(1000);
    display.clearDisplay();
  }

  // Check for incoming serial data
  if (Serial.available() > 0) {
    String x = Serial.readStringUntil('\n'); 
    if(x=="1"){
    digitalWrite(green,HIGH);
    delay(1000);
    digitalWrite(green,LOW);
    }
    else if(x=="0")
    {
      digitalWrite(red,HIGH);
      tone(BUZZER, 300);
      delay(1000);
     digitalWrite(red,LOW);
     noTone(BUZZER);
    }
    String name = Serial.readStringUntil('\n');
    //display.clearDisplay();
    display.setCursor(0, 0);
    display.println(F("Employee Name:"));
    display.println(name);
    display.display();
    delay(2000); // Display for 2 seconds
    display.clearDisplay();
    display.display();
    display.setCursor(0, 0);
    display.println(F("Card UID:"));
    display.display();
    
    
  }

  delay(500); // Delay between readings
}
