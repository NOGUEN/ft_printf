/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogeun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 11:44:33 by nogeun            #+#    #+#             */
/*   Updated: 2021/02/08 11:25:11 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_vsprintf_d(char **tmp, va_list *ap)
{
	if (**tmp == 'd')
	{
		if (g_flags & LONGLONGFLAG)
			g_n = va_arg(*ap, long long);
		else if (g_flags & LONGFLAG)
			g_n = va_arg(*ap, long);
		else if (g_flags & HALFHALFFLAG)
			g_n = (signed char)va_arg(*ap, int);
		else if (g_flags & HALFFLAG)
			g_n = (short)va_arg(*ap, int);
		else if (g_flags & SIZETFLAG)
			g_n = va_arg(*ap, ssize_t);
		else
			g_n = va_arg(*ap, int);
		g_flags |= SIGNEDFLAG;
		g_base = 10;
		g_checker = 3;
	}
}
