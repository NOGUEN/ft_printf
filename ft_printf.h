/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 10:53:56 by hnoh              #+#    #+#             */
/*   Updated: 2021/02/09 14:39:57 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define LONGFLAG			0x00000001
# define LONGLONGFLAG		0x00000002
# define HALFFLAG			0x00000004
# define HALFHALFFLAG		0x00000008
# define SIZETFLAG			0x00000010
# define ALTFLAG			0x00000020
# define CAPSFLAG			0x00000040
# define SHOWSIGNFLAG		0x00000080
# define SIGNEDFLAG			0x00000100
# define LEFTFORMATFLAG		0x00000200
# define LEADZEROFLAG 		0x00000400
# define POINTFLAG			0x00000800
# define ASTERISKFLAG		0x00001000
# define MINUSPREFLAG		0x00002000
# define PREZEROFLAG		0x00004000
# define BIGFORMATFLAG		0x00008000
# define POINTERFLAG		0x00010000
# define SPACEFLAG			0x00020000

extern int					g_flags;
extern int					g_format_num;
extern int					g_precision;
extern int					g_checker;
extern long					g_n;
extern char					g_tmp[100];
extern int					g_base;
extern int					g_nullchecker[10000];
extern int					g_cchecker;
extern int					g_exitloop;

int			ft_printf(const char *format, ...);

int			ft_vsprintf(char *buf, char *tmp, va_list args);
void		ft_vsprintf2(char **tmp);
void		ft_vsprintf_put(char **str, char **tmp);
void		ft_vsprintf_set(char **tmp);
void		ft_vsprintf_setstr(char **str, char **buf);

void		ft_vsprintf_asterisk(char **tmp, va_list *ap);
void		ft_vsprintf_digit(char **tmp);
void		ft_vsprintf_point(char **tmp);
void		ft_vsprintf_minus(char **tmp);
void		ft_vsprintf_plus(char **tmp);
void		ft_vsprintf_hash(char **tmp);
void		ft_vsprintf_space(char **tmp);
void		ft_vsprintf_c(char **tmp, char **str, va_list *ap);
void		ft_vsprintf_s(char **tmp, va_list *ap, char **s);
void		ft_vsprintf_p(char **tmp, va_list *ap);
void		ft_vsprintf_d(char **tmp, va_list *ap);
void		ft_vsprintf_i(char **tmp, va_list *ap);
void		ft_vsprintf_u(char **tmp, va_list *ap);
void		ft_vsprintf_o(char **tmp, va_list *ap);
void		ft_vsprintf_x(char **tmp, char **str, va_list *ap);
void		ft_vsprintf_bx(char **tmp, char **str, va_list *ap);
void		ft_vsprintf_per(char **tmp, char **str);
void		ft_defaultact(char **tmp, char **str);
char		*ft_vsprintf_ltos(int len);

void		ft_outputchar(char **str, char c);
int			ft_do_div(long *n, int base);
size_t		ft_strlen(const char *s);
size_t		ft_strnlen(char *s, size_t maxlen);
int			ft_isdigit(int c);
void		ft_puts(char *str);

void		ft_outputstring(char **str);
void		ft_outputstring1(char *c);
void		ft_outputstring2(char *sign);
void		ft_outputstring3(char **str, int *i, char *digits);
void		ft_outputstring4(char **str, char *sign, char *c);
void		ft_outputstring5(char **str, int *i);
#endif
