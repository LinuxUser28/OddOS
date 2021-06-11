// Project "Whitetail/TXLonghorn" System C library

/* static __inline void
outb (unsigned char __value, unsigned short int __port) // (io.h) OUTB function
{
  __asm__ __volatile__ ("outb %b0,%w1": :"a" (__value), "Nd" (__port));
} */

size_t strlen(const char* str) 
{
	size_t len = 0;
	while (str[len])
		len++;
	return len;
}

static __inline void
outb (char *__value, unsigned short int __port)
{
  __asm__ __volatile__ ("outb %b0,%w1\noutb %%al,$0x80": :"a" (__value),
                        "Nd" (__port));
}


int substr(char *str, char *substr) // simple SUBSTR function, finds substring in string
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