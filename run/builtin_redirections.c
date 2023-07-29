/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_redirections.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 10:40:31 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/29 13:31:56 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_dolar_(char *str)
{
	int	count;

	count = 0;
	while (str[count])
	{
		if (str[count] == '$')
			return (1);
		count++;
	}
	return (0);
}

char	**get_new_args(char **content, t_minishell *mini)
{
	int		count;
	char	**new_content;
 
	count = 0;
	new_content = duplicate_content(content);
	count = 0;
	while (new_content[count])
	{
		if (is_dolar_(new_content[count]) && is_bettwen_double(new_content[count]))
			new_content[count] = expand(new_content[count], mini);
		new_content[count] = remove_quots(new_content[count]);
		count++;
	}
	return (new_content);
}

int	run_redirections(char **content, t_minishell *mini, \
	int count, char **new_content)
{
	int	captur;

	captur = 0;
	if (str_cmp(">", content[count]))
	{
		captur = check_redrect_output(new_content, mini, count, \
			content[count + 1]);
		if (captur != 0)
			return (captur);
	}
	if (str_cmp("<", content[count]))
	{
		captur = check_redrect_input(new_content, mini, count, \
			content[count + 1]);
		if (captur != 0)
			return (captur);
	}
	if (str_cmp(">>", content[count]))
	{
		captur = check_appned(mini, content[count + 1], count, new_content);
		if (captur != 0)
			return (captur);
	}
	return (0);
}

int	builtin_redirections(char **content, t_parsing *shell, t_minishell *mini)
{
	int		captur;
	int		count;
	char	**new_content;

	count = 0;
	captur = 0;
	if (search_for_heardoc(content))
		herdoc(content, mini);
	if (is_redirec_output(content))
	{
		new_content = get_new_args(content, mini);
		count = 0;
		while (content[count])
		{
			captur = run_redirections(content, mini, count, new_content);
			if (captur == 1)
				break ;
			count++;
		}
		shell->args = get_args_without_redirections(shell->args);
		free_double(new_content);
	}
	return (captur);
}
