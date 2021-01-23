/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 10:08:39 by hnoh              #+#    #+#             */
/*   Updated: 2021/01/23 11:20:13 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_vsprintf_set(const char *fmt, char *tmp,  va_list args)
{
	tmp = ft_vsprintf_percentsign(fmt, &str);
	tmp = ft_vsprintf_flag(tmp);
	tmp = ft_vsprintf_width(tmp, args);
	tmp = ft_vsprintf_precision(tmp, args);
	tmp = ft_vsprintf_conversion(tmp);
}

int			ft_vsprintf(char *buf, const char *fmt, va_list args)
{
	char *tmp;

	ft_vsprintf_set(fmt, tmp, args);
}
