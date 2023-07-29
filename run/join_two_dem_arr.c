/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_two_dem_arr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:26:05 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/29 18:47:14 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count_length_two_arr(char **arr)
{
	int	count;

	count = 0;
	while (arr[count])
		count++;
	return (count);
}

char	**join_two_dim_arr(char *s1, char **arr)
{
	int		count;
	int		size;
	char	**dst;

	count = 1;
	size = count_length_two_arr(arr) + 1;
	dst = ft_malloc(sizeof(char *) * (size + 1), 0, ALLOC, 0);
	dst[0] = s1;
	while (count < size)
	{
		dst[count] = arr[count - 1];
		count++;
	}
	dst[count] = 0;
	//free(arr);
	return (dst);
}
