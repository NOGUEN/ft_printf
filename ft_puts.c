/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogeun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 10:04:41 by nogeun            #+#    #+#             */
/*   Updated: 2021/02/09 12:43:28 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_puts(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 7 && g_nullchecker[i] == 1)
			write(STDOUT_FILENO, "\x00", 1);
		else
			write(STDOUT_FILENO, &str[i], 1);
		i++;
	}
}
