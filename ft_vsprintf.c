/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 10:08:39 by hnoh              #+#    #+#             */
/*   Updated: 2021/02/12 12:39:32 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					g_flags;
int					g_format_num;
int					g_precision;
int					g_checker;
long				g_n;
char				g_tmp[100];
int					g_base;
int					g_cchecker;
int					g_exitloop;

void		ft_vsprintf_case(char **tmp, va_list *ap)
{
	g_checker = 0;
	ft_vsprintf_asterisk(tmp, ap);
	ft_vsprintf_digit(tmp);
	ft_vsprintf_point(tmp);
	ft_vsprintf_per(tmp);
	ft_vsprintf_space(tmp);
	ft_vsprintf_c(tmp, ap);
	ft_vsprintf_s(tmp, ap);
	ft_vsprintf_minus(tmp);
	ft_vsprintf_plus(tmp);
	ft_vsprintf_hash(tmp);
	ft_vsprintf_i(tmp, ap);
	ft_vsprintf_d(tmp, ap);
	ft_vsprintf_u(tmp, ap);
	ft_vsprintf_p(tmp, ap);
	ft_vsprintf_bx(tmp, ap);
	ft_vsprintf_x(tmp, ap);
	ft_vsprintf_o(tmp, ap);
	ft_defaultact(tmp);
}

void		ft_vsprintf_put(char **tmp)
{
	while (**tmp != 0)
	{
		if (**tmp == '%' || g_checker == 2)
			break ;
		ft_puts(*(*tmp)++);
	}
	if (g_checker != 2)
	{
		if (**tmp == 0)
		{
			g_exitloop = 1;
			return ;
		}
		g_flags = 0;
		g_format_num = 0;
		g_precision = 0;
		g_base = 10;
	}
}

void		ft_vsprintf_setstr(void)
{
	g_checker = 0;
	g_cchecker = 0;
	g_exitloop = 0;
}

void		ft_vsprintf_continue(char **tmp)
{
	if (g_checker == 1 || g_checker == 2)
	{
		if (g_checker == 1)
			(*tmp)++;
		g_exitloop = 2;
		return ;
	}
	else if (g_checker == 3)
	{
		(*tmp)++;
		ft_outputstring();
		g_exitloop = 2;
		return ;
	}
}

int			ft_vsprintf(char *tmp, va_list *ap)
{
	ft_vsprintf_setstr();
	while (1)
	{
		ft_vsprintf_put(&tmp);
		if (g_exitloop == 1)
			break ;
		tmp++;
		if (*tmp == 0)
			break ;
		ft_vsprintf_case(&tmp, ap);
		ft_vsprintf_continue(&tmp);
		if (g_exitloop == 2)
			continue ;
	}
	return (g_cchecker);
}
