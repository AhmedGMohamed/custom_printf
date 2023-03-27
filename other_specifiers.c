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
	int sum = 0;

	while (*i)
	{
		if (format[*i] == '-')
			sum += F_MINUS;
		else if (format[*i] == '+')
			sum += F_PLUS;
		else if (format[*i] == ' ')
			sum += F_SPACE;
		else if (format[*i] == '#')
			sum += F_HASH;
		else if (format[*i] == '0')
			sum += F_ZERO;
		else
			return (sum);
		(*i)++;
	}
}
/**
 * get_width - Checks for width sub-specifier
 * @format: the main printf string
 * @i: the current index to check in the format string
 * @list: the list of arguments supplied to the printf function
 *
 * Return: width - the amount of padding required for the specifier
 */
int get_width(const char *format, int *i, va_list list)
{
	int width = 0;

	if (format[*i] == '*')
	{
		(*i)++;
		return (va_arg(list, int));
	}
	else
	{
		while (format[*i] >= '0' && format[*i] <= '9')
		{
			width += format[*i] - '0';
			width *= 10;
			(*i)++;
		}
		width /= 10;
	}
	return (width);
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
		(*i)++;
		if (format[*i] == '*')
		{
			(*i)++;
			return (va_arg(list, int));
		}
		else
		{
			while (format[*i] >= '0' && format[*i] <= '9')
			{
				precision += format[*i] - '0';
				(*i)++;
				precision *= 10;
			}
			precision /= 10;
			return (precision);
		}
	}
	return (-1);
}
/**
 * get_size - checks for length modifiers for conversion specifiers
 * @format: the main printf string
 * @i: the current index to check in the format string
 *
 * Return: sum - the sum of numbers which indicate which modifier was found
 */
int get_size(const char *format, int *i)
{
	int sum = 0;

	if (format[*i] == 'l')
		sum += S_LONG;
	else if (format[*i] == 'h')
		sum += S_SHORT;
	return (sum);
}
