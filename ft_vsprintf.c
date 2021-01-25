/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 10:08:39 by hnoh              #+#    #+#             */
/*   Updated: 2021/01/25 12:51:18 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_vsprintf_set(char *tmp,
		char *str, va_list args)
{
	tmp = ft_vsprintf_percentsign(tmp, str);
	tmp = ft_vsprintf_flag(tmp);
	tmp = ft_vsprintf_width(tmp, args);
	tmp = ft_vsprintf_precision(tmp, args);
	tmp = ft_vsprintf_conversion(tmp);
	g_checker = 0;
	ft_vsprintf_c(tmp, str, args);
	ft_vsprintf_s(tmp, str, args);
	ft_vsprintf_p(tmp);
	ft_vsprintf_d(tmp);
	ft_vsprintf_i(tmp);
	ft_vsprintf_u(tmp);
	ft_vsprintf_x(tmp);
	ft_vsprintf_bx(tmp);
	ft_vsprintf_per(tmp, str);
	ft_defaultact(str, tmp);
}

int			ft_vsprintf(char *buf, char *tmp, va_list args)
{
	unsigned long	num;
	char 			*str;

	str = buf;
	while (*tmp)
	{
		ft_vsprintf_set(tmp, str, args);
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
		str = ft_number(str, num);
		tmp++;
	}
	*str = '\0';
	return (str - buf);
}
