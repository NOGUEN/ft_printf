# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nogeun <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/24 21:41:47 by nogeun            #+#    #+#              #
#    Updated: 2021/01/27 11:19:34 by nogeun           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=		ft_defaultact.c		\
				ft_do_div.c			\
				ft_isdigit.c		\
				ft_isflag.c			\
				ft_number.c			\
				ft_printf.c			\
				ft_puts.c			\
				ft_skip_atoi.c		\
				ft_strnlen.c		\
				ft_vsprintf.c		\
				ft_vsprintf_bx.c	\
				ft_vsprintf_c.c		\
				ft_vsprintf_d.c		\
				ft_vsprintf_i.c		\
				ft_vsprintf_p.c		\
				ft_vsprintf_per.c	\
				ft_vsprintf_s.c		\
				ft_vsprintf_u.c		\
				ft_vsprintf_utils.c	\
				ft_vsprintf_x.c		\

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
