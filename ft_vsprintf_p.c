/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf_p.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogeun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 11:51:04 by nogeun            #+#    #+#             */
/*   Updated: 2021/02/08 12:01:03 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_vsprintf_p(char **tmp, va_list *ap)
{
	if (**tmp == 'p')
	{
		g_flags |= POINTERFLAG | ALTFLAG;
		if (g_format_num == -1)
		{
			g_format_num = 2 * sizeof(void *);
			g_flags |= LEADZEROFLAG;
		}
		g_n = (unsigned long)va_arg(*ap, void *);
		g_base = 16;
		g_checker = 3;
	}
}
