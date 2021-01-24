/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogeun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 12:39:48 by nogeun            #+#    #+#             */
/*   Updated: 2021/01/24 18:20:54 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		if_LEFT()
{
	if (g_flags & LEFT)
		g_flags &= ~ZEROPAD;
}

void		if_SIGN(long num)
{
	if (g_flags & SIGN)
	{
		if (num < 0)
		{
			g_sign = '-';
			num = -(num);
			g_field_width--;
		}
		else if (g_flags & PLUS)
		{
			g_sign = '+';
			g_field_width--;
		}
		else if (g_flags & SPACE)
		{
			g_sign = ' ';
			g_field_width--;
		}
	}
}

void		if_SPECIAL()
{
	if (g_flags & SPECIAL)
	{
		if (g_base == 16)
			(g_field_width) -= 2;
		else if (g_base == 8)
			(g_field_width)--;
	}
}

void		if_SPECIAL2(char *str)
{
	if (g_flags & SPECIAL)
	{
		if (g_base == 8)
			*str++ = '0';
		else if (g_base == 16)
		{
			*str++ = '0';
			*str++ = ('X' | g_locase);
		}
	}
}
