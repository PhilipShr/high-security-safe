#include <Arduino.h>
#include <pins_arduino.h>
#include <state_machine.h>

#define Button1 PA5 // input1
#define Button2 PA6 // input2
#define Button3 PA7 // input3
#define Button4 PA8 // open_foor

#define LED1 PB5
#define LED2 PB6
#define LED3 PB7
#define LED4 PB8
#define LED5 PB9

// Funktion definieren

void set_einAusgänge();
void check_state();
void set_state();

void setup()
{
  void set_einAusgänge();
}

// Taster und Leds intitialisieren
void loop()
{
  void check_state();
  void set_state();
}

// Statemachine

void set_einAusgänge()
{
  // Input
  pinMode(Button1, INPUT);
  pinMode(Button2, INPUT);
  pinMode(Button3, INPUT);
  pinMode(Button4, INPUT);
  // Output
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

void check_state()
{
  // Tasterzustände überprüfen
  if (digitalRead(Button1) == LOW)
  {
    state_machine(input1_accepted);
  }
  if (digitalRead(Button2) == LOW)
  {
    state_machine(input2_accepted);
  }
  if (digitalRead(Button3) == LOW)
  {
    state_machine(input3_accepted);
  }
  if (digitalRead(Button4) == LOW)
  {
    state_machine(open_door);
  }
}

void set_state()
{
  switch (state)
  {
  case safe_locked:
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    break;
  case level1_unlocked:
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, LOW);
    digitalWrite(LED3, LOW);
    break;
  case level2_unlocked:
    digitalWrite(LED3, HIGH);
    digitalWrite(LED3, LOW);
    digitalWrite(LED3, LOW);
    break;
  }
}