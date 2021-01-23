/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogeun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 11:41:26 by nogeun            #+#    #+#             */
/*   Updated: 2021/01/23 11:50:52 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_vsprintf_s.c(va_list args)
{
	const char	*s;
	int 		len;
	int			i;

	s = v_arg(args, char *);
	len = strnlen(s, precision);

	if (!(flags & LEFT))
		while (len < field_width--)
			*str++ = ' ';
	i = 0;
	while (i < len)
	{
		*str++ = *s++;
		i++;
	}
	while (len < field_width--)
		*str++ = ' ';
}
