#include <CapacitiveSensor.h>
#include "pitches.h"
/*
 * CapitiveSense Library Demo Sketch
 * Paul Badger 2008
 * Uses a high value resistor e.g. 10 megohm between send pin and receive pin
 * Resistor effects sensitivity, experiment with values, 50 kilohm - 50 megohm. Larger resistor values yield larger sensor values.
 * Receive pin is the sensor pin - try different amounts of foil/metal on this pin
 * Best results are obtained if sensor foil and wire is covered with an insulator such as paper or plastic sheet
 */

CapacitiveSensor cs_12_2 = CapacitiveSensor(12, 2); // 10 megohm resistor between pins 4 & 2, pin 2 is sensor pin, add wire, foil
CapacitiveSensor cs_12_3 = CapacitiveSensor(12, 3);
CapacitiveSensor cs_12_4 = CapacitiveSensor(12, 4); // 10 megohm resistor between pins 4 & 2, pin 2 is sensor pin, add wire, foil
CapacitiveSensor cs_12_5 = CapacitiveSensor(12, 5);
CapacitiveSensor cs_12_6 = CapacitiveSensor(12, 6); // 10 megohm resistor between pins 4 & 2, pin 2 is sensor pin, add wire, foil
CapacitiveSensor cs_12_7 = CapacitiveSensor(12, 7);
CapacitiveSensor cs_12_8 = CapacitiveSensor(12, 8); // 10 megohm resistor between pins 4 & 2, pin 2 is sensor pin, add wire, foil
CapacitiveSensor cs_12_9 = CapacitiveSensor(12, 9);

int duration = 100;
// 3000 works on touch
int threshold = 3000;
void setup()
{
    Serial.begin(9600);
}

void loop()
{
    long DO = cs_12_2.capacitiveSensor(30);
    long RE = cs_12_3.capacitiveSensor(30);
    long MI = cs_12_4.capacitiveSensor(30);
    long FA = cs_12_5.capacitiveSensor(30);
    long SOL = cs_12_6.capacitiveSensor(30);
    long LA = cs_12_7.capacitiveSensor(30);
    long SI = cs_12_8.capacitiveSensor(30);
    long DO2 = cs_12_9.capacitiveSensor(30);

    if (DO > threshold)
    {
        Serial.print("rING1\n");
        tone(11, NOTE_C4 , duration);
    }

    if (RE > threshold)
    {
        Serial.print("rING2\n");
        tone(11, NOTE_D4, duration);
    }

    if (MI > threshold)
    {
        Serial.print("rING1\n");
        tone(11, NOTE_E4, duration);
    }

    if (FA > threshold)
    {
        Serial.print("rING2\n");
        tone(11, NOTE_F4, duration);
    }

    if (SOL > threshold)
    {
        Serial.print("rING2\n");
        tone(11, NOTE_G4, duration);
    }

    if (LA > threshold)
    {
        Serial.print("rING2\n");
        tone(11, NOTE_A4, duration);
    }

    if (SI > threshold)
    {
        Serial.print("rING2\n");
        tone(11, NOTE_B4, duration);
    }

    if (DO2 > threshold)
    {
        Serial.print("rING2\n");
        tone(11, NOTE_C5, duration);
    }

    Serial.print(DO); // print sensor output 1
    Serial.print("\t");
    Serial.print(RE); // print sensor output 2
    Serial.print("\n");

    // delay(duration); // arbitrary delay to limit data to serial port
}