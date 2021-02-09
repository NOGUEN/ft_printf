# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nogeun <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/24 21:41:47 by nogeun            #+#    #+#              #
#    Updated: 2021/02/05 10:15:40 by nogeun           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=		ft_defaultact.c		\
				ft_isdigit.c		\
				ft_printf.c			\
				ft_puts.c			\
				ft_strlen.c			\
				ft_strnlen.c		\
				ft_vsprintf.c		\
				ft_vsprintf_asterisk.c	\
				ft_vsprintf_bx.c	\
				ft_vsprintf_c.c		\
				ft_vsprintf_d.c		\
				ft_vsprintf_digit.c	\
				ft_vsprintf_hash.c	\
				ft_vsprintf_i.c		\
				ft_vsprintf_minus.c	\
				ft_vsprintf_p.c		\
				ft_vsprintf_plus.c	\
				ft_vsprintf_point.c	\
				ft_vsprintf_per.c	\
				ft_vsprintf_s.c		\
				ft_vsprintf_u.c		\
				ft_vsprintf_x.c		\
				ft_do_div.c			\

OBJS	=		$(SRCS:.c=.o)

CC		=		gcc
RM		=		rm -f
CFLAGS	=		-Wall -Wextra -Werror -I.

NAME	=		libftprintf.a

all:			$(NAME)

$(NAME):		$(OBJS)
					ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
					$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus
