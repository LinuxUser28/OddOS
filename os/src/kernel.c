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


void bluescreen(const char *msg) {
	clear(1);
	xycolorprint(msg,1,15,(25 / 2 - 1), (80 / 2 - (strlen(msg) / 2)));
}


void main()
{
	//redscreen("This is a test");
	bluescreen("ERROR: THERE IS NO ERROR");
}

