/* Project "Whitetail/TXLonghorn" System main code */
/* 'Monotasking Operating System (MOS)' or (future) 'STereotasking Operating Enviroment (STOE)' */
/* The RAM is split half-way, with lower being kernel, and upper being Applications */

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "libc.h"
#include "printlib.h"

int white = 15;
int green = 10;
int red = 4;
const char* name = "Simple Monotasking Operating System";

// char key = inb(0x60);

void help() {
	//
}

void terminal() {
	print("Main terminal initialized", white);
	print("To issue a command, press the button on your 'keyboard' labled with the character in parentheses to the right of the intended commands", green);
	newline();
	print("Commands: help (h)", green);
	bool loop = true;
	while(loop) {
		if( inb(0x60) == 0xA3 ) {
			outb(0x60, 0x00);
			print("H",green);
			loop = false;
		}
	}
}

void main()
{
	cursor cursor;
	cursor.disable();
	init_pics(0x20, 0x28);
	print(name, white);
	terminal();
}