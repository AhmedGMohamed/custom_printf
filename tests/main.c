#include "main.h"
void foo(int n, char buffer[], int f, int w, int p, int s, ...)
{
	int i = n;
	va_list list;
	va_start(list, s);
	print_char(list, buffer, &i, f, w, p, s); 
}
int main(void)
{
	int i = 1, f, w, p, s;
	char buffer[BUFF_SIZE];
	va_list list;
	f = get_flags("%-+5.5c", &i);
	w = get_width("%-+5.5c", &i, list);
	p = get_precision("%-+5.5c", &i, list);
	s = get_size("%-+5.5c", &i);
	foo(0, buffer, f, w, p, s, 'c');
	printf("%c, %d, %d, %d, %d", buffer[0], f, w, p, s);
}
