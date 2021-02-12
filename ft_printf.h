/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 10:53:56 by hnoh              #+#    #+#             */
/*   Updated: 2021/02/12 12:16:29 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define ALTFLAG			0x00000001
# define CAPSFLAG			0x00000002
# define SHOWSIGNFLAG		0x00000004
# define SIGNEDFLAG			0x00000008
# define LEFTFORMATFLAG		0x00000010
# define LEADZEROFLAG 		0x00000020
# define POINTFLAG			0x00000040
# define ASTERISKFLAG		0x00000080
# define MINUSPREFLAG		0x00000100
# define PREZEROFLAG		0x00000200
# define BIGFORMATFLAG		0x00000400
# define POINTERFLAG		0x00000800
# define SPACEFLAG			0x00001000

extern int					g_flags;
extern int					g_format_num;
extern int					g_precision;
extern int					g_checker;
extern long					g_n;
extern char					g_tmp[100];
extern int					g_base;
extern int					*g_nullchecker;
extern int					g_cchecker;
extern int					g_exitloop;

int			ft_printf(const char *format, ...);

int			ft_vsprintf(char *tmp, va_list *ap);
void		ft_vsprintf2(char **tmp);
void		ft_vsprintf_put(char **tmp);
void		ft_vsprintf_set(char **tmp);
void		ft_vsprintf_setstr();

void		ft_vsprintf_asterisk(char **tmp, va_list *ap);
void		ft_vsprintf_digit(char **tmp);
void		ft_vsprintf_point(char **tmp);
void		ft_vsprintf_minus(char **tmp);
void		ft_vsprintf_plus(char **tmp);
void		ft_vsprintf_hash(char **tmp);
void		ft_vsprintf_space(char **tmp);
void		ft_vsprintf_c(char **tmp, va_list *ap);
void		ft_vsprintf_s(char **tmp, va_list *ap);
void		ft_vsprintf_p(char **tmp, va_list *ap);
void		ft_vsprintf_d(char **tmp, va_list *ap);
void		ft_vsprintf_i(char **tmp, va_list *ap);
void		ft_vsprintf_u(char **tmp, va_list *ap);
void		ft_vsprintf_o(char **tmp, va_list *ap);
void		ft_vsprintf_x(char **tmp, va_list *ap);
void		ft_vsprintf_bx(char **tmp, va_list *ap);
void		ft_vsprintf_per(char **tmp);
void		ft_defaultact(char **tmp);
char		*ft_vsprintf_ltos(int len);

int			ft_do_div(long *n, int base);
size_t		ft_strlen(const char *s);
size_t		ft_strnlen(char *s, size_t maxlen);
int			ft_isdigit(int c);
void		ft_puts(char c);

void		ft_outputstring();
void		ft_outputstring1(char *c);
void		ft_outputstring2(char *sign);
void		ft_outputstring3(int *i, char *digits);
void		ft_outputstring4(char *sign, char *c);
void		ft_outputstring5(int *i);
#endif
