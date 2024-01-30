#include <stdlib.h>
#include "main.h"
/**
 * _printf - prints a formated output to console
 * @format: string passed with defined specifiers
 *
 * Return: Number of bytes printed
 */
int _printf(const char *format, ...)
{
	int i, hlen;
	va_list argp;
	char buffer[BUFSIZE];
	char *(*pointer_get_valid)(va_list);
	char *holder;

	va_start(argp, format);
	for (i = 0; i < BUFSIZE; i++)
		buffer[i] = 0;
	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			pointer_get_valid = get_valid_type(format[i + 1]);

			holder = (pointer_get_valid(format[i + 1]) == NULL) ?
					found_nothing(format[i + 1]) :
					pointer_get_valid(argp);
			hlen = _strlen(holder);
			blen = alloc_buffer(holder, hlen, buffer, blen, total);
			i++;
		}
		else
		{
			holder = ctos(format[i]);
			blen = alloc_buffer(holder, 1, buffer, blen, total);
		}
	}
	va_end(argp);
	_puts(buffer, blen);
	return (totalBuffer + blen);
}

