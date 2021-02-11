/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogeun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 07:18:30 by nogeun            #+#    #+#             */
/*   Updated: 2021/02/12 07:31:49 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		*ft_memset(void *dest, int c, size_t len)
{
	unsigned char	*string;

	string = (unsigned char *)dest;
	while (len-- > 0)
		*(string++) = (unsigned char)c;
	return (dest);
}
