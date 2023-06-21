# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/03 14:24:14 by mamazzal          #+#    #+#              #
#    Updated: 2023/06/21 22:57:29 by mamazzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = main.c ./parsing/parsing.c ./parsing/update_token.c ./parsing/split_commande_args.c \
			./errors/quots_error.c ./errors/error_msg.c ./errors/all_func_errors.c \
			./run/builtin.c ./run/echo.c ./run/clear.c ./run/execut.c remove_quots.c \
			./run/redirections/redirect.c ./run/utilis/exec_utilis.c ./parsing/set_all_in_current_place.c \
			str_cmp.c ./run/pipe.c ./run/redirections/appned.c ./run/redirections/herdoc.c ./run/redirections/redirect_input.c \
			./run/redirections/redirect_output.c ./run/get_cmd_path.c  ./run/join_two_dem_arr.c ./run/cd.c \
			./run/pwd.c ./run/exit.c ./run/env.c ./run/set_env.c ./run/export.c ./run/unset.c \
			./run/redirections/search_for_herdoc.c ./run/builtin_redirections.c

CC = cc
CFLAGS = -Wall -Wextra -Werror 
# 
OBJ = $(SRC:.c=.o)

all: $(NAME)

run: all clean
	./$(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -lreadline ./libft/libft.a -o $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all clean

