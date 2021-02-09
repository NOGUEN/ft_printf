/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf_asterisk.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogeun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 12:46:51 by nogeun            #+#    #+#             */
/*   Updated: 2021/02/06 09:38:13 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_vsprintf_asterisk(char **tmp, va_list *ap)
{
	if (**tmp == '*')
	{
		if (g_flags & POINTFLAG)
		{
			g_precision = va_arg(*ap ,int);
			if (g_precision < 0)
			{
				g_precision = 0;
				g_flags |= MINUSPREFLAG;
			}
			g_flags |= ASTERISKFLAG;
		}
		else
		{
			g_format_num = va_arg(*ap, int);
			if (g_format_num < 0)
			{
				g_format_num = -g_format_num;
				g_flags |= LEFTFORMATFLAG;
			}
		}
		g_checker = 2;
	}
}
