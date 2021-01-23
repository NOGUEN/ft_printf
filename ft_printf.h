/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 10:53:56 by hnoh              #+#    #+#             */
/*   Updated: 2021/01/23 11:56:13 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef ZEROPAD
#  define ZEROPAD	1
# endif

# ifndef SIGN
#  define SIGN	2
# endif

# ifndef PLUS
#  define PLUS	4
# endif

# ifndef SPACE
#  define SPACE	8
# endif

# ifndef LEFT
#  define LEFT	16
# endif

# ifndef SMALL
#  define SMALL	32
# endif

# ifndef SPECIAL
#  define SPECIAL	64
# endif

int			ft_printf(const char *format, ...);

char		*ft_vsprintf_percentsign(const char *fmt, char **str);
char		*ft_vsprintf_flag(char *tmp);
char		*ft_vsprintf_width(char *tmp, va_list args);
char		*ft_vsprintf_precision(char *tmp, va_list args);
char		*ft_vsprintf_conversion(char *tmp);

int			ft_skip_atoi(const char **s);

int			ft_isflag(char *p);
int			ft_isdigit(int c);
void		ft_puts(const char *str);
#endif
