#include <stdint.h>
#include "delay.h"
#include "tm4c.h"

#define LED_RED	  (1U << 1)
#define LED_BLUE  (1U << 2)
#define LED_GREEN (1U << 3)

uint8_t u8a, u8b;
uint16_t u16c, u16d;
uint32_t u32e, u32f;

int8_t s8;
int16_t s26;
int32_t s32;

int main() {

	u8a = sizeof(u8a);
	u16c = sizeof(u16c);
	u32e = sizeof(u32e);
	
	u16c = 40000;
	u16d = 30000;
	u32e = u16c + u16d;
	
	SYSCTL_RCGCGPIO_R |= (1U << 5);		//enable clock for GPIOF
	SYSCTL_GPIOHBCTL_R |= (1U << 5); 	//enable AHB for GPIOF
	GPIO_PORTF_AHB_DIR_R |= (LED_RED | LED_BLUE | LED_GREEN);
	GPIO_PORTF_AHB_DEN_R |= (LED_RED | LED_BLUE | LED_GREEN);
	
	GPIO_PORTF_AHB_DATA_BITS_R[LED_BLUE] = LED_BLUE;
	while(1) {
		GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] = LED_RED;		
		
		delay(1000000);
		
		GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] = 0;
		
		delay(500000);
	}
	return 0;
}
