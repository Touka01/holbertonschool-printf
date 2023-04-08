#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

/**
 *print_char - a function that outputs a charachter
 *@args: variable number of arguments
 *Return: value of count
 */

int print_char(va_list args)
{
	int count = 0;

	putchar(va_arg(args, int));
	count++;
	return (count);
}

/**
 *print_string - a function that outputs a string
 *@args: variable number of arguments
 *Return: value of count
 */

int print_string(va_list args)
{
	int count = 0;

	char *s = va_arg(args, char *);

	if (s == NULL)
	{
		s = "(null)";
	}
	while (*s != '\0')
	{
		putchar(*s++);
		count++;
	}
	return (count);
}

/**
 *print_percent - a function that outputs a percent sign
 *@args: variable number of arguments
 *Return: value of count
 */
int print_percent(va_list args)
{
	(void)args;
	putchar('%');
	return (1);
}

/**
 *print_int - a function that outputs an integer
 *@args: variable number of arguments
 *Return: value of count
 */

int print_int(va_list args)
{
	int count = 0;
	int n = va_arg(args, int);
	int digit, sign = 1;

	if (n < 0)
	{
		sign = -1;
		n = -n;
	}

	digit = n % 10;
	n = n / 10;

	if (n != 0)
	{
		count += print_int_helper(n);
	}

	if (sign == -1)
	{
		putchar('-');
		count++;
	}

	putchar(digit + '0');
	count++;

	return (count);
}

/**
 *print_int_helper - a helper function for print_integer
 *@n: an integer
 *Return: the number of digits in the integer
 */
int print_int_helper(int n)
{
	int count = 0;

	if (n / 10 != 0)
	{
		count += print_int_helper(n / 10);
	}

	putchar((n % 10) + '0');
	count++;

	return (count);
}