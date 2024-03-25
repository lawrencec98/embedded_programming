int main() {

	unsigned int *p_portFGatingControl = (unsigned int*)0x400FE608U;
	unsigned int *p_pinDirection = (unsigned int*)0x40025400U;
	unsigned int *p_digitalFunction = (unsigned int*)0x4002551CU;
	unsigned int *p_ledOnOff = (unsigned int*)0x400253FCU;
	
	// set up memory to allow LED controls
	*p_portFGatingControl = 0x20U;
	*p_pinDirection = *p_digitalFunction = 0x0EU;
	
	// control loop for blinking the LED
	while(1) {
		*p_ledOnOff = 0x04U;
		
		int counter = 0;
		while (counter < 1000000) {
			++counter;
		}
		
		*p_ledOnOff = 0x00U;
		
		counter = 0;
		while (counter < 1000000) {
			++counter;
		}
	}
	
	return 0;
}
