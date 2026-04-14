# 🔢 ESP32 Keypad to Serial / Serial1

This sketch reads a **4x3 matrix keypad** on an ESP32 and forwards key presses to:

- `Serial` (USB debug monitor at 115200)
- `Serial1` (UART at 9600 baud, TX=`GPIO4`, RX=`GPIO0`)

It also drives an LED on `GPIO23` for status feedback.

---

## ⚙️ Current behavior (from `keypad_rgb.ino`)

- Reads keypad events using the `Keypad` library.
- Uses one key press per press/release cycle (`keyHeld` logic prevents repeats while held).
- Applies software debounce: **200 ms**.
- On valid key press:
  - Sends key character to `Serial` and `Serial1`.
  - If data is available on `Serial1`, reads one byte and prints it to `Serial` as echoed feedback.
  - LED stays **ON** while key is considered held.
- When no key is held:
  - LED blinks every **200 ms**.
- If key is `0x0A` (Enter), the ESP32 restarts with `ESP.restart()`.

---

## 🔌 Wiring used in this sketch

### Keypad pins (4x3)

| Keypad line | ESP32 pin |
|-------------|-----------|
| Row 1       | GPIO 32   |
| Row 2       | GPIO 33   |
| Row 3       | GPIO 25   |
| Row 4       | GPIO 26   |
| Column 1    | GPIO 21   |
| Column 2    | GPIO 18   |
| Column 3    | GPIO 19   |

### Other signals

| Signal   | ESP32 pin |
|----------|-----------|
| LED      | GPIO 23   |
| UART TX1 | GPIO 4    |
| UART RX1 | GPIO 0    |

> Note: Alternate UART/keypad pin mappings are present in comments inside the sketch but are currently disabled.

---

## 🧩 Key map

The configured 4x3 layout is:

| Row\Col | C1  | C2  | C3      |
|---------|-----|-----|---------|
| R1      | `1` | `2` | `3`     |
| R2      | `4` | `5` | `6`     |
| R3      | `7` | `8` | `9`     |
| R4      | `*` | `0` | `0x0A`  |

---

## Components used

- ESP32 development board (e.g., ESP32 DevKitC)
- 4x3 matrix keypad
- LED (optional, for status indication)
- UART/RS232 interface module (optional, if using `Serial1` externally)

---

## 🖲️ Reset notes

- **Software reset:** pressing the key mapped to `0x0A` triggers `ESP.restart()`.
- **Hardware reset:** pressing the ESP32 **EN** button resets the board.

---

## 📚 Dependencies

- Arduino core for ESP32
- `Keypad` library (`#include <Keypad.h>`)

---

