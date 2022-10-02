#include <Arduino.h>
#include <EasyButton.h>

#define BUTTON_ONE_PIN D1
#define BUTTON_TWO_PIN D2

#define LED_Red D3
#define LED_Yellow D5
#define LED_Blue D6

#define BAUDRATE 9600

EasyButton button1(BUTTON_ONE_PIN);
EasyButton button2(BUTTON_TWO_PIN);

void onButton1Pressed()
{
  Serial.println("Button1 pressed");
  if (digitalRead(LED_Blue) == HIGH)
    digitalWrite(LED_Blue, LOW);
  else
    digitalWrite(LED_Blue, HIGH);
}

void onButton2Pressed()
{
  Serial.println("Button2 pressed");
  if (digitalRead(LED_Yellow) == HIGH)
    digitalWrite(LED_Yellow, LOW);
  else
    digitalWrite(LED_Yellow, HIGH);
}

void onPressedForDuration()
{
  Serial.println("Button pressed");
  if (digitalRead(LED_Red) == HIGH)
    digitalWrite(LED_Red, LOW);
  else
    digitalWrite(LED_Red, HIGH);
}

void setup()
{
  Serial.begin(BAUDRATE);

  pinMode(LED_Red, OUTPUT);
  pinMode(LED_Yellow, OUTPUT);
  pinMode(LED_Blue, OUTPUT);
  pinMode(BUTTON_ONE_PIN, INPUT_PULLUP);
  pinMode(BUTTON_TWO_PIN, INPUT_PULLUP);

  button1.begin();
  button2.begin();

  button1.onPressed(onButton1Pressed);
  button2.onPressed(onButton2Pressed);
  button1.onPressedFor(2000, onPressedForDuration);
}

void loop()
{

  button1.read();
  button2.read();
}
