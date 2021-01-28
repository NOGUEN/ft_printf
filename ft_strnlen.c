/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogeun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 12:12:54 by nogeun            #+#    #+#             */
/*   Updated: 2021/01/27 11:58:32 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_strnlen(char *s, size_t maxlen)
{
	size_t len;

	len = 0;
	while (len < maxlen)
	{
		if (!*s)
			break;
		s++;
		len++;
	}
	return (len);
}
