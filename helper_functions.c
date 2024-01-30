#include "main.h"
#include <stdlib.h>

/**
 * get_valid_types - identifies the valid specifiers
 * @c: a character to a specific data type
 *
 * Return: a pointer to a function to match the specifier data type or
 *		NULL on failure
 */
char *(*get_valid_type(char c))(va_list)
{
	int i;
	v_types valid_types[] = {
		{"c", found_char},
		{"d", found_int},
		{"s", found_str},
		{NULL, NULL}
	};
	for (i = 0; valid_types[i].valid; i++)
	{
		if (c == *valid_types[i].valid)
			return (valid_types[i].f);
	}

	return (NULL);
}

/**
 * found_nothing - makes an unknown specifier a literal string
 * @c: unknown specifier
 *
 * Return: pointer to a string
 */
char *found_nothing(char c)
{
	char string[3];

	string[0] = '%';
	string[1] = c;
	string[2] = '\0';

	return (string);
}

/**
 * alloc_buffer - allocates characters to buffer, handling overflows
 * @hold: string to allocate into buffer
 * @hlen: holder length
 * @buffer: pointer to buffer
 * @blen: used buffer length
 * @total: pointer to full buffer size count
 * Return: used buffer length
 */
int alloc_buffer(char *hold, int hlen, char *buffer, int blen, double *total)
{
	int sizecpy = 0;

	if (hlen + blen > BUFSIZE)
	{
		sizecpy = BUFSIZE - blen;
		_memcpy(buffer, hold, sizecpy, blen);
		_puts(buffer, BUFSIZE);
		hold += sizecpy;
		_memcpy(buffer, hold, hlen - sizecpy, 0);
		blen = hlen - sizecpy;
		*total += BUFSIZE;
	}
	else
	{
		_memcpy(buffer, hold, hlen, blen);
		blen += hlen;
	}									}
		return (blen);
}
/**
 * ctos - converts a character to a string
 * @c: charater to convert
 *
 *Return: a pointer to a string
 */
char *ctos(char c)
{
	char string[2];

	string[0] = c;
	string[1] = '\0';
	return (string);
}
