/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 17:57:18 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/20 19:30:12 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**duplicate_content(char **content)
{
	int		count;
	char	**new_content;

	count = 0;
	new_content = NULL;
	while (content[count])
		count++;
	new_content = malloc(sizeof(char *) * (count + 1));
	count = 0;
	while (content[count])
	{
		new_content[count] = ft_strdup(content[count]);
		count++;
	}
	new_content[count] = NULL;
	return (new_content);
}
