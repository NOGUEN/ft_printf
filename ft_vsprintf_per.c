/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf_per.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogeun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 12:23:56 by nogeun            #+#    #+#             */
/*   Updated: 2021/02/12 12:20:15 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_vsprintf_per(char **tmp)
{
	char		c;

	if (**tmp == '%')
	{
		c = (g_flags & LEADZEROFLAG) ? '0' : ' ';
		if (!(g_flags & LEFTFORMATFLAG))
			while (--g_format_num > 0)
				ft_puts(c);
		ft_puts('%');
		while (--g_format_num > 0)
			ft_puts(' ');
		g_checker = 1;
	}
}
