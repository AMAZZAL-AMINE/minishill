/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:21:08 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/29 16:21:22 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

void	free_double(char **str)
{
	int	i;

	i = 0;
	if (str[0] && ft_strlen(str[0]) == 0)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	please_free_me(t_minishell *minishell)
{
	int	i;
	int	count;

	i = 0;
	while (minishell->n_cmd >= i)
	{
		count = 0;
		while (minishell->parsing[i].args[count]) {
			free(minishell->parsing[i].args[count]);
			count++;
		}
		free(minishell->parsing[i].args);
		free(minishell->parsing[i].cmd);
		free(minishell->parsing[i].cmd_tmp);
		i++;
	}
	free_double(minishell->tokens);
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
	set_env(minishell);
	signal(SIGQUIT, handle_signals);
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
			please_free_me(minishell);
			free(minishell->parsing);
			// system("leaks minishell | grep 'leak'");
		}
		free(line);
	}
	return (0);
}
// echo 1$USER$USER-
