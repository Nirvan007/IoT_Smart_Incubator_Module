#include <Wire.h>
#include "MAX30100_PulseOximeter.h"
#define BLYNK_PRINT Serial
#include <Blynk.h>
#include <ESP8266WiFi.h> 
#include <BlynkSimpleEsp8266.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 16, 2);

#define REPORTING_PERIOD_MS 1000

 
char auth[] = "4q6j6DSlo6B9gVvmLfmzxsY2a5nBrv9Q";             
char ssid[] = "AVANI";        
char pass[] = "avaninu123";        
 

PulseOximeter pox;
 
float BPM, SpO2;
uint32_t tsLastReport = 0;
int Buzzer = 13;
 
 
void setup()
{
    Serial.begin(115200);
    pinMode(Buzzer, OUTPUT);
    pinMode(16, OUTPUT);
    Blynk.begin(auth, ssid, pass);
    Wire.begin(D2, D1);
    lcd.begin();
    lcd.backlight();
    lcd.setCursor(3, 0);
    lcd.print("Powered on");
    delay(3000);
    lcd.clear();
    lcd.setCursor(2, 1);
    lcd.print("Initializing..");
    delay(2000);
    lcd.clear();
    lcd.setCursor(4, 0);
    lcd.print("IoT");
    lcd.setCursor(8, 0);
    lcd.print("Based");
    lcd.setCursor(2, 1);
    lcd.print("Smart Warmer");
    delay(3000);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("Designed and");
    lcd.setCursor(3, 1);
    lcd.print("Created by");
    delay(2000);
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("Nirvan");
    lcd.setCursor(8, 0);
    lcd.print("Tamhane,");
    delay(3000);
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("Smita");
    lcd.setCursor(7, 0);
    lcd.print("Trivedi,");
    delay(2000);
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("Dev");
    lcd.setCursor(7, 0);
    lcd.print("Patel,");
    lcd.setCursor(6, 1);
    lcd.print("And");
    delay(1500);
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("Dhruv");
    lcd.setCursor(7, 0);
    lcd.print("Bhansali");
    delay(1500);
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("Displaying");
    lcd.setCursor(2, 1);
    lcd.print("BPM and SpO2");
    delay(2000);
    lcd.clear();
    Serial.print("Initializing Pulse Oximeter..");
 
    if (!pox.begin())
    {
         Serial.println("FAILED");
         for(;;);
    }
    else
    {
         Serial.println("SUCCESS");
    }
 
}
 
void loop()
{
    pox.update();
    Blynk.run();
 
    BPM = pox.getHeartRate();
    SpO2 = pox.getSpO2();
    
   if (millis() - tsLastReport > REPORTING_PERIOD_MS)
    {
        Serial.print("Heart rate:");
        Serial.print(BPM);
        Serial.print(" SpO2:");
        Serial.print(SpO2);
        Serial.println(" %");

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("BPM: ");
        lcd.setCursor(10, 0);
        lcd.print(pox.getHeartRate());
        lcd.setCursor(0, 1);
        lcd.print("SpO2:");
        lcd.setCursor(10, 1);
        lcd.print(pox.getSpO2());
        lcd.setCursor(14, 1);
        lcd.print("%");
 
        Blynk.virtualWrite(V1, BPM);
        Blynk.virtualWrite(V2, SpO2);

        if(BPM < 50)
        {
          digitalWrite(Buzzer, HIGH);
          Serial.println("Low Heart Rate detected!");
        }
        else if(SpO2 < 90)
        {
          digitalWrite(Buzzer, HIGH);
          Serial.println("Low Oxygen Saturation detected!");
        }
        else if(BPM > 130)
        {
          digitalWrite(Buzzer, HIGH);
          Serial.println("High Heart Rate detected!");
        }
        else 
        {
          digitalWrite(Buzzer, LOW);
          Serial.println("Heart Rate is normal");
          Serial.println("Oxygen Saturation is normal");
        }

        Serial.println("________x________x________");
 
        tsLastReport = millis();
    }
}
