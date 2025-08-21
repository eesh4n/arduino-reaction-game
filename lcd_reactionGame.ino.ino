#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int led = 7;
const int button = 2; 

long ledOnTime;
bool ledOn = false;
bool waiting = false;
long delayTime;

int roundCount = 0;
int numRounds = 3;
int avgscore = 0;


void setup() {

// setup pins

    pinMode(led, OUTPUT);
    pinMode(button, INPUT);
    Serial.begin(9600);

// set up the game with LCD text 

    lcd.begin(16, 2);
    lcd.setCursor(2, 0);
    lcd.setColorWhite();
    lcd.print("Reaction Game");
    delay(5000);
}

void loop() {

    if (roundCount < numRounds) {

        unsigned long currentTime = millis();

        // if we are not waiting, turn on a new random wait 

        if (!waiting && !ledOn) {

            int randTime = random(1000, 5000);
            delayTime = currentTime + randTime;
            lcd.clear();
            lcd.setCursor(2, 0);
            lcd.print("Get ready...");
            waiting = true;

        }

        if (digitalRead(button) == HIGH && waiting) {

            for (int j = 0; j < 25; j++) {

            lcd.setCursor(0, 0);
            lcd.print("  Too early. Try again.");
            lcd.scrollDisplayLeft();
            delay(200);
 
                }

            waiting = false;
            avgscore += 100;


            }
        
        // turn on a LED at a random time interval
        
        if (waiting && currentTime >= delayTime) {

            digitalWrite(led, HIGH);
            waiting = false;
            ledOn = true;
            ledOnTime = currentTime;
            lcd.clear();
            lcd.print("Press the button!");
            lcd.setRGB(0, 255, 0);

        }

        // display reaction time 

        if (ledOn && digitalRead(button) == HIGH) {

            digitalWrite(led, LOW);
            ledOn = false;
            long reactionTime = currentTime - ledOnTime;

            lcd.clear();
            lcd.setCursor(2, 0);
            lcd.print("Reaction Time:");
            lcd.setCursor(2, 1);
            lcd.print(reactionTime);
            lcd.print(" ms");
            delay(3000);
            lcd.clear();
            roundCount ++;
            avgscore += reactionTime;

        }
    }

    else {

        long score = avgscore / numRounds;

        lcd.setCursor(0, 0);
        lcd.print("  Your average reaction time is: ");
        lcd.scrollDisplayLeft();
        lcd.print(score);
        lcd.print(" ms");
        delay(250);
    }

}
