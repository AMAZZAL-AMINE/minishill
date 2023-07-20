/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_tables.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 15:10:49 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/20 19:48:07 by mamazzal         ###   ########.fr       */
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
	if (table1 == NULL)
		return (table2);
	size = count_length_two_arr(table1) + count_length_two_arr(table2);
	dst = malloc(sizeof(char *) * (size + 1));
	while (table1[count])
		dst[index++] = table1[count++];
	count = 0;
	while (table2[count])
		dst[index++] = table2[count++];
	dst[index] = NULL;
	return (dst);
}
