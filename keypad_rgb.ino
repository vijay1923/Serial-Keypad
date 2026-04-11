#include <Arduino.h>
#include <Keypad.h>

#define LED 23
#define DEBOUNCE_TIME 100 

char keys[4][3] =
{
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
    {0x2A, '0', 0x0A}  
};

byte pin_rows[4] = {32, 33, 25, 26};
byte pin_column[3] = {27, 14, 12};

Keypad keypad = Keypad(makeKeymap(keys), pin_rows, pin_column, 4, 3);

unsigned long lastBlink = 0;
unsigned long lastPressTime = 0;
bool ledState = false;
bool keyHeld = false;

void setup()
{
    Serial.begin(115200);
    Serial1.begin(9600, SERIAL_8N1, 16, 17);
    pinMode(LED, OUTPUT);
    Serial.println("Welcome ESP32 Dev Module : Serial Keypad");
}

void loop()
{
    char key = keypad.getKey();
    byte state = keypad.getState();
    if (state == PRESSED && !keyHeld)
    {
        unsigned long now = millis();
        if (now - lastPressTime > DEBOUNCE_TIME)
        {
            keyHeld = true;
            lastPressTime = now;

            Serial.print(key);
            Serial1.print(key);

            if (key == 0x0A)
            {
                Serial.println("\nRestarting ESP32\n");
                delay(300);
                ESP.restart();
            }
        }
    }
    else if (state == RELEASED)
    {
        keyHeld = false;
    }
    if (keyHeld)
    {
        digitalWrite(LED, HIGH); 
    }
    else if (millis() - lastBlink >= 200)
    {
        lastBlink = millis();
        ledState = !ledState;
        digitalWrite(LED, ledState);  
    }
}