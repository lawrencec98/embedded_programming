#include "tmc4_cmsis.h"

void SysTick_Handler(void)
{
	GPIOF_AHB->DATA_Bits[LED_RED] ^= LED_RED;
}