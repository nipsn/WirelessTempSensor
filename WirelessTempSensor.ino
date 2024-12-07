/* Arduino version */
#include "led.hpp"
#include "temperature.hpp"

#define PAUSE 100

uint32_t counter = 0;

void setup()
{
    LED_Init();
    Serial.begin(9600);
    temperature_init();
}

void loop()
{
    float temper;

    temper = temperature_read();
    Serial.print(temper);
    Serial.println(" °C");

    if (temper > 24.0)
    {
        LED_On();
    }
    else
    {
        LED_Off();
    }

    delay(2000);
}
