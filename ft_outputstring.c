/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outputstring.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogeun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 14:04:45 by nogeun            #+#    #+#             */
/*   Updated: 2021/02/09 14:51:22 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_outputstring(char **str)
{
	int		i;
	char	c;
	char	sign;
	char 	*digits;

	if (g_flags & CAPSFLAG)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	ft_outputstring1(&c);
	ft_outputstring2(&sign);
	ft_outputstring3(str, &i, digits);
	ft_outputstring4(str, &sign, &c);
	ft_outputstring5(str, &i);
}
