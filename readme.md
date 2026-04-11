# 🔢 Serial Keypad

This project allows you to connect a **4x3 matrix keypad** to an **ESP32** and send the pressed key values over **UART 16(RX),17(TX)** to another device.  
It includes **LED feedback**, **debounce handling (500 ms)**, **long-press prevention**, and an **auto-restart feature** when the **Enter key** or **EN push button** is pressed.

---

## ⚙️ Features

- ✅ Reads input from a **4x3 matrix keypad**
- ✅ Sends key values to:
  - **Serial Monitor (USB)**
  - **Serial1 (UART TX = 17, RX = 16)** for external communication
- ✅ LED (**GPIO 23**) stays ON while a key is pressed  
- ✅ Prevents repeated key input during long press  
- ✅ Debounce time of **500 ms**
- ✅ **Auto-restarts** ESP32 when:
  - The **Enter key** (`0x0A`) is pressed  
  - The **EN push button** is pressed (hardware reset)
- ✅ **Delete key** (`0x2A`) reserved for **backspace**

---

## 🧰 Hardware Connections

| Component           | ESP32 Pin | Description                     |
|---------------------|-----------|---------------------------------|
| R1 (Row 1)          | GPIO 32   | Keypad row 1                    |
| R2 (Row 2)          | GPIO 33   | Keypad row 2                    |
| R3 (Row 3)          | GPIO 25   | Keypad row 3                    |
| R4 (Row 4)          | GPIO 26   | Keypad row 4                    |
| C1 (Column 1)       | GPIO 27   | Keypad column 1                 |
| C2 (Column 2)       | GPIO 14   | Keypad column 2                 |
| C3 (Column 3)       | GPIO 12   | Keypad column 3                 |
| LED                 | GPIO 23   | LED feedback                    |
| UART TX             | GPIO 17   | Transmit to external device     |
| UART RX             | GPIO 16   | Receive from external device    |
| EN Pin              | EN PIN    | Connected to push button for reset |

---
## 🧩 Components Used

- **ESP32 Dev Module**
- **4x3 Matrix Keypad** with nameplate for keys
- **LED**
- **Push button** (connected to EN pin)
- **MAX232N 16-pin IC**
- **5 × 104 Capacitors**
- **Solenoid 4-pin male connector**
- **Enclosure box:** 160 mm × 100 mm × 85 mm
- **2 screws** for PCB  mounting
- **Acrylic sheet**
- **Connectors:**
  - 1 × 4-pin connector PCB Mounted
  - 1 × 8-pin connector PCB Mounted
  - 2 × 2-pin connectors PCB Mounted
- **wires:**
  - 1 × 4-wire
  - 1 × 8-wire
  - 2 × 2-wire

## 🔌 Key Mapping

| Key              | Description                                 |
|------------------|---------------------------------------------|
| `1–9`, `0`       | Standard numeric keys                       |
| `*` (`0x2A`)     | Delete key (Backspace)                      |
| `Enter` (`0x0A`) | Triggers ESP32 restart                      |

---

## 🖲️ Manual Reset

- The **EN pin** is connected to a **momentary push button**.  
- When pressed, it **resets/restarts the ESP32** hardware — similar to     
  pressing the onboard reset button.  
- This provides a **quick manual way** to restart the system during   
  testing or deployment.

---

