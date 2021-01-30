# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehande <ehande@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/06 20:41:14 by ehande            #+#    #+#              #
#    Updated: 2021/01/30 22:46:48 by ehande           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
H = libft.h
FL = -Wall -Wextra -Werror
SRC =   ft_atoi.c ft_bzero.c ft_calloc.c  ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
        ft_isprint.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
        ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
        ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
        ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
        ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
        ft_lstmap.c ft_lstnew.c ft_lstsize.c \

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	@gcc $(FL) -c $(SRC) $(H)
	@ar rcs $(NAME) $(OBJ)
all: $(NAME)

clean:
	@rm -f $(OBJ)
	@rm -f libft.h.gch

fclean:	clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
