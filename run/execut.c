/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execut.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 07:40:31 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/21 12:07:24 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	length_cmd(char *cmd)
{
	int	count;

	count = ft_strlen(cmd) - 1;
	while (count >= 0 && cmd[count] != '/')
		count--;
	return (count + 1);
}

void	run_simple_commande(int is_path, t_parsing *shell, \
	char **content, t_minishell *mini)
{
	if (is_path == 1)
	{
		if (execve(shell->cmd, join_two_dim_arr(shell->cmd + \
			length_cmd(shell->cmd), content), mini->env_v) == -1)
			cmd_not_found(shell->cmd, mini);
	}
	else
	{
		if (execve(find_cmd_path(shell->cmd, mini, shell), \
			join_two_dim_arr(shell->cmd, content), mini->env_v) == -1)
			cmd_not_found(shell->cmd, mini);
	}
}

void	execut(t_parsing *shell, t_minishell *mini, int ispipe)
{
	int		status;
	int		pid;
	int		size_new_vars;
	int		check;
	char	**new_arg;

	if (search_for_heardoc(shell->args))
		herdoc(shell->args, mini);
	if (ispipe == 1)
		pipe(mini->pipefd);
	else if (ispipe == 2)
		pipe(mini->pipefd2);
	pid = fork();
	if (pid == 0)
	{
		if (ispipe == 1)
		{
			close(mini->pipefd[0]);
			dup2(mini->pipefd[1], STDOUT_FILENO);
			close(mini->pipefd[1]);
		}
		else if (ispipe == 2)
		{
			close(mini->pipefd[0]);
			dup2(mini->pipefd[1], STDOUT_FILENO);
			close(mini->pipefd[1]);
			close(mini->pipefd2[0]);
			dup2(mini->pipefd2[1], STDOUT_FILENO);
			close(mini->pipefd2[1]);
		}
		check = 0;
		if (is_redirec_output(shell->args) == 1)
		{
			check = 1;
			if (redirect(1, shell, shell->args, mini) != 0)
				exit(1);
		}
		if (check == 1 && ft_strlen(shell->cmd) == 0)
			exit(0);
		size_new_vars = count_length_two_arr(shell->args);
		new_arg = malloc(sizeof(char *) * (size_new_vars + 1));
		shell->args = get_new_arg(new_arg, shell->args, size_new_vars, mini);
		if (str_cmp("./minishell", shell->cmd))
		{
			mini->shlvl = ft_itoa(ft_atoi(mini->shlvl) + 1);
			update_exported_var(get_value_from_env(mini->env_v, "SHLVL"), \
				mini, "SHLVL", mini->shlvl);
		}
		if (str_cmp(find_cmd_path(shell->cmd + length_cmd(shell->cmd), \
			mini, shell), shell->cmd))
			run_simple_commande(1, shell, shell->args, mini);
		else
			run_simple_commande(0, shell, shell->args, mini);
	}
	else
	{
		if (ispipe == 1)
		{
			close(mini->pipefd[1]);
			dup2(mini->pipefd[0], STDIN_FILENO);
			close(mini->pipefd[0]);
		}
		else if (ispipe == 2)
		{
			close(mini->pipefd[1]);
			dup2(mini->pipefd[0], STDIN_FILENO);
			close(mini->pipefd[0]);
			close(mini->pipefd2[1]);
			dup2(mini->pipefd2[0], STDIN_FILENO);
			close(mini->pipefd2[0]);
		}
		if (!ispipe)
			waitpid(pid, &status, 0);
		else
			waitpid(pid, &status, WNOHANG);
		captur.exit_status = status / 256;
	}
}
