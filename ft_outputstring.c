/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outputstring.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogeun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 14:04:45 by nogeun            #+#    #+#             */
/*   Updated: 2021/02/12 12:39:49 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_outputstring(void)
{
	int		i;
	char	c;
	char	sign;
	char	*digits;

	if (g_flags & CAPSFLAG)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	ft_outputstring1(&c);
	ft_outputstring2(&sign);
	ft_outputstring3(&i, digits);
	ft_outputstring4(&sign, &c);
	ft_outputstring5(&i);
}
