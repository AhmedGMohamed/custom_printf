#include "main.h"
/**
 * get_flags - Checks for flag types in the format specifier
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
