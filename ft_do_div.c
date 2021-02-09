/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_div.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogeun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 13:05:16 by nogeun            #+#    #+#             */
/*   Updated: 2021/02/05 10:05:37 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_do_div(long *n, int base)
{
	int		res;
	res = ((unsigned long) *n) % (unsigned) base;
	*n = ((unsigned long) *n) / (unsigned) base;
	return (res);
}
