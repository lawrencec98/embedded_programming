#include <stdint.h> // C99 standard integers
#include "bsp.h"


void main_blinky1() {
    while (1) {
        BSP_ledGreenOn();
        BSP_delay(BSP_TICKS_PER_SEC / 4U);
        BSP_ledGreenOff();
        BSP_delay(BSP_TICKS_PER_SEC * 3U / 4U);
    }
    //return 0;
}

void main_blinky2() {
    while (1) {
        BSP_ledBlueOn();
        BSP_delay(BSP_TICKS_PER_SEC / 2U);
        BSP_ledBlueOff();
        BSP_delay(BSP_TICKS_PER_SEC / 3U);
    }
    //return 0;
}

int main() {
	uint32_t volatile run = 0U;
	BSP_init();
	
	if (run) {
		main_blinky1();
	} else {
		main_blinky2();
	}
}