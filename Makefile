# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/03 14:24:14 by mamazzal          #+#    #+#              #
#    Updated: 2023/06/09 17:57:49 by mamazzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = main.c ft_splite.c ft_strjoin.c change_dir.c ft_strncmp.c \
	ft_strlen.c echo.c ft_isalpha.c ft_isdigit.c ft_ispip.c ft_strdup.c is_dl_q.c lexer.c \
	new_args.c  ft_strnstr.c run_shell.c 
CC = cc
CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

all: $(NAME) clean
	./$(NAME)


$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -lreadline -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all clean

