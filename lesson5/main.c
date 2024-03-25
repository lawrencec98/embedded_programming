#include "tm4c.h"

int main() {

	SYSCTL_RCGCGPIO_R = 0X20U;		//enable clock for GPIOF
	GPIO_PORTF_DIR_R = 0X0EU;		// set pins 1,2 and 3 as outputs
	GPIO_PORTF_DEN_R = 0X0EU;
	
	while(1) {
		GPIO_PORTF_DATA_R = 0x04U;
		
		int counter = 0;
		while (counter < 1000000) {		// delay loop
			++counter;
		}
		
		GPIO_PORTF_DATA_R = 0x00U;
		counter = 0;
		while (counter < 1000000) {		// delay loop
			++counter;
		}
	}
	return 0;
}
