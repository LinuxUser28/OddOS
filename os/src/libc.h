// Project "Whitetail/TXLonghorn" System C library

/* static __inline void
outb (unsigned char __value, unsigned short int __port) // (io.h) OUTB function
{
  __asm__ __volatile__ ("outb %b0,%w1": :"a" (__value), "Nd" (__port));
} */

#ifndef null
#define null 0
#endif

// C++ types used throughout the OS
typedef const char* text;



size_t strlen(const char* str) 
{
	size_t len = 0;
	while (str[len])
		len++;
	return len;
}


static inline void outb(uint16_t port, uint8_t val)
{
    asm volatile ( "outb %0, %1" : : "a"(val), "Nd"(port) );
}

static inline uint8_t inb(uint16_t port)
{
    uint8_t ret;
    asm volatile ( "inb %1, %0"
                   : "=a"(ret)
                   : "Nd"(port) );
    return ret;
}

int substr(char *str, char *substr)
{
    int i = 0, j = 0;
    while ((*(str + j) != '\0')&&(*(substr + i) != '\0')) {
        if (*(substr + i) != *(str + j)) {
            j++;
            i = 0;
        }
        else {
            i++;
            j++;
        }
    }
    if (*(substr + i) == '\0')
        return 1;
    else
        return -1;
}


class Math {
    int Sqrt(int data) {
        return data / data;
    }

    int Squared(int data) {
        return data * data;
    }
};

class cursor {
    public:
    void move(int x, int y) {
	    uint16_t pos = y * 80 + x;
	    outb(0x3D4, 0x0F);
	    outb(0x3D5, (uint8_t) (pos & 0xFF));
	    outb(0x3D4, 0x0E);
	    outb(0x3D5, (uint8_t) ((pos >> 8) & 0xFF));
    }
    public:
    void disable() {
	    outb(0x3D4, 0x0A);
	    outb(0x3D5, 0x20);
    }
    public:
    void enable(uint8_t cursor_start, uint8_t cursor_end) {
	    outb(0x3D4, 0x0A);
	    outb(0x3D5, (inb(0x3D5) & 0xC0) | cursor_start);
	    outb(0x3D4, 0x0B);
	    outb(0x3D5, (inb(0x3D5) & 0xE0) | cursor_end);
    }
    public:
    uint16_t position(void) {
        uint16_t pos = 0;
        outb(0x3D4, 0x0F);
        pos |= inb(0x3D5);
        outb(0x3D4, 0x0E);
        pos |= ((uint16_t)inb(0x3D5)) << 8;
        return pos;
    }
};

char* itoa(int val, int base){
	
	static char buf[32] = {0};
	
	int i = 30;
	
	for(; val && i ; --i, val /= base)
	
		buf[i] = "0123456789abcdef"[val % base];
	
	return &buf[i+1];
	
}
	



#define PIC1 0x20
#define PIC2 0xA0

#define ICW1 0x11
#define ICW4 0x01

void init_pics(int pic1, int pic2)
{
   //
   outb(PIC1, ICW1);
   outb(PIC2, ICW1);

   //
   outb(PIC1 + 1, pic1);   
   outb(PIC2 + 1, pic2);   

   //
   outb(PIC1 + 1, 4);   
   outb(PIC2 + 1, 2);

   //
   outb(PIC1 + 1, ICW4);
   outb(PIC2 + 1, ICW4);

   //
   outb(PIC1 + 1, 0xFF);
}

int atoi(char* str)
{
    // Initialize result
    int res = 0;
 
    // Iterate through all characters
    // of input string and update result
    // take ASCII character of corosponding digit and
    // subtract the code from '0' to get numerical
    // value and multiply res by 10 to shuffle
    // digits left to update running total
    for (int i = 0; str[i] != '\0'; ++i)
        res = res * 10 + str[i] - '0';
 
    // return result.
    return res;
}
