/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 10:08:39 by hnoh              #+#    #+#             */
/*   Updated: 2021/01/24 22:01:13 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_vsprintf_set(char *fmt, char *tmp,
		char *str, va_list args)
{
	tmp = ft_vsprintf_percentsign(fmt, str);
	tmp = ft_vsprintf_flag(tmp);
	tmp = ft_vsprintf_width(tmp, args);
	tmp = ft_vsprintf_precision(tmp, args);
	tmp = ft_vsprintf_conversion(tmp);
	while (*tmp)
	{
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
		tmp++;
	}
}

int			ft_vsprintf(char *buf, char *fmt, va_list args)
{
	char 			*tmp;
	char 			*str;
	unsigned long	num;

	str = NULL;
	tmp = NULL;
	ft_vsprintf_set(fmt, tmp, str, args);
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
	*str = '\0';
	return (str - buf);
}
