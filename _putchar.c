#include "main.h"
/**
* _putchar - write the character c to stdout
* @: the character to print
* return: on success 1
* on error, -1 is returned, and errno is set properly
*/

int _putchar(char c)
{
	return(write(1, &c, 1));
}
