/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_redirection_and_files.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:39:32 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/29 20:25:01 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	count_redirection_and_files(char **args)
{
	int	count;
	int	count_returend;

	count = 0;
	count_returend = 0;
	while (args[count])
	{
		if (is_redirect(args[count]))
		{
			if (args[count + 1])
				count_returend++;
			count_returend++;
		}
		count++;
	}
	if (count_returend == 0)
		return (1);
	return (count_returend);
}

int	is_quot_in_cmd(char *cmd)
{
	int	count;

	count = 0;
	while (cmd[count])
	{
		if (cmd[count] == '\'' || cmd[count] == '\"')
			return (1);
		count++;
	}
	return (0);
}

int	count_argment_without_red(char **args)
{
	int	count;
	int	reterned_count;

	count = 0;
	reterned_count = 0;
	while (args[count])
	{
		if (count == 0 && !is_redirect(args[count]))
			reterned_count++;
		else
			if (count - 1 >= 0 && !is_redirect(args[count - 1]) \
				&& !is_redirect(args[count]))
				reterned_count++;
		count++;
	}
	return (reterned_count);
}

int	is_commande_var(t_parsing *shell, t_minishell __unused *mini, \
	int __unused index)
{
	char	**cmd;
	char	**new_args;

	cmd = ft_split(shell->cmd, ' ');
	if (count_length_two_arr(cmd) > 0)
	{
		shell->cmd = cmd[0];
		new_args = cmd + 1;
		shell->args = join_tables(new_args, shell->args);
	}
	return (0);
}

int	length_new_cmd(char *arg)
{
	int	count;
	int	count_s_quot;
	int	count_d_quot;

	count = 0;
	count_s_quot = 0;
	count_d_quot = 0;
	while (arg[count])
	{
		if (arg[count] == '\'')
			count_s_quot++;
		if (arg[count] == '\"')
			count_d_quot++;
		if ((arg[count] == ' ' || arg[count] == '>' \
			|| arg[count] == '<') && \
			(count_s_quot % 2 == 0 && count_d_quot % 2 == 0))
			break ;
		count++;
	}
	return (count);
}
