/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogeun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 11:30:09 by nogeun            #+#    #+#             */
/*   Updated: 2021/01/28 11:43:04 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_vsprintf_c(char **tmp, char **str, va_list *args)
{
	if (**tmp == 'c')
	{
        g_checker = 2;
		if (!(g_flags & LEFT))
		{
			while (--g_field_width > 0)
				**str++ = ' ';
		}
		**str = (unsigned char)va_arg(*args, int);
		(*str)++;
		while (--g_field_width > 0)
			**str++ = ' ';
    }
}
