/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:07:30 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/24 21:30:26 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./libft_t/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <dirent.h>
# include <stdbool.h>
# include <sys/stat.h>

typedef struct s_parsing
{
	char				*cmd;
	char				**args;
	char				*input;
	int					n_out_files;
	int					n_in_files;
	struct s_parsing	*all_cmd;
	int					fd_in;
	int					fd_out;
	int					is_cmd_var;
	int					is_cmd_in_quotes;
}	t_parsing;

typedef struct s_env
{
	char	*name;
	char	*value;
	int		is_haver_equal;
}	t_env;

struct s_captur
{
	int		exit_status;
	int		is_press_ctrl_c;
	int		is_press_ctrl_d;
}	captur;

typedef struct s_minishell {
	t_env			*env;
	t_parsing		*parsing;
	char			**env_v;
	int				n_cmd;
	int				n_var_env;
	int				_stdin;
	int				_stdout;
	int				pipefd[2];
	int				pipefd2[2];
	int				prev_pipefd[2];
	char			*shlvl;
	char			**tokens;
}	t_minishell;

int		parsing_input(t_minishell *minishell, char *line);
char	*update_token(char *token, int size);
char	*get_with_fixes_size(char *token, int size);
int		ft_count_tokens(char *line);
int		redirect(int is_path, t_parsing *shell, \
	char **content, t_minishell *mini);
void	set_the_tokens_in_ther_place(t_minishell *shell);
char	**get_new_arg(char **dst, char **args, \
	int size, t_minishell *minishell);
char	**split_commande_args(char *token, t_minishell *minishell);
char	*get_value_from_env(char **conten, char *what);
//start point 
void	start_cmd(t_minishell *shell, char *line);
char	**join_two_dim_arr(char *s1, char **arr);
char	*remove_quots(char *arg);
int		count_quots(char *arg);
char	**new_content(char **content);
int		is_redirec_output(char **args);
int		find_file_after_redir(char **args);
char	**get_only_what_ineed_in_arr(char **args);
void	count_redirections(t_minishell *shell);
int		str_cmp(char *s1, char *s2);
char	*find_cmd_path(char *cmd, t_minishell *shell, t_parsing *s);
int		count_length_two_arr(char **arr);
char	**join_two_dim_arr(char *s1, char **arr);
char	**split_variabls(char *arg, int size);
void	update_exported_var(char *content, t_minishell *shell, \
	char *name, char *value);
char	**join_tables(char **table1, char **table2);
void	update_env_ontime(t_parsing *shell, t_minishell *mini);
char	**get_args_without_redirections(char **args);
char	**duplicate_content(char **content);
int		is_dolar_(char *str);
int		is_bettwen_double(char *arg);
char	*get_value_with_no_moure_then_space(char *value);
void	get_exported_vars(t_minishell *shell);
int		count_redirection_and_files(char **args);
int		export_to_en(t_minishell *shell, char *name, \
	char *value, char *content);
void	update_exported_var(char *content, t_minishell \
	*shell, char *name, char *value);
char	**sort_args(char **oldargs);
int		count_argment_without_red(char **args);
int		is_redirect(char *red);
int		is_quot_in_cmd(char *cmd);
int		count_argment_without_red(char **args);
int		is_commande_var(t_parsing *shell, t_minishell *mini, int index);
int		length_new_cmd(char *arg);
char	*update_cmd_from_quotes(char *cmd);
int		is_dolar_var(char *arg);
char	**split_variabls(char *arg, int size);
int		skip_spaces(char *token);
char	*rm_spaces_from_cmd(char *cmd);
int		get_size_of_arg_if_args(char **args);
int		get_length_var(char *s);
char	*get_cmd_with_fixes_size(char *token, int size);
int		commande_length(char *token);
char	**new_tokens(char *line);
char	*pip_strchr(char *arg);
int		find_index_pipe(char *line);
int		ft_count_tokens(char *line);
char	**remove_space_from_dst(char **dst);
int		get_rederection_length(char *token);
int		count_splited_words(char *token);
char	*ft_strndup_new(char const *str, size_t max);

