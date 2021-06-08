#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "libc.h"
#include "printlib.h"


void main(void)
{
	int lolz = 0;
	while(lolz != 25) {
		lineprint("FoobarBarian",lolz);
		lolz++;
	}
}



// Axel F