/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 10:08:39 by hnoh              #+#    #+#             */
/*   Updated: 2021/01/28 13:28:31 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			g_base;

char		*ft_vsprintf_set(char **tmp, va_list *args)
{
	*tmp = ft_vsprintf_flag(tmp);
	*tmp = ft_vsprintf_width(tmp, args);
	*tmp = ft_vsprintf_precision(tmp, args);
	*tmp = ft_vsprintf_conversion(tmp);
	return (*tmp);
}

void        ft_vsprintf_case(char **tmp, char **str, va_list *args)
{
    g_checker = 0;
    ft_vsprintf_c(tmp, str, args);
    ft_vsprintf_s(tmp, str, args);
    ft_vsprintf_p(tmp, str, args);
    ft_vsprintf_d(tmp);
    ft_vsprintf_i(tmp);
    ft_vsprintf_u(tmp);
    ft_vsprintf_x(tmp);
    ft_vsprintf_bx(tmp);
    ft_vsprintf_per(tmp, str);
}

int			ft_vsprintf(char *buf, char *tmp, va_list args)
{
	unsigned long	num;
	char 			*str;

	str = buf;
	tmp = tmp - 1;
	while (*(++tmp))
	{
		if (*tmp != '%')
		{
			*str = *tmp;
			str++;
			continue;
		}
		tmp = ft_vsprintf_set(&tmp, &args);
		g_base = 10;
		if (ft_isdigit(*tmp))
			tmp++;
		while (*tmp)
		{
			ft_vsprintf_case(&tmp ,&str, &args);
			if (g_checker == 0)
			{
				ft_defaultact(&str, &tmp);
				break;
			}
			else if (g_checker == 2 || g_checker == 1)
				break;
		}
		if (g_checker == 2)
			tmp++;
		if (g_qualifier == 'l')
			num = va_arg(args, unsigned long);
		else if (g_qualifier == 'h')
		{
			num = (unsigned short)va_arg(args, int);
			if (g_flags & SIGN)
				num = (short)num;
		}
		else if (g_flags & SIGN)
			num = va_arg(args, int);
		else
			num = va_arg(args, unsigned int);
		str = ft_number(&str, num, g_base, g_field_width, g_precision, g_flags);
	}
	if (g_precision == 0)
		*buf = '\0';
	*str = '\0';
	return (str - buf);
}
