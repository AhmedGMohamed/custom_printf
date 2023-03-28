#include "main.h"
/**
 * convert_escape - converts escape characters for printf int one char
 * @src: the string containing the unconverted escape character
 * @dest: the string to put the converted escape character into
 */
void convert_escape(char *src, char *dest)
{
	if (*src == 'a')
		*dest = '\a';
	else if (*src == 'b')
		*dest = '\b';
	else if (*src == 'f')
		*dest = '\f';
	else if (*src == 'n')
		*dest = '\n';
	else if (*src == 'r')
		*dest = '\r';
	else if (*src == 't')
		*dest = '\t';
	else if (*src == 'v')
		*dest = '\v';
	else
		*dest = *src;
}
