/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:04:47 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/30 20:00:46 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_it_bultin_or_not(t_minishell *shell, int count)
{
	if (str_cmp("echo", shell->parsing[count].cmd) \
		|| str_cmp("cd", shell->parsing[count].cmd) \
		|| str_cmp("pwd", shell->parsing[count].cmd) \
		|| str_cmp("exit", shell->parsing[count].cmd) \
		|| str_cmp("env", shell->parsing[count].cmd) \
		|| str_cmp("export", shell->parsing[count].cmd) \
		|| str_cmp("unset", shell->parsing[count].cmd))
		return (1);
	return (0);
}

int	handle_error_break(char *line, t_minishell *shell, int count)
{
	if (handle_undfined_file(shell->parsing[count].args))
		return (1);
	if (all_functions_errors(line, shell, &shell->parsing[count]))
		return (1);
	return (0);
}

void	start_execution(t_minishell *shell, int count, int size_cmd)
{
	if (ft_strlen(shell->parsing[count].cmd) > 0 \
		|| shell->parsing[count].is_cmd_var == 0 \
		|| (shell->parsing[count].is_cmd_var == 1 \
		&& ft_strlen(shell->parsing[count].cmd) > 0))
	{
		if (count + 1 <= size_cmd \
			&& (str_cmp(shell->parsing[count + 1].cmd, "|")))
		{
			if (count - 1 >= 0 \
				&& str_cmp(shell->parsing[count - 1].cmd, "|"))
				execut(&shell->parsing[count], shell, 2);
			else
			{
				if (check_cmd_type(shell->parsing[count].cmd) == 0)
					execut(&shell->parsing[count], shell, 1);
			}
		}
		else
		{
			if (check_cmd_type(shell->parsing[count].cmd) == 0)
				execut(&shell->parsing[count], shell, 0);
		}
	}
	else
		captur.exit_status = 0;
}

void	start_cmd(t_minishell *shell, char *line)
{
	int	count;
	int	size_cmd;

	count = 0;
	size_cmd = ft_count_tokens(line) * 2;
	if (unclosed_pipe(shell))
		return ;
	while (count <= size_cmd)
	{
		if (count % 2 == 0 && check_cmd_syntax(shell->parsing[count].cmd, \
			shell->parsing[count].args, &shell->parsing[count]) == 0)
		{
			if (handle_error_break(line, shell, count))
				break ;
			check_cmd_exist(&shell->parsing[count], shell);
			if (is_it_bultin_or_not(shell, count))
				start_builtin(count, size_cmd, shell);
			else
				start_execution(shell, count, size_cmd);
		}
		count++;
	}
	dup2(shell->_stdin, STDIN_FILENO);
	dup2(shell->_stdout, STDOUT_FILENO);
}
