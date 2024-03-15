# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/28 13:09:52 by bamsyah           #+#    #+#              #
#    Updated: 2024/03/15 14:44:06 by bamsyah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = gcc
CFLAGS = -Wall -Wextra -Werror
FRAMEWORK = -lmlx -framework OpenGL -framework AppKit -Ofast
RM = rm -rf

SRC = cub3d.c Utils/libft/ft_calloc.c  Utils/libft/ft_isdigit.c Utils/libft/ft_memcmp.c  Utils/libft/ft_strchr.c  Utils/libft/ft_strlcpy.c Utils/libft/ft_strrchr.c Utils/libft/ft_toupper.c \
	Utils/libft/ft_isalnum.c Utils/libft/ft_isprint.c Utils/libft/ft_memcpy.c  Utils/libft/ft_strdup.c  Utils/libft/ft_strlen.c  Utils/libft/ft_strtrim.c \
	Utils/libft/ft_atoi.c    Utils/libft/ft_isalpha.c   Utils/libft/ft_memmove.c Utils/libft/ft_strjoin.c Utils/libft/ft_strncmp.c Utils/libft/ft_substr.c \
	Utils/libft/ft_bzero.c   Utils/libft/ft_isascii.c Utils/libft/ft_memchr.c  Utils/libft/ft_memset.c  Utils/libft/ft_strlcat.c Utils/libft/ft_strnstr.c Utils/libft/ft_tolower.c \
	Utils/libft/ft_itoa.c  Utils/libft/ft_putchar_fd.c  Utils/libft/ft_putstr_fd.c  Utils/libft/ft_putendl_fd.c  Utils/libft/ft_putnbr_fd.c Utils/libft/ft_split.c Utils/libft/ft_strmapi.c \
	Utils/libft/ft_striteri.c Mandatory/Parsing/initialize.c Mandatory/Parsing/parsing.c Mandatory/Parsing/check_file_extention.c Utils/get_next_line/get_next_line.c \
	Utils/get_next_line/get_next_line_utils.c Mandatory/Parsing/parce.c Mandatory/Parsing/check_elements.c Mandatory/Parsing/map.c Mandatory/Parsing/graphics.c Mandatory/Parsing/is_surrounded.c \
	Mandatory/Parsing/player.c 
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(FRAMEWORK) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	
re: fclean all