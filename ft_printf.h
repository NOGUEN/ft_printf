/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 10:53:56 by hnoh              #+#    #+#             */
/*   Updated: 2021/01/28 13:14:20 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

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

extern int		g_flags;
extern int		g_field_width;
extern int		g_precision;
extern int		g_qualifier;
extern int		g_base;
extern int		g_checker;

int			ft_printf(const char *format, ...);

int			ft_vsprintf(char *buf, char *tmp, va_list args);
char		*ft_vsprintf_set(char **tmp, va_list *args);
char		*ft_vsprintf_flag(char **tmp);
char		*ft_vsprintf_width(char **tmp, va_list *args);
char		*ft_vsprintf_precision(char **tmp, va_list *args);
char		*ft_vsprintf_conversion(char **tmp);

void		ft_vsprintf_c(char **tmp, char **str, va_list *args);
void		ft_vsprintf_s(char **tmp, char **str, va_list *args);
void		ft_vsprintf_p(char **tmp, char **str, va_list *args);
void		ft_vsprintf_d(char **tmp);
void		ft_vsprintf_i(char **tmp);
void		ft_vsprintf_u(char **tmp);
void		ft_vsprintf_x(char **tmp);
void		ft_vsprintf_bx(char **tmp);
void		ft_vsprintf_per(char **tmp, char **str);
void		ft_defaultact(char **str, char **tmp);

int			ft_skip_atoi(char **s);

size_t		ft_strnlen(char *s, size_t maxlen);

int			ft_do_div(long *n, int base);
int			ft_isflag(char *p);
int			ft_isdigit(int c);
void		ft_puts(char *str);

void		if_LEFT();
void		if_SIGN(long num);
void		if_SPECIAL();
void		if_SPECIAL2(char *str);

char *ft_number(char **str, long num, int base, int size, int precision,
		    int type);
#endif
