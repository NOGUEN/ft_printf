/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 10:57:32 by hnoh              #+#    #+#             */
/*   Updated: 2021/02/08 19:18:38 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		err;
	char	*tmp;
	char	printf_buf[10000];

	va_start(ap, format);
	tmp = (char *)format;
	err = ft_vsprintf(printf_buf, tmp, ap);
	va_end(ap);
	ft_puts(printf_buf);
	return (err);
}
