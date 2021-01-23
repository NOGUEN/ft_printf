/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf_p.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogeun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 11:51:04 by nogeun            #+#    #+#             */
/*   Updated: 2021/01/23 11:55:28 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_vsprintf_p()
{
	if (field_width == -1)
	{
		field_width = 2 * sizeof(void *);
		flags |= ZEROPAD;
	}
	str = number(str,
			(unsigned long)va_arg(args, void *), 16,
			field_width, precision, flags);
}
