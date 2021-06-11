/* Project "Whitetail/TXLonghorn" System screen/printing library
See https://wiki.osdev.org/Printing_To_Screen for more info (incl. colors) */


char *vram = (char*)0xB8000;

void print(const char *string) {
    const char *space = " ";
    *vram++ = *space++;
    *vram++ = 0;
    while( *string != 0 )
    {           
        *vram++ = *string++;
        *vram++ = 10;
    }
}

void clear(unsigned int color) {
    const char *space0 = " ";
    int num0 = 0;
    color = color * 16;
    while(num0 != (80*25)) {
        *vram++ = *space0;
        *vram++ = color;
        num0++;
    }
}

static void lineprint_print(volatile char *video,const char *string) {
    while( *string != 0 )
    {
        *video++ = *string++;
        *video++ = 10;
    }
}
void lineprint(const char *string, unsigned int data) { 
    // Add 'A0'(0x000A0) to '0xB8000' to get to another line on the screen
    if (data <= 24) { volatile char *video = (volatile char*)(0xB8000 + data * 0x000A0); lineprint_print(video,string); }
    else {print("NOTE: Screen row MUST stay under 25");}
}

/* Advanced Video Options
*/

void xyprint(const char *string, unsigned int x,unsigned int y) {
    volatile char *video = (volatile char*)(0xB8000 + x * 0x000A0 + (y*2));
    while( *string != 0 )
    {
        *video++ = *string++;
        *video++ = 15;
    }
}

void advprint(const char *string, int color) {
    while( *string != 0 )
    {
        *vram++ = *string++;
        *vram++ = color;
    }
}

void line_advprint(const char *string, int color, unsigned int x) {
    volatile char *video = (volatile char*)(0xB8000 + x * 0x000A0);
    while( *string != 0 )
    {
        *video++ = *string++;
        *video++ = color;
    }
}