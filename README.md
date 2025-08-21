# Arduino Reaction Game 🎮💡

This is a simple reaction time game built with **Arduino** and an **RGB LCD Shield**.  
The game measures how fast you can press a button after an LED lights up.

---

## 🔧 Features
- Randomized LED delay (1–5 seconds)  
- LCD prompts: *"Get Ready..."* → *"Press the button!"*  
- Calculates and displays your reaction time in milliseconds  
- Supports multiple rounds with average reaction time calculation  
- Early button press detection with a scrolling penalty message  

---

## 🖥️ Hardware Used
- Arduino Uno (compatible board works too)  
- RGB LCD Shield (I²C connection via `Wire.h` and `rgb_lcd.h`)  
- Push button  
- LED  

---

## 📜 How It Works
1. The LCD displays **"Get Ready..."**.  
2. After a random delay, the LED turns on and the LCD shows **"Press the button!"**.  
3. When the button is pressed, the LCD displays your reaction time in milliseconds.  
4. The game repeats for multiple rounds, then shows your **average reaction time**.  
5. If you press too early, you get a **100 ms penalty** with a scrolling LCD warning message.  

---

## 🚀 Getting Started
1. Clone this repository:  
   ```bash
   git clone https://github.com/eesh4n/arduino-reaction-game.git
