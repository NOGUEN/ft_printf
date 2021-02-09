/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogeun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 11:30:09 by nogeun            #+#    #+#             */
/*   Updated: 2021/02/08 19:30:02 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_vsprintf_c(char **tmp, char **str, va_list *ap)
{
	int		t;
	if (**tmp == 'c')
	{
		if (!(g_flags & LEFTFORMATFLAG))
			while (--g_format_num > 0)
				*(*str)++ = ' ';
		t = va_arg(*ap, int);
		if (t == 0)
			*(*str)++ = 127;
		else
			*(*str)++ = (unsigned char)t;
		while (--g_format_num > 0)
			*(*str)++ = ' ';
		g_checker = 1;
    }
}
