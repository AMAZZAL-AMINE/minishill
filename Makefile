# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/03 14:24:14 by mamazzal          #+#    #+#              #
#    Updated: 2023/07/29 16:23:57 by mamazzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = main.c ./parsing/parsing.c ./parsing/update_token.c ./parsing/split_commande_args.c \
			./errors/quots_error.c ./errors/all_func_errors.c \
			./run/start_cmd.c ./run/echo.c ./run/clear.c ./run/execut.c remove_quots.c \
			./run/redirections/redirect.c ./run/utilis/exec_utilis.c  \
			str_cmp.c ./run/redirections/appned.c ./run/redirections/herdoc.c ./run/redirections/redirect_input.c \
			./run/redirections/redirect_output.c ./run/get_cmd_path.c  ./run/join_two_dem_arr.c ./run/cd.c \
			./run/pwd.c ./run/exit.c ./run/env.c ./run/set_env.c ./run/export.c ./run/unset.c \
			./run/redirections/search_for_herdoc.c ./run/builtin_redirections.c ./run/run_builtins.c \
			./parsing/expand.c ./signals.c ./run/is_cmd_redirected.c ./parsing/check_cmd_exist.c \
			./errors/handle_undfined_file.c ./errors/cmd_not_found.c ./errors/is_can_access.c \
			./errors/exp_not_valid_identifier.c ./errors/check_cmd_type.c \
			./errors/cmd_is_only_dolar.c ./errors/unset_not_valid_identifier.c ./errors/check_the_dir_name.c \
			join_tables.c ./errors/unclosed_pipes.c ./errors/check_cmd_syn.c update_env.c \
			get_args_without_redirections.c ./duplicate_content.c ./errors/ambiguous.c \
			get_value_with_no_moure_then_space.c ./run/utilis/execute_utilis_part1.c \
			./run/utilis/cd_utilis.c ./run/utilis/builtins_utilis.c ./run/utilis/redirections_utilis.c \
			./run/utilis/export_utilis_get_exported_vars.c ./run/utilis/export_utilis_export_to_env.c \
			./run/utilis/export_utilis_update_exported_var.c ./errors/utilis/is_ambiguous_file.c \
			./errors/utilis/ambiguoys_utilis_p1.c ./errors/utilis/ambiguoys_utilis_p2.c ./parsing/utilis/sort_args.c \
			./parsing/utilis/count_redirection_and_files.c ./parsing/utilis/update_cmd_from_quotes.c \
			./parsing/utilis/split_variabls.c ./parsing/utilis/utilis_part1.c ./parsing/utilis/utilis_part2.c \
			./parsing/utilis/get_cmd_with_fixes_size.c ./parsing/utilis/utilis_part3.c \
			./parsing/utilis/new_tokens.c ./parsing/remove_space_from_dst.c ./parsing/ft_strndup_new.c\
			./parsing/count_splited_words.c ./parsing/get_rederection_length.c

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -O0 #-fsanitize=address -g

#to defined the path of readline
LDFLAGS="-L/goinfre/mamazzal/homebrew/opt/readline/lib"
CPPFLAGS="-I/goinfre/mamazzal/homebrew/opt/readline/include"

OBJ = $(SRC:.c=.o)
 
all: $(NAME)

run: all clean
	./$(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS)  ./libft_t/libft.a -o $(NAME) $(OBJ)  -lreadline


clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all clean
