#ifndef MAIN_H
#define MAIN_H

/*** libraries ***/

#include <stdarg.h>

/**** Prototypes *****/

int _printf(const char *format, ...);
char *found_char(va_list c);
char *found_int(va_list n);
char *found_str(va_list s);
int _strlen(char *s);
char *_memcpy(char *dest, char *src, unsigned int n, unsigned int bufferlen);
void _puts(char *buffer, int size);
int alloc_buffer(char *hold, int hlen, char *buffer, int blen, double *total);
char *ctos(char);
char *itos(int num, int abs_val, int string_len, int divisor);


/*** defined macros ***/

#define BUFSIZE 1024

/*** defined data types ***/

typedef struct validTypes
{
	char *valid;
	char *(*f)(va_list c);
} v_types;

#endif /* !MAIN_H */
