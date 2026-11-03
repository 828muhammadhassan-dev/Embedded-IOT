#include <Arduino.h>

#define DAC_PIN   25
#define PWM_PIN   16

// ESP32 standard core ke liye channel define karna zaroori hota hai
#define PWM_CHANNEL 0
#define PWM_FREQ    5000  // 5 kHz frequency
#define PWM_RES     8     // 8-bit resolution (0-255)

void setup()
{
  Serial.begin(115200);

  // 1. Channel ko configure karein (Frequency aur Resolution)
  ledcSetup(PWM_CHANNEL, PWM_FREQ, PWM_RES);

  // 2. Pin ko us channel ke sath attach karein
  ledcAttachPin(PWM_PIN, PWM_CHANNEL);
}

void loop()
{
  // DAC output code 128 (approx 1.65V)
  dacWrite(DAC_PIN, 128);

  // PWM duty cycle 128 (~50% duty cycle)
  ledcWrite(PWM_CHANNEL, 128);

  Serial.println("DAC=128 | PWM duty=128");
  delay(1000);
}