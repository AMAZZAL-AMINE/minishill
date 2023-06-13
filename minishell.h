/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:07:30 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/13 21:28:20 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "./libft/libft.h"
#include "./errors/errors.h"

typedef struct s_parsing
{
    char *cmd;
    char **args;
    char *input;
    char *output;
    char *append;
    int  is_re_to_file;// (>) Sends standard output to <file>
    int  pipe;
    int index;
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
void clear(void);

//start point 
void builtin(t_minishell *shell, char *line);

//commandes
int echo_cmd(t_parsing *shill);

#endif
