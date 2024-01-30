#include <unistd.h>
#include "main.h"

/**
 * _strlen - return length of string
 * @s: string parameter
 * Return: length of string
 */
int _strlen(char *s)
{
	int length;
	int i;

	length = 0;
	for (i = 0; s[i] != '\0'; i++)
		length++;
	return (length);
}

/**
 * _memcpy - copies memory area
 * @dest: pointer to destination memory area
 * @src: pointer to source memory area
 * @n: number of bytes to copy
 * @bufferlen: current number of bytes taken by buffer
 * Return: pointer to destination memory area
 */
char *_memcpy(char *dest, char *src, unsigned int n, unsigned int bufferlen)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i + bufferlen] = src[i];
	return (dest);
}

/**
 * _puts - print a buffer content to console.
 * @buffer: buffer passed
 * @size: number of bytes to print
 */
void _puts(char *buffer, int size)
{
	write(1, buffer, size);
}
