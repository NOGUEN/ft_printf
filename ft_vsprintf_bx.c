/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf_bx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogeun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 11:59:12 by nogeun            #+#    #+#             */
/*   Updated: 2021/02/12 11:58:13 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_vsprintf_bx(char **tmp, va_list *ap)
{
	if (**tmp == 'X')
	{
		g_flags |= CAPSFLAG;
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
