/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execut.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 07:40:31 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/25 22:55:55 by mamazzal         ###   ########.fr       */
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

void	run_simple_commande(t_parsing *shell, \
	char **content, t_minishell *mini)
{
	char *tmp = find_cmd_path(shell->cmd + length_cmd(shell->cmd), \
		mini, shell);
	if (str_cmp(tmp, shell->cmd))
	{
		free(tmp);
		shell->args = join_two_dim_arr(shell->cmd +	length_cmd(shell->cmd), content);
		if (execve(shell->cmd, shell->args, mini->env_v) == -1) {
			cmd_not_found(shell->cmd, mini);
		}
	}
	else
	{
		free(tmp);
		shell->args = join_two_dim_arr(shell->cmd, content);
		if (execve(find_cmd_path(shell->cmd, mini, shell), shell->args, mini->env_v) == -1) {
			cmd_not_found(shell->cmd, mini);
		}
	}
}

void	is_redirect_utilise(t_parsing *shell, t_minishell *mini)
{
	int	check;

	check = 0;
	if (is_redirec_output(shell->args) == 1)
	{
		check = 1;
		if (redirect(1, shell, shell->args, mini) != 0)
			exit(1);
	}
	if (check == 1 && ft_strlen(shell->cmd) == 0)
		exit(0);
}

void	run_cmd_inside_child(t_parsing *shell, t_minishell *mini, int ispipe)
{
	int		size_new_vars;
	char	**new_arg;

	if (ispipe == 1)
		open_child_between_pieps(mini, 0);
	else if (ispipe == 2)
		open_child_between_pieps(mini, 1);
	is_redirect_utilise(shell, mini);
	size_new_vars = count_length_two_arr(shell->args);
	new_arg = malloc(sizeof(char *) * (size_new_vars + 1));
	shell->args = get_new_arg(new_arg, shell->args, size_new_vars, mini);
	if (str_cmp("./minishell", shell->cmd))
	{
		mini->shlvl = ft_itoa(ft_atoi(mini->shlvl) + 1);
		update_exported_var(get_value_from_env(mini->env_v, "SHLVL"), \
			mini, "SHLVL", mini->shlvl);
	}
	run_simple_commande(shell, shell->args, mini);
}

void	execut(t_parsing *shell, t_minishell *mini, int ispipe)
{
	int		status;
	int		pid;

	if (search_for_heardoc(shell->args))
		herdoc(shell->args, mini);
	if (ispipe == 1)
		pipe(mini->pipefd);
	else if (ispipe == 2)
		pipe(mini->pipefd2);
	pid = fork();
	if (pid == 0)
		run_cmd_inside_child(shell, mini, ispipe);
	else
	{
		if (ispipe == 1)
			close_child_between_pieps(mini, 0);
		else if (ispipe == 2)
			close_child_between_pieps(mini, 1);
		if (!ispipe)
			waitpid(pid, &status, 0);
		else
			waitpid(pid, &status, WNOHANG);
		captur.exit_status = status / 256;
	}
}
