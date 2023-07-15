/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:07:30 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/16 00:36:22 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include "./libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <dirent.h>
#include <stdbool.h>
#include <sys/stat.h>

typedef struct s_parsing
{
    char *cmd;
    char **args;
    char *input;
    int n_out_files;
    int n_in_files;
    struct s_parsing *all_cmd;
    int     fd_in;
    int     fd_out;
}               t_parsing;

typedef struct s_env
{
    char *name;
    char *value;
    int is_haver_equal;
}            t_env;

struct s_captur
{
    int exit_status;
}  captur;


typedef struct s_minishell {
    t_env           *env;
    t_parsing       *parsing;
    char            **env_v;
    int             n_cmd;
    int             n_var_env;
    int             _stdin;
    int             _stdout;
    int             pipefd[2];
    int             pipefd2[2];
    int             prev_pipefd[2];
}    t_minishell;

int     parsing_input(t_minishell *minishell, char *line);
char    *update_token(char *token, int size);
// char **split_commande_args(char *token);
char *get_with_fixes_size(char *token, int size);
int ft_count_tokens(char *line);
int redirect(int is_path, t_parsing *shell, char **content);
void set_the_tokens_in_ther_place(t_minishell *shell);
char **get_new_arg(char **dst, char **args, int size, t_minishell *minishell);
char **split_commande_args(char *token, t_minishell *minishell);
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
char *find_cmd_path(char *cmd, t_minishell *shell, t_parsing *s);
int count_length_two_arr(char **arr);
char **join_two_dim_arr(char *s1, char **arr);
char *expande_cmd(char *cmd, t_minishell *minishell);
char **split_variabls(char *arg, int size);
void update_exported_var(char *content, t_minishell *shell, char *name, char *value);
char **join_tables(char **table1, char **table2);
int is_commande_var(t_parsing *shell, t_minishell *mini, int index);

//redirection
int redirect_input(char **content, int count);
int redirect_output(char **content, int count) ;
int appned(char **content, int count);
int herdoc(char **content);
int search_for_heardoc(char **content);
int builtin_redirections(char **content, t_parsing *shell);
int is_cmd_redirected(char *cmd);

void run_buitins(t_minishell *shell, int count, int size);
char *get_env_value(char *what, t_minishell *shell);

//commandes 
void execut(t_parsing *shell, t_minishell *mini, int ispipe);
int echo_cmd(t_parsing *shill);
void clear(void);
void pip_exec(t_parsing *shell, t_minishell   *mini);
void change_dir(t_parsing *shell, t_minishell *minishell, int count, int isze);
void pwd(t_parsing *shell);
void exit_shell(t_parsing *shell, t_minishell *minishell, int index, int size);
void get_env(t_env *env, t_minishell *shell, char **content);
void set_env(t_minishell *shell);
void export(t_parsing *shell, t_minishell *ms);
void unset(t_minishell *ms, t_parsing *shell);
void expand(t_parsing *shell, t_minishell *ms);
void handle_signals(int sig);
void handle_ctl_d(char *line);
void _pipe(t_parsing *shell, t_minishell   *mini, char *line);
//checker
void check_cmd_exist(t_parsing *shell, t_minishell *ms);
int get_rederection_length(char *token);

//ERRORS
int all_functions_errors(char *line, t_minishell *ms, t_parsing *shell);
void error_message(char *msg, int free_flag, char *line) ;
int single_quots_arr(char *line);
int handle_undfined_file(char **content);
void cmd_not_found(char *cmd, t_minishell *shell);
int errors(char *line, t_minishell *ms, t_parsing *shell);
int is_can_access(char *arg, t_parsing *shell);
int exp_not_valid_identifier(char *arg);
int  check_cmd_type(char *cmd);
int cmd_is_only_dolar(char *cmd);
int unset_not_valid_identifier(char *arg);
int check_the_dir_name(char *dir_name);
int has_ambiguous_redirect(char** args);

#endif
