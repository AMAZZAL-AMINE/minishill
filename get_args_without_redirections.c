/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args_without_redirections.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 22:28:04 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/28 04:21:58 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_args_without_redirections(char **args)
{
	char	**new_args;
	int		count;
	int		index;

	count = 0;
	index = 0;
	while (args[index] && (!str_cmp(args[index], ">") \
		&& !str_cmp(args[index], ">>") \
		&& !str_cmp(args[index], "<") && !str_cmp(args[index], "<<")))
	{
		index++;
	}
	new_args = malloc(sizeof(char *) * (index + 1));
	count = 0;
	while (count < index)
	{
		new_args[count] = ft_strdup(args[count]);
		count++;
	}
	new_args[count] = NULL;
	free_double(args);
	return (new_args);
}
