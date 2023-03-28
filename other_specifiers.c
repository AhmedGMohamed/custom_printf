#include "main.h"
/**
 * get_flags - Checks for flag sub-specifiers in the format specifier
 * @format: the main printf string
 *
 * Return: sum - the sum of numbers which indicate which flags were found
 */
int get_flags(const char **format)
{
	int sum = 0;

	while (**format)
	{
		if (**format == '-')
			sum += F_MINUS;
		else if (**format == '+')
			sum += F_PLUS;
		else if (**format == ' ')
			sum += F_SPACE;
		else if (**format == '#')
			sum += F_HASH;
		else if (**format == '0')
			sum += F_ZERO;
		else
			return (sum);
		(*format)++;
	}
	return (sum);
}
/**
 * get_width - Checks for width sub-specifier
 * @format: the main printf string
 * @list: the list of arguments supplied to the printf function
 *
 * Return: width - the amount of padding required for the specifier
 */
int get_width(const char **format, va_list list)
{
	int width = 0;

	if (**format == '*')
	{
		(*format)++;
		return (va_arg(list, int));
	}
	else
	{
		while (**format >= '0' && **format <= '9')
		{
			width += **format - '0';
			width *= 10;
			(*format)++;
		}
		width /= 10;
	}
	return (width);
}
/**
 * get_precision - Checks for precision sub-specifiers
 * @format: the main printf string
 * @list: the list of arguments supplied to the printf function
 *
 * Return: -1 if the precision sub-specifier wasn't used
 *	   precision - the precision (number) specified in the format string
 */
int get_precision(const char **format, va_list list)
{
	int precision = 0;

	if (**format == '.')
	{
		(*format)++;
		if (**format == '*')
		{
			(*format)++;
			return (va_arg(list, int));
		}
		else
		{
			while (**format >= '0' && **format <= '9')
			{
				precision += **format - '0';
				(*format)++;
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
 *
 * Return: sum - the sum of numbers which indicate which modifier was found
 */
int get_size(const char **format)
{
	if (**format == 'l')
	{
		(*format)++;
		return (S_LONG);
	}
	else if (**format == 'h')
	{
		(*format)++;
		return (S_SHORT);
	}
	return (0);
}
/**
 * get_type - returns the function matching the type of specifier
 * @format: a pointer to the main printf string
 *
 * Return: a struct containing a character and the corresponding print function
 */
fmt_t get_type(const char **format)
{
	int cntr = 0;
	fmt_t functions[] = {
		{'%', (*print_char)},
		{'c', (*print_char)},
		{'s', (*print_string)},
		{'b', (*print_binary)},
		{'N', NULL}
	};

	while (functions[cntr].fmt != **format && functions[cntr].fmt != 'N')
		cntr++;
	if (functions[cntr].fmt == 'N')
	{
		while (**format != '%')
			(*format)--;
	}
	return (functions[cntr]);
}
