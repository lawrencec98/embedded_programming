#include <stdint.h>
#include "tm4c_cmsis.h"
#include "delay.h"

#define LED_RED   (1U << 1)
#define LED_BLUE  (1U << 2)
#define LED_GREEN (1U << 3)


int main(void) {
	
	SYSCTL->RCGC2 |= (1U << 5);  /* enable clock for GPIOF */
    SYSCTL->GPIOHSCTL |= (1U << 5); /* enable AHB for GPIOF */
    GPIOF_AHB->DIR |= (LED_RED | LED_BLUE | LED_GREEN);
    GPIOF_AHB->DEN |= (LED_RED | LED_BLUE | LED_GREEN);

    /* turn all LEDs off */
    GPIOF_AHB->DATA_Bits[LED_RED | LED_BLUE | LED_GREEN] = 0U;

    //GPIOF_AHB->DATA_Bits[LED_BLUE] = LED_BLUE;
	
    while (1) {
        GPIOF_AHB->DATA_Bits[LED_RED] ^= LED_RED;
        delay(500000);
    }
    //return 0; // unreachable code
}