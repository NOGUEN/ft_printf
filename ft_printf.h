/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 10:53:56 by hnoh              #+#    #+#             */
/*   Updated: 2021/01/24 22:00:59 by nogeun           ###   ########.fr       */
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

extern int		g_flags;
extern int		g_field_width;
extern int		g_precision;
extern int		g_qualifier;
extern int		g_base;
extern int		g_checker;
extern int		g_locase;
extern char		*g_digits;
extern char		g_tmp[66];
extern char		g_c;
extern char		g_sign;
extern int		g_i;

int			ft_printf(const char *format, ...);

int			ft_vsprintf(char *buf, char *fmt, va_list args);
char		*ft_vsprintf_percentsign(char *fmt, char *str);
char		*ft_vsprintf_flag(char *tmp);
char		*ft_vsprintf_width(char *tmp, va_list args);
char		*ft_vsprintf_precision(char *tmp, va_list args);
char		*ft_vsprintf_conversion(char *tmp);

void		ft_vsprintf_c(char *tmp, char *str, va_list args);
void		ft_vsprintf_s(char *tmp, char *str, va_list args);
void		ft_vsprintf_p(char *tmp);
void		ft_vsprintf_d(char *tmp);
void		ft_vsprintf_i(char *tmp);
void		ft_vsprintf_u(char *tmp);
void		ft_vsprintf_x(char *tmp);
void		ft_vsprintf_bx(char *tmp);
void		ft_vsprintf_per(char *tmp, char *str);
void		ft_defaultact(char *str, char *tmp);

int			ft_skip_atoi(char **s);

int			ft_strnlen(const char *tmp, int n);

int			ft_do_div(int n, int base);
int			ft_isflag(char *p);
int			ft_isdigit(int c);
void		ft_puts(char *str);

void		if_LEFT();
void		if_SIGN(long num);
void		if_SPECIAL();
void		if_SPECIAL2(char *str);

void		ft_number2(char *str);
char		*ft_number(char *str, long num);
#endif
