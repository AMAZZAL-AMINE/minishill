/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis_part1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:47:59 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/24 19:52:29 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_bettwen_double(char *arg)
{
	int	count;

	count = 0;
	while (arg[count])
	{
		if (arg[count] == '$')
			return (1);
		if (arg[count] == '\'')
			return (0);
		else if (arg[count] == '\"')
			return (1);
		count++;
	}
	return (1);
}

int	is_dolar_var(char *arg)
{
	int	count;

	count = 0;
	while (arg[count])
	{
		if (arg[count] == '$')
			return (1);
		count++;
	}
	return (0);
}

typedef struct t_data
{
	int		count;
	int		index;
	char	*mini_dst;
}	t_data;

int	init_data_fet_new_arg(t_data *data)
{
	data->count = 0;
	data->index = 0;
	return (0);
}

char	**get_new_arg(char **dst, char **args, int __unused size, \
	t_minishell *minishell)
{
	t_data	data;
	char		*tmp;

	init_data_fet_new_arg(&data);
	while (args[data.count])
	{
		tmp = args[data.count];
		if (is_dolar_var(tmp) && \
			is_bettwen_double(tmp))
		{
			data.mini_dst = remove_quots(expand(tmp, minishell));
			if (*data.mini_dst)
			{
				dst[data.index] = data.mini_dst;
				data.index++;
			}
		}
		else
		{
			dst[data.index] = remove_quots(tmp);
			data.index++;
		}
		free(tmp);
		data.count++;
	}
	dst[data.index] = NULL;
	return (dst);
}
