/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:21:08 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/30 22:28:59 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_env_vars(char **envs)
{
	int	count;

	count = 0;
	while (envs[count])
		count++;
	return (count);
}

int	is_not_space(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int	init_structer(t_minishell *minishell, char **env)
{
	minishell->env_v = env;
	minishell->n_var_env = count_env_vars(minishell->env_v);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, handle_signals);
	minishell->_stdin = dup(STDIN_FILENO);
	minishell->_stdout = dup(STDOUT_FILENO);
	captur.exit_status = 0;
	minishell->shlvl = get_env_value("SHLVL", minishell);
	return (1);
}

int	main(int __unused ac, char __unused **av, char **env)
{
	t_minishell	*minishell;
	char		*line;

	minishell = malloc(sizeof(t_minishell));
	if (!minishell)
		return (0);
	if (init_structer(minishell, env) == 0)
		return (0);
	while (1)
	{
		line = readline("minishell ❯❯❯ ");
		handle_ctl_d(line, minishell);
		if (*line && is_not_space(line))
		{
			add_history(line);
			parsing_input(minishell, line);
			start_cmd(minishell, line);
			ft_malloc(0, 0, FREE_ALL, 0);
		}
		free(line);
	}
	return (0);
}
