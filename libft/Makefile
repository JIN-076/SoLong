# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhong <jhong@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/10 14:23:02 by jhong             #+#    #+#              #
#    Updated: 2022/03/19 01:33:12 by jhong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cc=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=libft.a

INCDIR = -I ./

SRCDIR = ./
BONUS_SRCDIR = ./

SOURCES = $(addprefix $(SRCDIR), ft_atoi.c \
								ft_bzero.c \
								ft_calloc.c \
								ft_isalnum.c \
								ft_isalpha.c \
								ft_isascii.c \
								ft_isdigit.c \
								ft_isprint.c \
								ft_memccpy.c \
								ft_memchr.c \
								ft_memcmp.c \
								ft_memcpy.c \
								ft_memmove.c \
								ft_memset.c \
								ft_strdup.c \
								ft_strlcat.c \
								ft_strlcpy.c \
								ft_strlen.c \
								ft_strncmp.c \
								ft_strnstr.c \
								ft_strrchr.c \
								ft_tolower.c \
								ft_toupper.c \
								ft_strchr.c \
								ft_substr.c \
								ft_strjoin.c \
								ft_strtrim.c \
								ft_split.c \
								ft_itoa.c \
								ft_strmapi.c \
								ft_putchar_fd.c \
								ft_putstr_fd.c \
								ft_putendl_fd.c \
								ft_putnbr_fd.c \
								ft_strstr.c \
								get_next_line.c)
OBJECTS = $(SOURCES:.c=.o)

BONUS_SOURCES = $(addprefix $(BONUS_SRCDIR), ft_lstnew.c \
												ft_lstadd_front.c \
												ft_lstclear.c \
												ft_lstdelone.c \
												ft_lstiter.c \
												ft_lstlast.c \
												ft_lstmap.c \
												ft_lstadd_back.c \
												ft_lstsize.c)
BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)

ifdef WITH_BONUS
	OBJ = $(OBJECTS) $(BONUS_OBJECTS)
else
	OBJ = $(OBJECTS)
endif

.PHONY: bonus all clean fclean all

all: $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@ $(INCDIR)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

bonus :
	@make WITH_BONUS=1 all

clean:
	rm -rf $(OBJECTS)
	rm -rf $(BONUS_OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
