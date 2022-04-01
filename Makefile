# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhong <jhong@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/16 19:55:52 by jhong             #+#    #+#              #
#    Updated: 2022/03/21 01:54:09 by jhong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long
CC		= 	gcc
CFLAGS	= 	-Wall -Wextra -Werror

LIBFT	=	libft/libft.a

INCS	=	./
SRCS	=	source/init.c \
			source/maps.c \
			source/movements.c \
			source/keyboard.c \
			source/condition.c \
			source/enemy.c \
			source/utils.c \
			source/validation.c \
			source/so_long.c \

OBJS	=	$(SRCS:%.c=%.o)

RM		=	rm -rf

MLXFLAGS	= -L ./mlx/ -lmlx -framework OpenGL -framework AppKit

all:		$(NAME)

$(NAME):	$(OBJS)
			make -C libft
			$(CC) $^ $(LIBFT) $(MLXFLAGS) $(CFLAGS) -I$(INCS) -o $(NAME)

%.o:		%.c
			$(CC) $(CFLAGS) -I ./mlx -c $< -o $@

play:		all
			./$(NAME) maps/map.ber

clean:
			make clean -C libft
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)
			$(RM) *.out
			make fclean -C libft/

re:			fclean all

bonus:		all
			./$(NAME) maps/map_bonus.ber

.PHONY:		all clean fclean re
