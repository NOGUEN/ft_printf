/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogeun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 11:41:26 by nogeun            #+#    #+#             */
/*   Updated: 2021/02/12 11:57:23 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_vsprintf_s(char **tmp, va_list *ap)
{
	int				len;
	char			*s;
	int				i;
	char			c;

	if (**tmp == 's')
	{
		s = va_arg(*ap, char *);
		if (s == 0)
			s = "(null)";
		len = ft_strnlen(s, g_precision);
		if (!(g_flags & POINTFLAG) || (g_flags & MINUSPREFLAG))
			len = ft_strlen(s);
		c = (g_flags & LEADZEROFLAG) ? '0' : ' ';
		if (!(g_flags & LEFTFORMATFLAG))
			while (len < g_format_num--)
				ft_puts(c);
		i = 0;
		while (i++ < len)
			ft_puts(*s++);
		while (len < g_format_num--)
			ft_puts(' ');
		g_checker = 1;
	}
}
