/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 10:08:39 by hnoh              #+#    #+#             */
/*   Updated: 2021/02/08 19:27:59 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					g_uc;
int					g_flags;
int					g_format_num;
int					g_precision;
int					g_checker;
long				g_n;
char				g_tmp[100];
int					g_base;

void		ft_vsprintf_case(char **tmp, char **str, va_list *ap)
{
	g_checker = 0;
	ft_vsprintf_asterisk(tmp, ap);
	ft_vsprintf_digit(tmp);
	ft_vsprintf_point(tmp);
	ft_vsprintf_per(tmp, str);
	ft_vsprintf_c(tmp, str, ap);
	ft_vsprintf_s(tmp, str, ap);
	ft_vsprintf_minus(tmp);
	ft_vsprintf_plus(tmp);
	ft_vsprintf_hash(tmp);
	ft_vsprintf_i(tmp, ap);
	ft_vsprintf_d(tmp, ap);
	ft_vsprintf_u(tmp, ap);
	ft_vsprintf_p(tmp, ap);
	ft_vsprintf_bx(tmp, str, ap);
	ft_vsprintf_x(tmp, str, ap);
	ft_defaultact(tmp, str);
}

void		ft_vsprintf_outputstring(char **str)
{
	int				i;
	char			c;
	char			sign;
	char			*digits;

	if (g_flags & CAPSFLAG)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	if (g_precision == 0)
		g_flags |= PREZEROFLAG;
	if (g_format_num > g_precision)
		g_flags |= BIGFORMATFLAG;
	c = (g_flags & LEADZEROFLAG) ? '0' : ' ';
	sign = 0;
	if (g_flags & SIGNEDFLAG)
	{	
		if (g_n < 0)
		{
			sign = '-';
			g_n = -g_n;
			g_format_num--;
		}
		else if (g_flags & SHOWSIGNFLAG)
		{
			sign = '+';
			g_format_num--;
		}
	}
	i = 0;
	if (g_n == 0 && (g_flags & POINTFLAG) && (g_flags & PREZEROFLAG)
			&& !(g_flags & MINUSPREFLAG))
		g_tmp[0] = '\0';
	else if (g_n == 0)
		g_tmp[i++] = '0';
	else
		while (g_n != 0)
			g_tmp[i++] = digits[ft_do_div(&g_n, g_base)];
	if (i > g_precision)
		g_precision = i;
	g_format_num -= g_precision;
	if (g_flags & POINTERFLAG)
		g_format_num -= 2;
	if (!(g_flags & (LEADZEROFLAG + LEFTFORMATFLAG)) || 
			((g_flags & BIGFORMATFLAG) && (g_flags & LEADZEROFLAG) 
			 && (g_flags & POINTFLAG) && !(g_flags & LEFTFORMATFLAG)
			 && !(g_flags & MINUSPREFLAG)))
		while (g_format_num-- > 0)
			*(*str)++ = ' ';
	if (g_flags & POINTERFLAG)
	{
		*(*str)++ = '0';
		*(*str)++ = 'x';
	}
	if (sign)
		*(*str)++ = sign;
	if (!(g_flags & LEFTFORMATFLAG))
	{
		if ((g_flags & BIGFORMATFLAG) && (g_flags & POINTFLAG) 
			&& !(g_flags & MINUSPREFLAG))
			c = ' ';
		while (g_format_num-- > 0)
			*(*str)++ = c;
	}
	while (i < g_precision--)
		*(*str)++ = '0';
	while (i-- >  0)
		*(*str)++ = g_tmp[i];
	while (g_format_num-- > 0)
		*(*str)++ = ' ';
}

int			ft_vsprintf(char *buf, char *tmp, va_list ap)
{
	char				*str;

	str = buf;
	g_checker = 0;
	while (1)
	{
		// find %(1)
		while (*tmp != 0)
		{
			if (*tmp == '%' || g_checker == 2)
				break ;
			*str++ = *tmp++;
		}
		if (g_checker != 2)
		{
			if (*tmp == 0)
				break ;
			g_flags = 0;
			g_format_num = 0;
			g_precision = 0;
			g_base = 10;
		}
		// next_format (2)
		tmp++;
		if (*tmp == 0)
			break ;
		ft_vsprintf_case(&tmp, &str, &ap);
		if (g_checker == 1 || g_checker == 2)
		{
			if (g_checker == 1)
				tmp++;
			continue ;
		}
		// output_string (3)
		else if (g_checker == 3)
		{
			tmp++;
			ft_vsprintf_outputstring(&str);
			continue ;
		}
	}
	*str = 0;
	return (str - buf);
}
