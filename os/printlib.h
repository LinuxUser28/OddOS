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

void advprint(const char *string, int color) {
    volatile char *video = (volatile char*)0xB8000;
    while( *string != 0 )
    {
        *video++ = *string++;
        *video++ = color;
    }
}

void lineprint_print(volatile char *video,const char *string) {
    while( *string != 0 )
    {
        *video++ = *string++;
        *video++ = 10;
    }
}
static void lineprint(const char *string, unsigned int data) { 
    // Add 'A0'(0x000A0) to '0xB8000' to get to another line on the screen
    if (data <= 24) { volatile char *video = (volatile char*)(0xB8000 + data * 0x000A0); lineprint_print(video,string); }
    else {advprint("CODE ERROR: 'lineprint' number exceeds supported line.", 4);}
}