/**
 *
 *
 *
 *
 *
 *
 */

#include <Arduino.h>
#include "pinout.h"
#include "configuration.h"

void setup() {
    #ifdef CS_SWITCH1
    cs1.set_CS_AutocaL_Millis(0xFFFFFFFF);
    #endif
    #ifdef CS_SWITCH2
    cs2.set_CS_AutocaL_Millis(0xFFFFFFFF);
    #endif
    #ifdef CS_SWITCH3
    cs3.set_CS_AutocaL_Millis(0xFFFFFFFF);
    #endif
    #ifdef CS_SWITCH4
    cs4.set_CS_AutocaL_Millis(0xFFFFFFFF);
    #endif

    pinMode(RELAY, OUTPUT);
    pinMode(LED, OUTPUT);
    analogWrite(LED, dimmedLEDLevel);
}

void loop() {
    #ifdef CS_SWITCH1
    long cap1 = cs1.capacitiveSensor(30);
    #endif
    #ifdef CS_SWITCH2
    long cap2 = cs2.capacitiveSensor(30);
    #endif
    #ifdef CS_SWITCH3
    long cap3 = cs3.capacitiveSensor(30);
    #endif
    #ifdef CS_SWITCH4
    long cap4 = cs4.capacitiveSensor(30);
    #endif

    if (cap1 > cs1SensibilityLevel) {
        // Set flow of LED state indicatior
        if (!cs1State) {
            dimStart = brightLEDLevel; dimEnd = dimmedLEDLevel; dimStep = -1;
        }
        else {
            dimStart = dimmedLEDLevel; dimEnd = brightLEDLevel; dimStep = 1;
        }
        // Update the control switch state
        cs1State = !cs1State;
        // Update final relay switch
        digitalWrite(RELAY, cs1State);
        // Update LED indicator state
        updateLEDState(dimStart, dimEnd, dimStep);
    }
}
