#include "ft_printf.h"
#include <stdio.h>
#include <string.h>

int main ()
{
	char *c = "abcdefghijklmnop";
	printf("%zu\n", ft_strnlen(c, 14));
	ft_printf("%c,  %-c, %1c, %*c,  %-*c,  %*c, %-*c", 'a', 'a', '-', 12, '-', 12, 0, 12 ,'%' ,12, 'a');


}
