/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf_digit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogeun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 12:29:14 by nogeun            #+#    #+#             */
/*   Updated: 2021/02/06 11:51:23 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_vsprintf_digit(char **tmp)
{
	if (ft_isdigit(**tmp))
	{
		if (**tmp == '0' && g_format_num == 0)
			g_flags |= LEADZEROFLAG;
		if (g_flags & POINTFLAG)
		{
			g_precision *= 10;
			g_precision += **tmp - '0';
		}
		else
		{
			g_format_num *= 10;
			g_format_num += **tmp - '0';
		}
		g_checker = 2;
	}
}
