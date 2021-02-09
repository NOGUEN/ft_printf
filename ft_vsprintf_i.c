/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf_i.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogeun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 11:48:43 by nogeun            #+#    #+#             */
/*   Updated: 2021/02/08 11:24:58 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_vsprintf_i(char **tmp, va_list *ap)
{
    if (**tmp == 'i')
    {
        if (g_flags & LONGLONGFLAG)
            g_n = va_arg(*ap, long long);
        if (g_flags & LONGFLAG)
            g_n = va_arg(*ap, long);
        if (g_flags & HALFHALFFLAG)
            g_n = (signed char)va_arg(*ap, int);
        if (g_flags & HALFFLAG)
            g_n = (short)va_arg(*ap, int);
        if (g_flags & SIZETFLAG)
            g_n = va_arg(*ap, ssize_t);
        else
            g_n = va_arg(*ap, int);
        g_flags |= SIGNEDFLAG;
		g_base = 10;
        g_checker = 3;
    }
}
