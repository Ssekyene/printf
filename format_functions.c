#include <stdlib.h>
#include "main.h"
/**
 * found_char - stores a variable argument with a specified data type
 *@c: variable argument
 *
 * Return: a pointer to a character specifier
 */
char *found_char(va_list c)
{
	char string[2], *p;

	string[0] = va_arg(c, int);
	string[1] = '\0';
	p = string;
	return (p);
}

/**
 * itos - helper function for found_int, it converts integer
 *		to string
 * @num: the actual integer
 * @abs_val: absolute value of num
 * @string_len: length of the string to be generated
 * @divisor: the divisor to be used to convert each digit to
 *		an ascii character representation
 *
 *Return: a pointer to converted string
 */
char *itos(int num, int abs_val, int string_len, int divisor)
{
	char *string;
	int i;

	string = malloc(sizeof(char) * string_len);

	if (string == NULL)
		exit(98);
	i = 0;
	while (divisor >= 1)
	{
		if (num < 0)
			string[i++] = '-';
		abs_val /= divisor;
		string[i++] = (abs_val + '0');
		divisor /= 10;
	}
	string[i] = '\0';
	return (string);
}

/**
 * found_int - converts an integer to a string
 * @n: integer to be converted
 *
 * Return: a pointer a the converted integer string
 */
char *found_int(va_list n)
{
	int num, res, digit_count;
	char *string;
	int divisor, total_str_len;
	int i;

	num = va_arg(n, int);
	divisor = 1;
	digit_count = 0;

	if (num >= 0)
	{
		if (n == 0)
		digit_count = 1;
		res = num;
	}
	else
		res = num * -1;
	if (num != 0 && res >= 10)
	{
		while ((res / divisor) > 1)
		{
			divisor *= 10;
			digit_count++;
		}
	}
	/* to cater for a null character */
	total_str_len = digit_count + 1;
	if (num < 0)
	/* to cater for a negative sign*/
	total_str_len = *digit_count + 1;

	string = itos(num, res, total_str_len, divisor);

	return (string);
}

/**
 * found_str - specifies a variable argument to a string
 *@s: string to be specified
 *
 * Return: a pointer a character or (nil) on failure
 */
char *found_str(va_list s)
{
	char *str;

	str = va_arg(s, char *);
	if (str == NULL)
		return ("(nil)");
	return (str);
}
