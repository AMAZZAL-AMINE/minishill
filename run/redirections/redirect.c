/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 21:03:03 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/27 06:25:40 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**red_utilis(char **content, t_minishell *mini)
{
	int		count;
	char	**new_content;

	new_content = duplicate_content(content);
	count = 0;
	while (new_content[count])
	{
		if (is_dolar_(new_content[count]) && \
			is_bettwen_double(new_content[count]))
			new_content[count] = expand(new_content[count], mini);
		new_content[count] = remove_quots(new_content[count]);
		count++;
	}
	return (new_content);
}

int	redirect_utilis(char **content, t_minishell *mini, \
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

int	redirect(int __unused is_path, t_parsing *shell, \
	char **content, t_minishell __unused *mini)
{
	int		captur;
	int		count;
	char	**new_content;

	new_content = red_utilis(content, mini);
	captur = 0;
	count = 0;
	while (content[count])
	{
		captur = redirect_utilis(content, mini, count, new_content);
		if (captur != 0)
			break ;
		count++;
	}
	shell->args = get_args_without_redirections(shell->args);
	free_double(new_content);
	return (captur);
}
