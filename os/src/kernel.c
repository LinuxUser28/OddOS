// Project "Whitetail/TXLonghorn" System main code

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "libc.h"
#include "printlib.h"

/* void terminal() {
	const char *foobar = "foobar";
	unsigned int buffer0 = 1;
	while (buffer0 != 24)
	{
		line_advprint(foobar,15,buffer0);
		buffer0++;
	}
	line_advprint("Exiting terminal...",15,24);
} */

const char *start_string = "foorbar";

void main()
{
	clear(1);
	xyprint(start_string,(25 / 2),(80 / 2 - (strlen(start_string) / 2)));
	//advprint("Main code initialized",15);
	// Main code
}