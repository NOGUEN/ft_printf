/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogeun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 11:30:09 by nogeun            #+#    #+#             */
/*   Updated: 2021/01/23 11:40:54 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_vsprintf_c(char *tmp, va_list args)
{
	if (*tmp == 'c')
	{
		if (!(flags & LEFT))
		{
			while (--field_width > 0)
				*str++ = ' ';
		}
		*str++ (unsigned char)va_arg(args, int);
		while (--field_width > 0)
			*str++ = ' ';
	}
}
