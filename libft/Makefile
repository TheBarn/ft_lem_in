# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: barnout <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/09 20:20:32 by barnout           #+#    #+#              #
#    Updated: 2017/04/05 11:08:46 by barnout          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRC_BASE=	./ft_atoi.c		\
			./ft_bzero.c	\
			./ft_isalnum.c	\
			./ft_isalpha.c	\
			./ft_isascii.c	\
			./ft_isdigit.c	\
			./ft_isprint.c	\
			./ft_memccpy.c	\
			./ft_memchr.c	\
			./ft_memcmp.c	\
			./ft_memcpy.c	\
			./ft_memccpy.c	\
			./ft_memmove.c	\
			./ft_memset.c	\
			./ft_putchar.c	\
			./ft_putnbr.c	\
			./ft_putstr.c	\
			./ft_strcat.c	\
			./ft_strchr.c	\
			./ft_strcpy.c	\
			./ft_strdup.c	\
			./ft_strlcat.c	\
			./ft_strlen.c	\
			./ft_strncat.c	\
			./ft_strcmp.c	\
			./ft_strncmp.c	\
			./ft_strncpy.c	\
			./ft_strnstr.c	\
			./ft_strrchr.c	\
			./ft_strstr.c	\
			./ft_tolower.c	\
			./ft_toupper.c	\
			./ft_memalloc.c	\
			./ft_memdel.c	\
			./ft_strnew.c	\
			./ft_strdel.c	\
			./ft_strclr.c	\
			./ft_striter.c	\
			./ft_striteri.c	\
			./ft_strmap.c	\
			./ft_strmapi.c	\
			./ft_strequ.c	\
			./ft_strnequ.c	\
			./ft_strsub.c	\
			./ft_strjoin.c	\
			./ft_strtrim.c	\
			./ft_strsplit.c	\
			./ft_itoa.c		\
			./ft_putendl.c	\
			./ft_putchar_fd.c	\
			./ft_putstr_fd.c	\
			./ft_putendl_fd.c	\
			./ft_putnbr_fd.c	\
			./my_malloc.c	\
			./get_next_line.c	\
			srcs/ft_printf.c \
			srcs/conversion_functions.c \
			srcs/conversion_functions2.c \
			srcs/conversion_utils.c \
			srcs/conversion_wstr.c \
			srcs/conversion_wstr2.c \
			srcs/flags.c \
			srcs/ft_ltoa.c \
			srcs/ft_imaxtoa.c \
			srcs/ft_printf.c \
			srcs/get_functions.c \
			srcs/get_functions2.c \
			srcs/get_functions3.c \
			srcs/precision.c \
			srcs/padding.c \
			srcs/print_functions.c \
			srcs/print_functions2.c \
			srcs/print_functions3.c \
			srcs/put_functions.c \
			srcs/read_args.c \
			srcs/utils.c \
			srcs/utils2.c \
			srcs/wstr_utils.c \
			srcs/swap_minus.c

				

OBJS	=	$(SRC_BASE:.c=.o)

GCC		=	gcc

CFLAGS	+=	-Wall -Wextra -Werror

RM		=	rm -f

all		:	$(NAME)

%.o: %.c includes/libftprintf.h
		@gcc -I includes -c $< -o $@

$(NAME)	:	$(OBJS)
			@ar rc $(NAME) $(OBJS)
			@ranlib $@

clean	:	
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY: clean all re fclean
