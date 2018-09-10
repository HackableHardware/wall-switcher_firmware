/**
 *
 *
 *
 *
 *
 *
 */

#include "deps.h"

void updateLEDState(int dimStart, int dimEnd, int dimStep) {
    // Adjust panel LED intensity
    for (int i = dimStart; i > dimEnd; i += dimStep) {
        analogWrite(LED, i);
        delay(5);
    }
}
