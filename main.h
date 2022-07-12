#ifndef MAINH
#define MAINH

#include <stdarg.h>
int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list c);
int print_string(va_list s);
int print_int(va_list i);
int print_double(va_list d);
/**
 * struct c_format - Struct for format and function
 * @sc: a char format symbol
 * @f: The function associated with sc
 */
typedef struct c_format
{
	char *sc;
	int (*f)(va_list);
} code_f;

#endif
