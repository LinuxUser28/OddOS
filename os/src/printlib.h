/* Project "Whitetail/TXLonghorn" System screen/printing library
See https://wiki.osdev.org/Printing_To_Screen for more info (incl. colors) */

int color_def = 15;

int row = 0;
int column = 0;

void print(const char *string, int color = 15, bool addRow = true) {
    volatile char *video = (volatile char*)(0xB8000 + (row * 0x000A0) + (column * 2) );
    if(addRow) {
        row++;
        column = 0;
    }
    else {
        column += strlen(string);
    }
    int tmp = 0;
    while( *string != 0 )
    {
        tmp++;
        if(tmp >= 80) {
            *video += (char)0x000A0;
            row++;
            tmp = 0;
        }
        *video++ = *string++;
        *video++ = color;
    }
}

void newline(int amount = 1) {
    row += amount;
}


void clear(unsigned int color) {
    char *video = (char*)0xB8000;
    const char *space0 = " ";
    int num0 = 0;
    color = color * 16;
    while(num0 != (80*25)) {
        *video++ = *space0;
        *video++ = color;
        num0++;
    }
}

void xyprint(const char *string, unsigned int x = 0,unsigned int y = 0, unsigned int color = 15) {
    volatile char *video = (volatile char*)(0xB8000 + x * 0x000A0 + (y*2));
    while( *string != 0 )
    {
        *video++ = *string++;
        *video++ = color;
    }
}