//redirection
int		redirect_input(char **content, int count);
int		redirect_output(char **content, int count);
int		appned(char **content, int count);
int		herdoc(char **content, t_minishell *mini);
int		search_for_heardoc(char **content);
int		builtin_redirections(char **content, t_parsing *shell, \
	t_minishell *mini);
int		is_cmd_redirected(char *cmd);
void	run_buitins(t_minishell *shell, int count, int size);
char	*get_env_value(char *what, t_minishell *shell);
int		is_redirect(char *red);

//commandes 
void	execut(t_parsing *shell, t_minishell *mini, int ispipe);
int		echo_cmd(t_parsing *shill);
void	clear(void);
void	pip_exec(t_parsing *shell, t_minishell *mini);
void	change_dir(t_parsing *shell, t_minishell *minishell, \
	int count, int isze);
void	pwd(t_parsing *shell);
void	exit_shell(t_parsing *shell, t_minishell *minishell, \
	int index, int size);
void	get_env(t_env *env, t_minishell *shell, char **content);
void	set_env(t_minishell *shell);
void	export(t_parsing *shell, t_minishell *ms);
void	unset(t_minishell *ms, t_parsing *shell);
char	*expand(char *arg, t_minishell *mini);
void	handle_signals(int sig);
void	handle_ctl_d(char *line);
void	_pipe(t_parsing *shell, t_minishell *mini, char *line);
void	close_child_between_pieps(t_minishell *mini, int is_between);
void	open_child_between_pieps(t_minishell *mini, int is_between);
void	start_builtin(int count, int size_cmd, t_minishell *shell);
void	close_pipe_in_child(t_minishell *shell, int betwn_pipes);
void	run_pipe_in_child(t_minishell *shell, int betwn_pipes);
void	close_pipes(int is_betwwen_pipe, t_minishell *shell);
//checker
void	check_cmd_exist(t_parsing *shell, t_minishell *ms);
int		get_rederection_length(char *token);
int		no_permission(char *filename);
int		no_file_or_dir(char *filename);
int		check_redrect_output(char **new_content, t_minishell *mini, \
	int count, char *filename);
int		check_redrect_input(char **new_content, t_minishell *mini, \
	int count, char *filename);
int		check_appned(t_minishell *mini, char *filename, int count, \
	char **new_content);
int		is_q_in_cmd(char *token);

//ERRORS
int		all_functions_errors(char *line, t_minishell *ms, t_parsing *shell);
int		single_quots_arr(char *line);
int		handle_undfined_file(char **content);
void	cmd_not_found(char *cmd, t_minishell *shell);
int		errors(char *line, t_minishell *ms, t_parsing *shell);
int		is_can_access(char *arg, t_parsing *shell);
int		exp_not_valid_identifier(char *arg);
int		check_cmd_type(char *cmd);
int		cmd_is_only_dolar(char *cmd);
int		unset_not_valid_identifier(char *arg);
int		check_the_dir_name(char *dir_name);
int		has_ambiguous_redirect(char **args);
int		unclosed_pipe(t_minishell *mini);
int		check_cmd_syntax(char *command, char **args, t_parsing *shell);
int		is_ambiguous_file(char *name, t_minishell *mini);
int		is_ambiguous_file(char *name, t_minishell *mini);
int		check_next_str(char *str, int index);
int		is_btween_word_space(char *str);
int		is_dolar_between_quot(char *str);
int		check_prev_str(char *str, int index);
char	*expand_ambiguous(char *arg, t_minishell *mini);
int		is_var_between_quot_ambiguous(char *arg);
int		is_only_dolar(char c, char c_next);
int		is_arobase(char c, int grep_size, char *arg, int count);
int		ft_get_grepe_size_ambiguous(char *s);

//cd
void	home_not_set(void);
void	cd_err(char *dir);
void	cd_between_pipe_cd_status(void);
#endif
