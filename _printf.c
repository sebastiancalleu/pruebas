#include "holberton.h"
#include <stdio.h>
int main(void)
{
	_printf("this is the case %!\n");
	_printf("this is the case %%\n");
	_printf("this is the case %d\n", 54165);
	_printf("this is a string %s\n", "hola mundo");
	_printf("this is a number %i\n", -65384);
	return (0);
}
/**
 * _printf - this function works like the printf function.
 * @format: string to print.
 * Return: character count.
 */
int _printf(const char *format, ...)
{
	int a, b = 0;

	va_list(list);

	va_start(list, format);
	if (!format || (format[0] == '%' && _strlen(format) == 1))
		return (-1);
	for (a = 0; format[a] != '\0'; a++)
	{
		if (format[a] != '%')
		{
			_putchars(format[a], &b);
		}
		else
		{
			switch (format[a + 1])
			{
			case 'c':
				_putcharp((char) va_arg(list, int), &a, &b);
				break;
			case 's':
				putstring(va_arg(list, char *), &b, &a);
				break;
			case 'i':
			case 'd':
				_number(va_arg(list, int), &b);
				a++;
				break;
			case '%':
				_printd(&a, &b);
				break;

			default:
				_putchars('\%', &b);
				break;
			}
		}
	}
	printf("%d\n", b);
	va_end(list);
	return (b);
}
