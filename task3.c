#include "main.h"

/**
 * get_flags - determine active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags:
 * Authors: Darryl and Isaac
 */
int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int i, curr_i;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		for (i = 0; FLAGS_CH[i] != '\0'; i++)
			if (format[curr_i] == FLAGS_CH[i])
			{
				flags |= FLAGS_ARR[i];
				break;
			}

		if (FLAGS_CH[i] == 0)
			break;
	}

	*i = curr_i - 1;

	return (flags);
}

