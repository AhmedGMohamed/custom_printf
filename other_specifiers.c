#include "main.h"
/**
 * get_flags - Checks for flag sub-specifiers in the format specifier
 * @format: the main printf string
 * @i: the current index to check in the format string
 *
 * Return: sum - the sum of numbers which indicate which flags were found
 */
int get_flags(const char *format, int *i)
{
	int found = 1, sum = 0;

	while (found)
	{
		found = 0;
		if (format[*i] == '-')
			sum += F_MINUS, found = 1, *i++;
		else if (format[*i] == '+')
			sum += F_PLUS, found = 1, *i++;
		else if (format[*i] == ' ')
			sum += F_SPACE, found = 1, *i++;
		else if (format[*i] == '#')
			sum += F_HASH, found = 1, *i++;
		else if (format[*i] == '0')
			sum += F_ZERO, found = 1, *i++;
	}
	return (sum);
}
/**
 * get_precision - Checks for precision sub-specifiers
 * @format: the main printf string
 * @i: the current index to check in the format string
 * @list: the list of arguments supplied to the printf function
 *
 * Return: -1 if the precision sub-specifier wasn't used
 *	   precision - the precision (number) specified in the format string
 */
int get_precision(const char *format, int *i, va_list list)
{
	int precision = 0;

	if (format[*i] == '.')
	{
		*i++;
		if (format[*i] == '*')
		{
			*i++;
			return (va_arg(list, int));
		}
		else
		{
			while (format[*i] >= '0' && format[*i] <= '9')
			{
				precision += format[*i];
				*i++;
				precision *= 10;
			}
			precision /= 10;
			return (precision);
		}
	}
	return (-1);
}