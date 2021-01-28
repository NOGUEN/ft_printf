#include "ft_printf.h"

char *ft_number(char **str, long num, int base, int size, int precision,
		    int type)
{
	/* we are called with base 8, 10 or 16, only, thus don't need "G..."  */
	const char *digits;
	char tmp[66];
	char c, sign, locase;
	int i;

	digits = "0123456789ABCDEF";
	locase = (type & SMALL);
	if (type & LEFT)
		type &= ~ZEROPAD;
	if (base < 2 || base > 16)
		return NULL;
	c = (type & ZEROPAD) ? '0' : ' ';
	sign = 0;
	if (type & SIGN) {
		if (num < 0) {
			sign = '-';
			num = -num;
			size--;
		} else if (type & PLUS) {
			sign = '+';
			size--;
		} else if (type & SPACE) {
			sign = ' ';
			size--;
		}
	}
	if (type & SPECIAL) {
		if (base == 16)
			size -= 2;
		else if (base == 8)
			size--;
	}
	i = 0;
	if (num == 0)
	{
		tmp[i] = '0';
		i++;
	}
	else
		while (num != 0)
		{
			tmp[i] = (digits[ft_do_div(&num, base)] | locase);
			i++;
		}
	if (i > precision)
		precision = i;
	size -= precision;
	if (!(type & (ZEROPAD + LEFT)))
		while (size-- > i)
		{
			**str = ' ';
			(*str)++;
		}
	if (sign)
	{
		**str = sign;
		(*str)++;
	}
	if (type & SPECIAL) {
		if (base == 8)
		{
			**str = '0';
			(*str)++;
		}
		else if (base == 16) {
			**str = '0';
			(*str)++;
			**str = ('X' | locase);
			(*str)++;
		}
	}
	if (!(type & LEFT))
		while (size-- > 0)
		{
			**str = c;
			(*str)++;
		}
	while (i < precision--)
	{
		**str = '0';
		(*str)++;
	}
	while (i-- > 0)
	{
		**str = tmp[i];
		(*str)++;
	}
	while (size-- > 0)
	{
		**str = ' ';
		(*str)++;
	}
	return (*str);
}
