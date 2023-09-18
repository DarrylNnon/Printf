#include "main.h"
#include <stdlib.h>

/**
 * print_char - is used to accept char for print
 * @buffer: is the pointer
 * @buff_ind: - is the buffer input
 * @args: - is the arguement used
 * Author: Darynl Nnon and Isaac Adekunle
 */
void print_char(va_list args, char *buffer, int *buff_ind)
{
	char c = va_arg(args, int);

	buffer[(*buff_ind)++] = c;
}
/**
 * print_string - is used to accept str for print
 * @buffer: is pointer used
 * @buff_ind: is the buffer input
 * @args: is the arguement used
 */
void print_string(va_list args, char *buffer, int *buff_ind)
{
	char *s = va_arg(args, char *);

	while (*s)
	{
		buffer[(*buff_ind)++] = *s++;
	}
}
/**
 * print_percent - is used to accept percent for print
 * @buffer: is the pointer used
 * @buff_ind: is the pointer array
 */
void print_percent(char *buffer, int *buff_ind)
{
	buffer[(*buff_ind)++] = '%';
}
/**
 * print_buffer - is used to buffer print
 * @buffer: is the storage value
 * @buff_ind: is the buffer input
 */
void print_buffer(char *buffer, int *buff_ind)
{
	write(1, buffer, *buff_ind);
	*buff_ind = 0;
}
/**
 * _printf - is used as our custom printf
 * @format: is the input used
 * Return: as specified
 */
int _printf(const char *format, ...)
{
	va_list args;
	int buff_ind = 0;
	const char *traverse = format;
	char *buffer = malloc(BUFF_SIZE * sizeof(char));

	if (buffer == NULL || !format || (format[0] == '%' && !format[1]))
		return (-1);
	va_start(args, format);
	while (*traverse != '\0')
	{
		while (*traverse != '%' && *traverse != '\0')
			buffer[buff_ind++] = *traverse++;
		if (*traverse == '\0')
		{
			break;
			traverse++;
		}
		switch (*traverse)
		{
			case 'c':
		print_char(args, buffer, &buff_ind);
		break;
			case 's':
		print_string(args, buffer, &buff_ind);
		break;
			case '%':
		print_percent(buffer, &buff_ind);
		break;
		}
		if (buff_ind >= BUFF_SIZE - 1)
			print_buffer(buffer, &buff_ind);
		traverse++;
	}
	print_buffer(buffer, &buff_ind);
	free(buffer);
	va_end(args);
	return (buff_ind);
}
