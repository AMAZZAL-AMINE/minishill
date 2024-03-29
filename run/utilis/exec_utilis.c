/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utilis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 21:16:47 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/29 18:46:21 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_redirec_output(char **args)
{
	int	count;
	int	is_redirec;

	count = 0;
	is_redirec = 0;
	while (args[count])
	{
		if (str_cmp(">", args[count]) \
			|| str_cmp("<", args[count]) \
			|| str_cmp(">>", args[count]) \
			|| str_cmp("<<", args[count]))
			is_redirec = 1;
		count++;
	}
	return (is_redirec);
}

char	**new_content(char **content)
{
	int		count;
	int		index;
	char	**dst;

	count = 0;
	index = 0;
	if (is_redirec_output(content) == 0)
		return (content);
	while (content[index][0] != '>' \
		&& content[index][0] != '<' && content[index])
	{
		index++;
	}
	dst = ft_malloc(sizeof(char *) * (index + 1), 0, ALLOC, 0);
	while (count < index)
	{
		dst[count] = ft_strdup(content[count]);
		count++;
	}
	dst[count] = NULL;
	return (dst);
}
