/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 10:43:38 by hnoh              #+#    #+#             */
/*   Updated: 2021/01/23 11:15:37 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_vsprintf_percentsign(const char *fmt, char **str)
{
	char	*tmp;

	tmp = (char *)fmt;
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
	static int		flags;

	flags = 0;
	while (is_flag(++tmp))
	{
		if (*tmp == '-')
			flags |= LEFT;
		else if (*tmp == '+')
			flags |= PLUS;
		else if (*tmp == ' ')
			flags |= SPACE;
		else if (*tmp == '#')
			flags |= SPECIAL;
		else if (*tmp == '0')
			flags |= ZEROPAD;
	}
	return (tmp);
}

char		*ft_vsprintf_width(char *tmp, va_list args)
{
	static int		field_width;

	field_width = -1;
	if (ft_isdigit(*tmp))
		field_width = skip_atoi(&tmp);
	else if (*fmt == '*')
	{
		++tmp;
		field_width = va_arg(args, int);
		if (field_width < 0)
		{
			field_width = -field_width;
			flags |= LEFT;
		}
	}
	return (tmp);
}

char		*ft_vsprintf_precision(char *tmp, va_list args)
{
	static int		precision = -1;

	if (*tmp == '.')
	{
		++tmp;
		if (ft_isdigit(*fmt))
		{
			precision = ft_skip_atoi(&fmt);
		}
		else if (*tmp == '*')
		{
			++tmp;
			precision = va_arg(args, int);
		}
	}
	if (precision < 0)
		precision = 0;
	return (tmp);
}

char		*ft_vsprintf_conversion(char *tmp)
{
	static int	qualifier;

	qualifier = -1;
	if (*fmt == 'h' || *fmt == '1' || *fmt == 'L')
	{
		qualifier = *tmp;
		++tmp;
	}
	return (tmp);
}
