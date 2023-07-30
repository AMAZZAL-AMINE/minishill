/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_space_from_dst.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 00:31:00 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/30 21:23:39 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

typedef struct t_data
{
	int		count;
	int		within_quots;
	int		within_quots_two;
	int		helepr;
	int		helper2;
}	t_data;

void	init_data_structer_rm_sp(t_data *data)
{
		data->within_quots = 0;
		data->within_quots_two = 0;
		data->helepr = 0;
		data->helper2 = 0;
}

char	**remove_space_from_dst(char **dst)
{
	t_data	data;

	data.count = 0;
	while (dst[data.count])
	{
		init_data_structer_rm_sp(&data);
		data.helper2 = 0;
		while (dst[data.count][data.helper2])
		{
			if (dst[data.count][data.helper2] == '\'')
				data.within_quots_two++;
			if (dst[data.count][data.helper2] == '\"')
				data.within_quots++;
			if (dst[data.count][data.helper2] == ' ' \
				&& (data.within_quots % 2 == 0 \
				&& data.within_quots_two % 2 == 0))
				break ;
			data.helper2++;
		}
		dst[data.count] = ft_strndup(dst[data.count], \
			data.helper2);
		data.count++;
	}
	dst[data.count] = NULL;
	return (dst);
}
