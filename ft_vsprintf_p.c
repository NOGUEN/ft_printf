/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf_p.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogeun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 11:51:04 by nogeun            #+#    #+#             */
/*   Updated: 2021/01/28 12:09:19 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_vsprintf_p(char **tmp, char **str, va_list *args)
{
	if (**tmp == 'p')
	{
        g_checker = 2;
		if (g_field_width == -1)
		{
			g_field_width = 2 * sizeof(void *);
			g_flags |= ZEROPAD;
		}
		*str = ft_number(str, (unsigned long)va_arg(*args, void *), 16, g_field_width,
				g_precision, g_flags);
	}
}
