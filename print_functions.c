#include "main.h"
/**
 * print_char - replaces format specifier with formatted input in the buffer
 * @types: a list of arguments supplied with the printf function
 * @buffer: the buffer to output the text to
 * @i: the current index in the buffer
 * @flags: a summed number representing flags supplied in the format specifier
 * @width: the padding to output to the buffer
 * @precision: the precision value sub-specifer supplied in the format spefier
 * @size: a number specifying long or short sizes
 *
 * Return: printed - the number of printed characters to the buffer
 */
int print_char(va_list types, char buffer[], int *i,
	int flags, int width, int precision, int size)
{
	int printed = 1, it;

	UNUSED(precision);
	UNUSED(size);
	if (width)
	{
		if ((F_MINUS & flags) == F_MINUS)
		{
			buffer[(*i)++] = (char)va_arg(types, int);
			for (it = 0; it < width - 1; it++, (*i)++, printed++)
				buffer[*i] = ' ';
		}
		else
		{
			for (it = 0; it < width - 1; it++, (*i)++, printed++)
				buffer[*i] = ' ';
			buffer[(*i)++] = (char)va_arg(types, int);
		}
	}
	else
		buffer[(*i)++] = (char)va_arg(types, int);
	return (printed);
}
/**
 * print_string - Replaces string format specifier with formated string
 * @types: a list of arguments supplied with the printf function
 * @buffer: the buffer to output the text to
 * @i: the current index in the buffer
 * @flags: a summed number representing flags supplied in the format specifier
 * @width: the padding to output to the buffer
 * @precision: the precision value sub-specifer supplied in the format spefier
 * @size: a number specifying long or short sizes
 *
 * Return: printed - the number of printed characters to the buffer
 */
int print_string(va_list types, char buffer[], int *i,
	int flags, int width, int precision, int size)
{
	int printed = 0, len = 0, it, j = 0;
	char *final = va_arg(types, char *), tmp_buff[BUFF_SIZE];

	UNUSED(precision);
	UNUSED(size);
	if (final == NULL)
		final = "(null)";
	while (*final != '\0')
	{
		if (*final == '\\')
			convert_escape(++final, (tmp_buff + j));
		else
			tmp_buff[j] = *final;
		final++, len++, j++;
	}
	if (width - len > 0)
	{
		if ((F_MINUS & flags) == F_MINUS)
		{
			for (it = 0; it < len; it++, printed++)
				buffer[(*i)++] = tmp_buff[it];
			for (it = 0; it < width - len; it++, printed++)
				buffer[(*i)++] = ' ';
		}
		else
		{
			for (it = 0; it < width - len; it++, printed++)
				buffer[(*i)++] = ' ';
			for (it = 0; it < len; it++, printed++)
				buffer[(*i)++] = tmp_buff[it];
		}
	}
	else
		for (it = 0; it < len; it++, printed++)
			buffer[(*i)++] = tmp_buff[it];
	return (printed);
}
