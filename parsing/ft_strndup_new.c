/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 01:28:26 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/29 18:43:06 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strndup_new(char const *str, size_t max)
{
	size_t	index;
	char	*dst;
	int		count_quots;

	index = 0;
	dst = ft_malloc(sizeof(char) * (max + 1), 0, ALLOC, 0);
	if (!dst)
		return (0);
	count_quots = 0;
	while (str[index] && index < max)
	{
		if (str[index] == '\"' || str[index] == '\'')
			count_quots++;
		if ((str[index] == '>' || str[index] == '<') \
			&& count_quots % 2 == 0)
			break ;
		dst[index] = str[index];
		index++;
	}
	dst[index] = '\0';
	return (dst);
}
