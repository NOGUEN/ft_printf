/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf_o.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogeun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 09:44:31 by nogeun            #+#    #+#             */
/*   Updated: 2021/02/09 09:53:20 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_vsprintf_o(char **tmp, va_list *ap)
{
	if (**tmp == 'o')
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
		g_base = 8;
		g_checker = 3;
	}
}
