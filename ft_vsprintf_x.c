/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogeun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 11:51:58 by nogeun            #+#    #+#             */
/*   Updated: 2021/02/12 11:57:57 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_vsprintf_x(char **tmp, va_list *ap)
{
	if (**tmp == 'x')
	{
		g_n = va_arg(*ap, unsigned int);
		if (g_flags & ALTFLAG)
		{
			ft_puts('0');
			ft_puts((g_flags & CAPSFLAG) ? 'X' : 'x');
		}
		g_base = 16;
		g_checker = 3;
	}
}
