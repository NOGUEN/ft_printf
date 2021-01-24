/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_defaultact.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogeun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:02:36 by nogeun            #+#    #+#             */
/*   Updated: 2021/01/24 18:11:28 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_defaultact(char *str, char *tmp)
{
	if (g_checker == 0)
	{
		*str++ = '%';
		if (*tmp)
			*str++ = *tmp;
		else
			--tmp;
	}
}
