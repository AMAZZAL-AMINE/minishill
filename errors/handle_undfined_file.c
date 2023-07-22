/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_undfined_file.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 22:08:10 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/22 13:27:54 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	isredirection(char str)
{
	if (str == '>' || str == '<')
		return (1);
	return (0);
}

int	syntax_error_msg(void)
{
	printf("minishell: syntax error near unexpected \
		token `newline'\n");
	captur.exit_status = 258;
	return (1);
}

int	handle_undfined_file(char **content)
{
	int	count;

	count = 0;
	while (content[count])
	{
		if (str_cmp(">", content[count]) || str_cmp("<", content[count]) \
			|| str_cmp(">>", content[count]) || str_cmp("<<", content[count]))
			if (!content[count + 1])
				return (syntax_error_msg());
		count++;
	}
	count = 0;
	while (content[count])
	{
		if (content[count][2] && (isredirection(content[count][0]) \
			&& isredirection(content[count][1]) \
			&& isredirection(content[count][2])))
		{
			if (!content[count + 1])
				return (syntax_error_msg());
		}
		count++;
	}
	return (0);
}
