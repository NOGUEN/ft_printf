/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 10:43:38 by hnoh              #+#    #+#             */
/*   Updated: 2021/01/25 12:04:15 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		g_flags;
int		g_field_width;
int		g_precision;
int		g_qualifier;
int		g_checker;

char		*ft_vsprintf_percentsign(char *tmp, char *str)
{
	while (*tmp != '%')
	{
		*str++ = *tmp;
		tmp++;
	}
	if (*tmp == 0)
	{
		return (tmp);
	}
	return (tmp);
}

char		*ft_vsprintf_flag(char *tmp)
{
	g_flags = 0;
	while (ft_isflag(++tmp))
	{
		if (*tmp == '-')
			g_flags |= LEFT;
		else if (*tmp == '+')
			g_flags |= PLUS;
		else if (*tmp == ' ')
			g_flags |= SPACE;
		else if (*tmp == '#')
			g_flags |= SPECIAL;
		else if (*tmp == '0')
			g_flags |= ZEROPAD;
		else
			return (tmp);
	}
	return (tmp);
}

char		*ft_vsprintf_width(char *tmp, va_list args)
{
	g_field_width = -1;
	if (ft_isdigit(*tmp))
		g_field_width = ft_skip_atoi(&tmp);
	else if (*tmp == '*')
	{
		++tmp;
		g_field_width = va_arg(args, int);
		if (g_field_width < 0)
		{
			g_field_width = -g_field_width;
			g_flags |= LEFT;
		}
	}
	return (tmp);
}

char		*ft_vsprintf_precision(char *tmp, va_list args)
{
	g_precision = -1;
	if (*tmp == '.')
	{
		++tmp;
		if (ft_isdigit(*tmp))
		{
			g_precision = ft_skip_atoi(&tmp);
		}
		else if (*tmp == '*')
		{
			++tmp;
			g_precision = va_arg(args, int);
		}
	}
	if (g_precision < 0)
		g_precision = 0;
	return (tmp);
}

char		*ft_vsprintf_conversion(char *tmp)
{
	g_qualifier = -1;
	if (*tmp == 'h' || *tmp == '1' || *tmp == 'L')
	{
		g_qualifier = *tmp;
		++tmp;
	}
	return (tmp);
}
