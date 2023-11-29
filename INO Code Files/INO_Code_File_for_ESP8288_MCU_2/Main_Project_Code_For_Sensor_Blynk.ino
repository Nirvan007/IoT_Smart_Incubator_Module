#include <Wire.h>
#define BLYNK_PRINT Serial
#include <Blynk.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include "DHT.h"


#define DHTTYPE DHT11
#define DHTPIN 14 //D5 pin
#define DS18B20 2 //D4 pin
#define REPORTING_PERIOD_MS 1000

DHT dht(DHTPIN, DHTTYPE);;
OneWire oneWire(DS18B20);
DallasTemperature sensors(&oneWire);

int Buzzer1 = 13;
int Buzzer2 = 15;
 
char auth[] = "HiDL_Svy8QeD3RJ-DcSs0Wk6wlfdNVW1";             
char ssid[] = "Nirvan";        
char pass[] = "nirvan007";        
 
 
float bodytemp, bodytempF, temp, humidity, PPM, AQI;
uint32_t tsLastReport = 0;
 
 
void setup()
{
    Serial.begin(115200);
    Blynk.begin(auth, ssid, pass);
    dht.begin();
    pinMode(Buzzer1, OUTPUT);
    pinMode(Buzzer2, OUTPUT);
}
 
void loop()
{
    Blynk.run();
    
    sensors.requestTemperatures();
    
   if (millis() - tsLastReport > REPORTING_PERIOD_MS)
    {
        temp = dht.readTemperature();
        humidity = dht.readHumidity();
        
        bodytemp = sensors.getTempCByIndex(0);
        bodytempF = (bodytemp*9.0)/5.0+32;
        PPM = analogRead(A0);
        AQI = (PPM/1000)*100;

        Serial.print("Body Temperature: ");
        Serial.print(bodytempF);
        Serial.println("°F");

        if(bodytempF > 98.6)
        {
          Serial.println("Body Temperature: High Body Temperature");
        }
        else 
        {
          Serial.println("Body Temperature: Normal");
        }
        
        Serial.print("Room Temperature: ");
        Serial.print(temp);
        Serial.println("°C");

        if(temp > 37.5)
        {
          Serial.println("Room Temperature: High Ambient Temperature");
        }
        else
        {
          Serial.println("Room Temperature: Normal");
        }

        Serial.print("Room Humidity: ");
        Serial.print(humidity);
        Serial.println("%");

       if(humidity >= 90)
        {
          Serial.println("Room Humidity: High Ambient Humidity");
        }
        else
        {
          Serial.println("Room Humidity: Normal");
        }


        Serial.print("AQI: ");
        Serial.print(AQI);
        Serial.println("%");

        if(PPM >= 700 && PPM <= 750)
        {
          Serial.println("Air Quality: Slightly Impure");
        }
        else if(PPM >= 800)
        {
          Serial.println("Air Quality: Impure");
        }
        else
        {
          Serial.println("Air Quality: Good");
        }
       
        Serial.println("________x________x________");


        Blynk.virtualWrite(V3, temp);
        Blynk.virtualWrite(V4, humidity);
        Blynk.virtualWrite(V5, bodytempF);
        Blynk.virtualWrite(V6, AQI);
        
 
        tsLastReport = millis();
    }

    if(bodytempF > 98.6)
        {
          digitalWrite(Buzzer1, HIGH);
          tone(Buzzer1, 5000, 500);
        }
        else 
        {
          digitalWrite(Buzzer1, LOW);
        }
        
    if(PPM >= 700)
        {
          digitalWrite(Buzzer2, LOW);
          delay(1000);
          digitalWrite(Buzzer2, LOW);
          delay(100);
        }
        else
        {
          digitalWrite(Buzzer2, LOW);
        } 
}
