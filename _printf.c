#include "main.h"

/**
 *_printf - Customized printf function
 *@format: constant char
 *Return: Number of characters printed
 */

int _printf(const char *format, ...)
{
	int count = 0;

	va_list args;

	va_start(args, format);
	if (!format || *format == '\0')
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
			{
				putchar('%');
				count++;
			}
			else if (*format == '\0')
			{
				va_end(args);
				return (-1);
			}
			else
			{
				count += get_format_specifier(*format, args);
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
