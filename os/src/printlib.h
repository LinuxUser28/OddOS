#include "libc.h"

// See https://wiki.osdev.org/Printing_To_Screen for more info (incl. colors)

// note this example will always write to the top
// line of the screen



void print(const char *string) {
    volatile char *video = (volatile char*)0xB8000;
    const char *space = " ";
    *video++ = *space++;
    *video++ = 0;
    while( *string != 0 )
    {
        *video++ = *string++;
        *video++ = 10;
    }
}

void lineprint_print(volatile char *video,const char *string) {
    while( *string != 0 )
    {
        *video++ = *string++;
        *video++ = 10;
    }
}
void lineprint(const char *string, int data)
{
    if(data == 0) {volatile char *video = (volatile char*)0xB8000; lineprint_print(video,string);}
    if(data == 1) {volatile char *video = (volatile char*)0xB80A0; lineprint_print(video,string);}
    if(data == 2) {volatile char *video = (volatile char*)0xB8140; lineprint_print(video,string);}
}
