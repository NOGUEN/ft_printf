/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 10:57:32 by hnoh              #+#    #+#             */
/*   Updated: 2021/01/24 13:45:49 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	char	printf_buf[1024];
	va_list	args;
	int		printed;
	char	*tmp;

	va_start(args, format);
	tmp = (char *)format;
	printed = ft_vsprintf(printf_buf, tmp, args);
	va_end(args);
	ft_puts(printf_buf);
	return (printed);
}
