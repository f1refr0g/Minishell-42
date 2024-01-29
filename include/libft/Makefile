# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/21 11:17:32 by abeaudet          #+#    #+#              #
#    Updated: 2023/05/28 11:59:03 by abeaudet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a



SRCS =  ft_atoi.c \
        ft_bzero.c \
        ft_isalnum.c \
        ft_isalpha.c \
        ft_isascii.c \
        ft_isdigit.c \
        ft_isprint.c \
        ft_strlcat.c \
        ft_strlcpy.c \
        ft_strlen.c \
        ft_strncmp.c \
        ft_tolower.c \
        ft_toupper.c \
		ft_strchr.c \
		ft_strrchr.c\
		ft_strnstr.c\
		ft_memset.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_calloc.c\
		ft_strdup.c\
		ft_substr.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_split.c\
		ft_strmapi.c\
		ft_striteri.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_itoa.c\
		ft_lstnew.c\
		ft_lstadd_front.c\
		ft_lstsize.c\
		ft_lstlast.c\
		ft_lstadd_back.c\
		ft_lstdelone.c\
		ft_lstclear.c\
		ft_lstiter.c\
		ft_lstmap.c\
		ft_freeptr.c\
		ft_free_array.c\
		ft_error.c\
		ft_strdup_nonl.c\
		ft_strjoin_nonl.c\
		ft_percent.c\
		ft_printf.c\
		ft_printnbr.c\
		ft_ptr.c\
		ft_typestring.c\
		ft_unsigned.c\
		ft_hexaprint.c\
		ft_putchar.c\
		get_next_line.c\
		get_next_line_utils.c\
		ft_digit.c\
		ft_isint.c\
		ft_atoil.c\
		ft_intoverflow.c\
		
		
OBJS = $(SRCS:.c=.o)

HEADER = libft.h

CC = gcc
CFLAGS = -Wall -Werror -Wextra

$(NAME):
	$(CC) $(CFLAGS) -c $(SRCS)
	ar rc $(NAME) $(OBJS)
	
all: $(NAME)


clean:
	/bin/rm -f $(OBJS) 
	
fclean: clean
	/bin/rm -f $(NAME)
	
re: fclean all
	