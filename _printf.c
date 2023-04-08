#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
	int chars = 0;
	va_list args;
	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				int c = va_arg(args, int);
				putchar(c);
				chars++;
			}
			else if (*format == 's')
			{
				char *s = va_arg(args, char *);
				while (*s)
				{
					putchar(*s);
					s++;
					chars++;
				}
			}
			else if (*format == '%')
			{
				putchar('%');
				chars++;
			}
			else
			{
				putchar('%');
				putchar(*format);
				chars += 2;
			}
		}
		else
		{
			putchar(*format);
			chars++;
		}
		format++;
	}

	va_end(args);
	return chars;
}