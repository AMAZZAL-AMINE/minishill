/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:07:30 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/06 18:53:30 by mamazzal         ###   ########.fr       */
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
#include <sys/stat.h>

typedef struct s_parsing
{
    char *cmd;
    char **args;
    char *input;
    int n_out_files;
    int n_in_files;
    struct s_parsing *all_cmd;
}               t_parsing;

typedef struct s_env
{
    char *name;
    char *value;
    int is_haver_equal;
}            t_env;

typedef struct s_minishell {
    t_env           *env;
    t_parsing       *parsing;
    char            **env_v;
    int             n_cmd;
    int             n_var_env;
    int             _stdin;
    int             _stdout;
    int caputre_exit_status;
}    t_minishell;

int     parsing_input(t_minishell *minishell, char *line);
char    *update_token(char *token, int size);
char **split_commande_args(char *token);
char *get_with_fixes_size(char *token, int size);
int ft_count_tokens(char *line);
void redirect(int is_path, t_parsing *shell, char **content);
void set_the_tokens_in_ther_place(t_minishell *shell);

//start point 
void builtin(t_minishell *shell, char *line);
char **join_two_dim_arr(char *s1, char **arr);
char *remove_quots(char *arg);
int count_quots(char *arg) ;
char **new_content(char **content);
int is_redirec_output(char **args) ;
int find_file_after_redir(char **args);
char **get_only_what_ineed_in_arr(char **args);
void count_redirections(t_minishell *shell);
int str_cmp(char *s1, char *s2);
char *find_cmd_path(char *cmd, t_minishell *shell);
int count_length_two_arr(char **arr);
char **join_two_dim_arr(char *s1, char **arr);

//redirection
void redirect_input(char **content, int count);
void redirect_output(char **content, int count) ;
void appned(char **content, int count);
void herdoc(char **content);
int search_for_heardoc(char **content);
void builtin_redirections(char **content, t_parsing *shell);
int is_cmd_redirected(char *cmd);

void run_buitins(t_minishell *shell, int count);
char *get_env_value(char *what, t_minishell *shell);
//commandes
void execut(t_parsing *shell, t_minishell *mini);
int echo_cmd(t_parsing *shill);
void clear(void);
void pip_exec(t_parsing *shell, t_minishell   *mini);
void change_dir(t_parsing *shell, t_minishell *minishell) ;
void pwd(t_parsing *shell);
void exit_shell(t_parsing *shell);
void get_env(t_env *env, t_minishell *shell, char **content);
void set_env(t_minishell *shell);
void export(t_parsing *shell, t_minishell *ms);
void unset(t_minishell *ms, t_parsing *shell);
void expand(t_parsing *shell, t_minishell *ms);
void handle_signals(int sig);
void handle_ctl_d(char *line);

//checker
void check_cmd_exist(t_parsing *shell, t_minishell *ms);
#endif
