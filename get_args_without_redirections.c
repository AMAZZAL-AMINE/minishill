/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args_without_redirections.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 22:28:04 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/29 18:47:14 by rouali           ###   ########.fr       */
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
	new_args = ft_malloc(sizeof(char *) * (index + 1), 0, ALLOC, 0);
	count = 0;
	while (count < index)
	{
		new_args[count] = args[count];//str dup
		count++;
	}
	new_args[count] = NULL;
	//free(args);//free hna
	return (new_args);
}
