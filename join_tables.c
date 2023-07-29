/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_tables.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 15:10:49 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/29 18:41:14 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**join_tables(char **table1, char **table2)
{
	int		count;
	int		index;
	int		size;
	char	**dst;

	count = 0;
	index = 0;
	size = count_length_two_arr(table1) + count_length_two_arr(table2);
	dst = ft_malloc(sizeof(char *) * (size + 1), 0, ALLOC, 0);
	while (table1[count])
		dst[index++] = table1[count++];
	count = 0;
	while (table2[count])
		dst[index++] = table2[count++];
	dst[index] = NULL;
	return (dst);
}
