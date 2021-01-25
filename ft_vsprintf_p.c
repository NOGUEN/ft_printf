/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf_p.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogeun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 11:51:04 by nogeun            #+#    #+#             */
/*   Updated: 2021/01/24 22:00:37 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_vsprintf_p(char *tmp)
{
	if (*tmp == 'p')
	{
        g_checker = 1;
		if (g_field_width == -1)
		{
			g_field_width = 2 * sizeof(void *);
			g_flags |= ZEROPAD;
		}
	}
}
