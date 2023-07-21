/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:21:08 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/21 19:13:14 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

int	main(int __unused ac, char __unused **av, char **env)
{
	t_minishell	*minishell;
	char		*line;

	minishell = malloc(sizeof(t_minishell));
	if (!minishell)
		return (0);
	minishell->env_v = env;
	set_env(minishell);
	signal(SIGQUIT, handle_signals);
	signal(SIGINT, handle_signals);
	minishell->_stdin = dup(STDIN_FILENO);
	minishell->_stdout = dup(STDOUT_FILENO);
	captur.exit_status = 0;
	minishell->shlvl = get_env_value("SHLVL", minishell);
	while (1)
	{
		update_env_ontime(NULL, minishell);
		line = readline("minishell ❯❯❯ ");
		handle_ctl_d(line);
		if (*line && is_not_space(line))
		{
			add_history(line);
			parsing_input(minishell, line);
			count_redirections(minishell);
			start_cmd(minishell, line);
			free(line);
		}
	}
	return (0);
}
