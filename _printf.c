#include "main.h"

/**
 * _printf - function like printf
 * @format: string whit format to print
 * Return: number of chars that print
 */

int _printf(const char *format, ...)
{
	int printed = 0, i = 0, f, w, p, s;
	char buffer[BUFF_SIZE];
	va_list args;
	fmt_t func;

	va_start(args, format);
	if (!format)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			f = get_flags(&format);
			w = get_width(&format, args);
			p = get_precision(&format, args);
			s = get_size(&format);
			func = get_type(&format);
			if (func.fmt != 'N')
				if (func.fmt == '%')
					buffer[i++] = '%', printed++;
				else
					printed += func.fn(args, buffer,
							&i, f, w, p, s);
			else
				buffer[i++] = *format, printed++;
		}
		else
			buffer[i++] = *format, printed++;
		format++;
	}
	va_end(args);
	return (write(1, buffer, printed));
}
