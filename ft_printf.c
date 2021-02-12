/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 10:57:32 by hnoh              #+#    #+#             */
/*   Updated: 2021/02/12 11:49:34 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		err;
	char	*tmp;

	va_start(ap, format);
	tmp = (char *)format;
	err = ft_vsprintf(tmp, &ap);
	va_end(ap);
	return (err);
}
