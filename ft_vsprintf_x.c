/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogeun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 11:51:58 by nogeun            #+#    #+#             */
/*   Updated: 2021/02/08 11:24:33 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_vsprintf_x(char **tmp, char **str, va_list *ap)
{
	if (**tmp == 'x')
	{
		if (g_flags & LONGLONGFLAG)
			g_n = va_arg(*ap, unsigned long long);
		if (g_flags & LONGFLAG)
			g_n = va_arg(*ap, unsigned long);
		if (g_flags & HALFHALFFLAG)
			g_n = (unsigned char)va_arg(*ap, unsigned int);
		if (g_flags & HALFFLAG)
			g_n = (unsigned short)va_arg(*ap, unsigned int);
		if (g_flags & SIZETFLAG)
			g_n = va_arg(*ap, size_t);
		else
			g_n = va_arg(*ap, unsigned int);
		if (g_flags & ALTFLAG)
		{
			*(*str)++ = '0';
			*(*str)++ = (g_flags & CAPSFLAG) ? 'X' : 'x';
		}
		g_base = 16;
		g_checker = 3;
	}
}
