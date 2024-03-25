#include "delay.h"

void delay(int iter) {
	int counter = 0;
	while (counter < iter) {		// delay loop
		++counter;
	}
}