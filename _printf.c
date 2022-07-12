#include <string.h>
#include <unistd.h>
#include "main.h"

/**
 * find_function - function that finds formats for _printf
 * @format: char(c), string(s), int(i), decimal(d)
 * Return: if all goes well function associated
 */
int (*find_function(const char *format))(va_list)
{
	unsigned int i = 0;
	code_f find_f[] = {
		{"c", print_char},
		{"s", print_string},
		{NULL, NULL}
	};

	while(find_f[i].sc)
	{
		if(find_f[i].sc[0] == (*format))
			return (find_f[i].f);
		i++;
	}
	return (NULL);
}
/**
 * _printf - function that prints out to stdout according to the format
 * @format: char, string, int, decimal
 * Return: size of the output the text
 */
int _printf(const char *format, ...)
{
	va_list ap;
	
	int (*f)(va_list);
	unsigned int i = 0, cprint = 0;

	if (format == NULL)
		return (-1);
	
	va_start(ap, format);
	while (format[i])
	{
		while (format[i] != '%' && format[i])
		{
			_putchar(format[i]);
			cprint++;
			i++;
		}
		if (format[i] == '\0')
			return (cprint);
		f = find_function(&format[i + 1]);
		if (f != NULL)
		{
			cprint += f(ap);
			i += 2;
			continue;
		}
		if (!format[i + 1])
			return (-1);
		_putchar(format[i]);
		cprint++;
		if (format[i + 1] == '%')
			i +=2;
		else
			i++;
	}
	va_end(ap);
	return (cprint);
}
