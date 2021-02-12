/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogeun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 11:30:09 by nogeun            #+#    #+#             */
/*   Updated: 2021/02/12 12:17:36 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_vsprintf_c(char **tmp, va_list *ap)
{
	int		t;

	t = 0;
	if (**tmp == 'c')
	{
		if (!(g_flags & LEFTFORMATFLAG))
			while (--g_format_num > 0)
				ft_puts(' ');
		t = va_arg(*ap, int);
		if (t == 0)
			ft_puts(0);
		else
			ft_puts(t);
		while (--g_format_num > 0)
			ft_puts(' ');
		g_checker = 1;
	}
}
