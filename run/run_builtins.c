/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_builtins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 13:42:49 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/21 21:36:14 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	update_argments(t_minishell *shell, int count)
{
	int		size_new_vars;
	char	**new_arg;

	size_new_vars = count_length_two_arr(shell->parsing[count].args);
	new_arg = malloc(sizeof(char *) * (size_new_vars + 1));
	shell->parsing[count].args = get_new_arg(new_arg, \
	shell->parsing[count].args, size_new_vars, shell);
}

void	run_buitins(t_minishell *shell, int count, int size)
{
	update_argments(shell, count);
	if (str_cmp("echo", shell->parsing[count].cmd) \
		|| str_cmp("/bin/echo", shell->parsing[count].cmd))
		echo_cmd(&shell->parsing[count]);
	else if (str_cmp("cd", shell->parsing[count].cmd) \
		|| str_cmp("/usr/bin/cd", shell->parsing[count].cmd))
		change_dir(&shell->parsing[count], shell, count, size);
	else if (str_cmp("clear", shell->parsing[count].cmd))
		clear();
	else if (str_cmp("pwd", shell->parsing[count].cmd) \
		|| str_cmp("/bin/pwd", shell->parsing[count].cmd))
		pwd(&shell->parsing[count]);
	else if (str_cmp("exit", shell->parsing[count].cmd))
		exit_shell(&shell->parsing[count], shell, count, size);
	else if (str_cmp("env", shell->parsing[count].cmd))
		get_env(shell->env, shell, shell->parsing[count].args);
	else if (str_cmp("export", shell->parsing[count].cmd))
		export(&shell->parsing[count], shell);
	else if (str_cmp("unset", shell->parsing[count].cmd))
		unset(shell, &shell->parsing[count]);
}

void	builtin_that_need_to_fork(int count, int size_cmd, \
	t_minishell *shell, int is_betwwen_pipe)
{
	if (is_betwwen_pipe == 0)
		run_pipe_in_child(shell, 0);
	else
		run_pipe_in_child(shell, 1);
	if (builtin_redirections(shell->parsing[count].args, \
		&shell->parsing[count], shell) == 0)
	{
		run_buitins(shell, count, size_cmd);
		exit(0);
	}
	else
		exit(1);
}

void	run_single_cmd(t_minishell *shell, int count, int size_cmd)
{
	if (builtin_redirections(shell->parsing[count].args, \
		&shell->parsing[count], shell) == 0)
		run_buitins(shell, count, size_cmd);
}

void	start_builtin(int count, int size_cmd, t_minishell *shell)
{
	int	is_betwwen_pipe;
	int	pid;

	is_betwwen_pipe = 0;
	if (count + 1 <= size_cmd && \
		(str_cmp(shell->parsing[count + 1].cmd, "|")))
	{
		if (count - 1 >= 0 && \
			str_cmp(shell->parsing[count - 1].cmd, "|"))
			is_betwwen_pipe = 1;
		if (is_betwwen_pipe == 0)
			pipe(shell->pipefd);
		else
			pipe(shell->pipefd2);
		pid = fork();
		if (pid == 0)
			builtin_that_need_to_fork(count, size_cmd, shell, \
				is_betwwen_pipe);
		else
			close_pipes(is_betwwen_pipe, shell);
	}
	else
		run_single_cmd(shell, count, size_cmd);
}
