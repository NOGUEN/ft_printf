/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf_outputstring.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogeun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 13:15:29 by nogeun            #+#    #+#             */
/*   Updated: 2021/02/09 19:11:12 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_outputstring1(char *c)
{
	if (g_precision == 0)
		g_flags |= PREZEROFLAG;
	if (g_format_num > g_precision)
		g_flags |= BIGFORMATFLAG;
	*c = (g_flags & LEADZEROFLAG) ? '0' : ' ';
}

void		ft_outputstring2(char *sign)
{
	*sign = 0;
	if (g_flags & SIGNEDFLAG)
	{
		if (g_n < 0)
		{
			*sign = '-';
			g_n = -g_n;
			g_format_num--;
		}
		else if (g_flags & SHOWSIGNFLAG)
		{
			*sign = '+';
			g_format_num--;
		}
		else if (g_flags & SPACEFLAG)
		{
			*sign = ' ';
			g_format_num--;
		}
	}
}

void		ft_outputstring3(char **str, int *i, char *digits)
{
	(*i) = 0;
	if (g_n == 0 && (g_flags & POINTFLAG) && (g_flags & PREZEROFLAG)
			&& !(g_flags & MINUSPREFLAG))
		g_tmp[0] = '\0';
	else if (g_n == 0)
		g_tmp[(*i)++] = '0';
	else
		while (g_n != 0)
			g_tmp[(*i)++] = digits[ft_do_div(&g_n, g_base)];
	if (*i > g_precision)
		g_precision = *i;
	g_format_num -= g_precision;
	if (g_flags & POINTERFLAG)
		g_format_num -= 2;
	if (!(g_flags & (LEADZEROFLAG + LEFTFORMATFLAG)) ||
			((g_flags & BIGFORMATFLAG) && (g_flags & LEADZEROFLAG)
			&& (g_flags & POINTFLAG) && !(g_flags & LEFTFORMATFLAG)
			&& !(g_flags & MINUSPREFLAG)))
		while (g_format_num-- > 0)
			ft_outputchar(str, ' ');
}

void		ft_outputstring4(char **str, char *sign, char *c)
{
	if (g_flags & POINTERFLAG)
	{
		ft_outputchar(str, '0');
		ft_outputchar(str, 'x');
	}
	if (*sign)
		ft_outputchar(str, *sign);
	if (!(g_flags & LEFTFORMATFLAG))
	{
		if ((g_flags & BIGFORMATFLAG) && (g_flags & POINTFLAG)
				&& !(g_flags & MINUSPREFLAG))
			*c = ' ';
		while (g_format_num-- > 0)
			ft_outputchar(str, *c);
	}
}

void		ft_outputstring5(char **str, int *i)
{
	while (*i < g_precision--)
		ft_outputchar(str, '0');
	while ((*i)-- > 0)
		ft_outputchar(str, g_tmp[*i]);
	while (g_format_num-- > 0)
		ft_outputchar(str, ' ');
}
