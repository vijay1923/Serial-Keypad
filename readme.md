# 🔢 ESP32 Keypad to Serial1

This sketch reads a **4x3 matrix keypad** on an ESP32 and forwards key presses to:

- `Serial` (USB debug monitor at 115200)
- `Serial1` (UART at 9600 baud, TX=`GPIO17`, RX=`GPIO16`)

It also drives an LED on `GPIO23` for status feedback.

---

## ⚙️ Current behavior (from `keypad_rgb.ino`)

- Reads keypad events using the `Keypad` library.
- Accepts one key press per press/release cycle (prevents repeats while held).
- Applies software debounce: **200 ms**.
- On valid key press:
  - Sends key char to `Serial` and `Serial1`.
  - LED stays **ON** while key is considered held.
- When no key is held:
  - LED blinks every **200 ms**.
- If key is `Enter` (`0x0A`), the ESP32 restarts with `ESP.restart()`.

---

## 🔌 Wiring used in this sketch

### Keypad pins

| Keypad line | ESP32 pin |
|-------------|-----------|
| Row 1       | GPIO 21   |
| Row 2       | GPIO 19   |
| Row 3       | GPIO 18   |
| Row 4       | GPIO 32   |
| Column 1    | GPIO 33   |
| Column 2    | GPIO 25   |
| Column 3    | GPIO 26   |
| Column 4    | GPIO 21   |

### Other signals

| Signal   | ESP32 pin |
|----------|-----------|
| LED      | GPIO 23   |
| UART TX1 | GPIO 17   |
| UART RX1 | GPIO 16   |

---

## 🧩 Key map

The configured 4x3 layout is:

| Row\Col | C1  | C2   | C3    |
|---------|-----|------|-------|
| R1      | `1` | `2`  | `3`   |
| R2      | `4` | `5`  | `6`   |
| R3      | `7` | `8`  | `9`   |
| R4      | `*` | `0`  |`Enter`|

> Note: In this code, `*` is transmitted like any other key (no special backspace logic implemented yet).

---

## Components used
- ESP32 development board (e.g., ESP32 DevKitC)
- 4x4 matrix keypad (e.g., KY-016)
- LED (optional, for status indication)
- TTL to RS232 Module (for connecting `Serial1` to a PC or other device)

## 🖲️ Reset notes

- **Software reset:** pressing `Enter` triggers `ESP.restart()`.
- **Hardware reset:** pressing the ESP32 **EN** button resets the board at hardware level.

---

## 📚 Dependencies

- Arduino core for ESP32
- `Keypad` library (`#include <Keypad.h>`)

---

