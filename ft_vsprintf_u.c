/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogeun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 11:50:43 by nogeun            #+#    #+#             */
/*   Updated: 2021/02/05 10:07:04 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_vsprintf_u(char **tmp, va_list *ap)
{
    if (**tmp == 'u')
    {
        if (g_flags & LONGLONGFLAG)
            g_n = va_arg(*ap, unsigned long long);
        if (g_flags & LONGFLAG)
            g_n = va_arg(*ap, unsigned long);
        if (g_flags & HALFHALFFLAG)
            g_n = (unsigned char)va_arg(*ap, unsigned int);
        if (g_flags & HALFFLAG)
            g_n = (unsigned short)va_arg(*ap, unsigned int);
        if (g_flags & SIZETFLAG)
            g_n = va_arg(*ap, size_t);
        else
            g_n = va_arg(*ap, unsigned int);
        g_checker = 3;
    }
}
