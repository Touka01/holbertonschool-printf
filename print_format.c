#include "main.h"

/**
 * print_char - Prints a character
 * @args: The character to print
 *
 * Return: The number of characters printed
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);
	putchar(c);
	return (1);
}

/**
 * print_string - Prints a string
 * @args: The string to print
 *
 * Return: The number of characters printed
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int len = 0;

	while (*str)
	{
		putchar(*str);
		str++;
		len++;
	}

	return (len);
}

/**
 * print_percent - Prints a percent sign
 * @args: Unused
 *
 * Return: The number of characters printed
 */
int print_percent(__attribute__((unused)) va_list args)
{
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
