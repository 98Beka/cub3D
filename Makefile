# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehande <ehande@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/26 08:47:35 by ehande            #+#    #+#              #
#    Updated: 2021/01/30 22:33:16 by ehande           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
LIBFT = dop_files/libft/libft.a
LB = dop_files/libft
SRC =	cub3d.c dop_files/get_next_line.c dop_files/get_next_line_utils.c parser.c \
		map.c dop1.c dop2.c  dop3.c pars_inf.c reycast.c drow.c get_textur.c save.c\

CC = clang

CFLAGS =  -Wall -Wextra -Werror

MLX = dop_files/minilibx_opengl/

LXFLAGS = -lmlx -framework OpenGL -framework AppKit


OBJ = ${SRC:.c=.o}

all: $(NAME)

$(NAME): $(OBJ)
	make -C dop_files/libft
	$(CC) -o $(NAME) -L $(MLX) $(LXFLAGS) $(OBJ) $(LIBFT)
	
#######################################################
a:  clean
	rm -f $(NAME) a
	make -C dop_files/libft
	$(CC) -o a -L $(MLX) $(LXFLAGS) $(CFLAGS) $(SRC) $(LIBFT) -g
#######################################################

clean:
	make clean -C dop_files/libft
	rm -rf $(OBJ)
	rm -f screen.bmp

fclean: clean
	make fclean -C dop_files/libft
	rm -f $(NAME)


re: fclean all

.PHONY: all clean fclean re norm
