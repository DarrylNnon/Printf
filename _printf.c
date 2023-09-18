#include "main.h"
/**
 * print_buff - is the buffer print
 * @buffer: is the array
 * @buff_ind: is the array
 */
void print_buff(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
	{
		write(1, &buffer[0], *buff_ind);
	}
	*buff_ind = 0;
}


/**
 * _printf - is used as our custom printf
 * @format: is the input used
 * Return: as specified
 */
int _printf(const char *format, ...)
{
	int j, prt = 0, _print_char = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (j = 0; format && format[j] != '\0'; j++)
	{
		if (format[j] != '%')
			buffer[buff_ind++] = format[j];
		if (buff_ind == BUFF_SIZE)
		{
			print_buff(buffer, &buff_ind);
			_print_char++;
		}
		else
		{
			print_buff(buffer, &buff_ind);
			flags = get_flags(format, &j);
			width = get_width(format, &j, list);
			precision = get_precision(format, &j, list);
			size = get_size(format, &j);
			j++;
			prt = handle_print(format, &j, list, buffer, flags, width, precision, size);
		if (prt == -1)
			return (-1);
		_print_char += prt;
		}
	}
	print_buff(buffer, &buff_ind);
	va_end(list);
	return (_print_char);
}
