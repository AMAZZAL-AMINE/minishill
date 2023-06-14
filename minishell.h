/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:07:30 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/14 19:50:23 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include "./libft/libft.h"
#include "./errors/errors.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <dirent.h>

typedef struct s_parsing
{
    char *cmd;
    char **args;
    char *input;
    int  is_re_to_file;// (>) Sends standard output to <file>
    int  pipe;
    int index;
    int outout_fd;
    int input_fd;
    int is_re_from_file;// (<) Reads standard input from <file>
    struct s_parsing *all_cmd;
}               t_parsing;

typedef struct s_env
{
    char *name;
    char *value;
    struct s_env *next;
}            t_env;

typedef struct s_minishell {
    t_env *env;
    t_parsing *parsing;
}               t_minishell;

int     parsing_input(t_minishell *minishell, char *line);
char    *update_token(char *token, int size);
char **split_commande_args(char *token);
char *get_with_fixes_size(char *token, int size);
int ft_count_tokens(char *line);

//start point 
void builtin(t_minishell *shell, char *line);
char **join_two_dim_arr(char *s1, char **arr);
char *remove_quots(char *arg);

//commandes
int echo_cmd(t_parsing *shill);
void ls(t_parsing *shell);
void clear(void);

#endif
