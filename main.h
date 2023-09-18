#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFF_SIZE 1024

void print_char(va_list args, char *buffer, int *buff_ind);
void print_string(va_list args, char *buffer, int *buff_ind);
void print_percent(char *buffer, int *buff_ind);
void print_buffer(char *buffer, int *buff_ind);
int _printf(const char *format, ...);

#endif
