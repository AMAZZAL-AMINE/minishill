/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_variabls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:52:28 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/29 20:27:41 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

typedef struct t_data
{
	int		count;
	int		index;
	char	**dst;
	char	*arg;
}	t_data;

int	init_data_structer_split_var(t_data *data, int size, char *arg)
{
	data->count = 0;
	data->index = 0;
	data->arg = arg;
	data->dst = ft_malloc(sizeof(char *) * (size + 1), 0, ALLOC, 0);
	if (!data->dst)
		return (0);
	return (1);
}

int	if_index_equal_to_zero(t_data *data)
{
	if (data->index == 0)
	{
		if (data->arg[0] != '$')
		{
			data->count = 0;
			while (data->arg[data->count])
			{
				if (data->arg[data->count] == '$')
					return (0);
				data->count++;
			}
			data->dst[data->index] = ft_strndup(data->arg, data->count);
			data->index++;
			data->arg = ft_strchr(data->arg, '$');
		}
	}
	return (1);
}

int	start_spliting_vars(t_data *data)
{
	if (*data->arg && data->arg[0] == '$')
	{
		if (!data->arg[1])
		{
			data->dst[data->index - 1] = ft_strjoin(data->dst[data->index - 1], \
				"$");
			return (0);
		}
		data->count = 0;
		while (data->arg[data->count])
		{
			if (data->arg[data->count] == '$' && data->count != 0)
				return (0);
			data->count++;
		}
		data->dst[data->index] = ft_strndup(data->arg, data->count);
		data->arg = ft_strchr(data->arg + 1, '$');
	}
	data->index++;
	return (1);
}

char	**split_variabls(char *arg, int size)
{
	t_data	data;

	if (!init_data_structer_split_var(&data, size, arg))
		return (NULL);
	while (data.index < size)
	{
		if (!if_index_equal_to_zero(&data))
			break ;
		if (!start_spliting_vars(&data))
			break ;
		if (data.arg == NULL)
			break ;
	}
	data.dst[data.index++] = NULL;
	return (data.dst);
}
