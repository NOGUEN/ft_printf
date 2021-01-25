/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogeun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 12:30:56 by nogeun            #+#    #+#             */
/*   Updated: 2021/01/24 21:57:13 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			g_locase;
char		*g_digits;
char		g_tmp[66];
char		g_c;
char		g_sign;
int			g_i;

void	ft_number2(char *str);

char	*ft_number(char *str, long num)
{
	g_digits = "0123456789ABCDEF";
	g_locase = (g_flags & SMALL);
	if_LEFT();
	if (g_base < 2 || g_base > 16)
		return (NULL);
	g_c = (g_flags & ZEROPAD) ? '0' : ' ';
	g_sign = 0;
	if_SIGN(num);
	if_SPECIAL();
	g_i = 0;
	if (num == 0)
		g_tmp[g_i++] = '0';
	else
		while (num != 0)
			g_tmp[g_i++] = (g_digits[ft_do_div(num, g_base)] | g_locase);
	if (g_i > g_precision)
		g_precision = g_i;
	g_field_width -= g_precision;
	ft_number2(str);
	return (str);
}

void	ft_number2(char *str)
{
	if (!(g_flags & (ZEROPAD + LEFT)))
		while (g_field_width-- > 0)
			*str++ = ' ';
	if (g_sign)
		*str++ = g_sign;
	if_SPECIAL2(str);
	if (!(g_flags & LEFT))
		while (g_field_width-- > 0)
			*str++ = g_c;
	while (g_i < g_precision--)
		*str++ = '0';
	while (g_i-- > 0)
		*str++ = g_tmp[g_i];
	while (g_field_width-- > 0)
		*str++ = ' ';
}
