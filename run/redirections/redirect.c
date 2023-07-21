/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 21:03:03 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/21 16:11:51 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	redirect(int __unused is_path, t_parsing *shell, \
	char **content, t_minishell __unused *mini)
{
	int		captur;
	int		count;
	char	**new_content;

	captur = 0;
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
	count = 0;
	while (content[count])
	{
		if (str_cmp(">", content[count]))
		{
			if (content[count + 1] && \
				!is_ambiguous_file(content[count + 1], mini))
			{
				captur = redirect_output(new_content, count);
				if (captur != 0)
					break ;
			}
			else
			{
				captur = 1;
				break ;
			}
		}
		if (str_cmp("<", content[count]))
		{
			if (content[count + 1] && \
				!is_ambiguous_file(content[count + 1], mini))
			{
				captur = redirect_input(new_content, count);
				if (captur != 0)
					break ;
			}
			else
			{
				captur = 1;
				break ;
			}
		}
		if (str_cmp(">>", content[count]))
		{
			if (content[count + 1] && \
				!is_ambiguous_file(content[count + 1], mini))
			{
				captur = appned(new_content, count);
				if (captur != 0)
					break ;
			}
			else
			{
				captur = 1;
				break ;
			}
		}
		count++;
	}
	shell->args = get_args_without_redirections(shell->args);
	return (captur);
}
