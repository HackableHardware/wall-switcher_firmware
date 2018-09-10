/**
 *
 *
 *
 *
 *
 *
 */

#ifndef __CONFIGURATION_H__
#define __CONFIGURATION_H__

// Fill dependencies
#include "deps.h"

//
int dimStart = 0,
    dimEnd = 0,
    dimStep = 0;

//
#ifdef CS_SWITCH1
bool cs1State = 0;
CapacitiveSensor cs1 = CapacitiveSensor(CS_COMMON, CS_SWITCH1);
const int cs1SensibilityLevel = 5000;
#endif
#ifdef CS_SWITCH2
bool cs2State = 0;
CapacitiveSensor cs2 = CapacitiveSensor(CS_COMMON, CS_SWITCH2);
const int cs2SensibilityLevel = 5000;
#endif
#ifdef CS_SWITCH3
bool cs3State = 0;
CapacitiveSensor cs3 = CapacitiveSensor(CS_COMMON, CS_SWITCH3);
const int cs3SensibilityLevel = 5000;
#endif
#ifdef CS_SWITCH4
bool cs4State = 0;
CapacitiveSensor cs4 = CapacitiveSensor(CS_COMMON, CS_SWITCH4);
const int cs4SensibilityLevel = 5000;
#endif

//
const int dimmedLEDLevel = 1;
const int brightLEDLevel = 255;

//
void updateLEDState(int dimStart, int dimEnd, int dimStep);

#endif /* __CONFIGURATION_H__ */
