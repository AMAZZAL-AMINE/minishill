/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_with_fixes_size.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:02:49 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/22 18:30:02 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

typedef struct t_data
{
	int		count;
	int		index;
	char	*dst;
	int		count_quots;
	int		count_s_quots;
	int		new_size;
}			t_data;

char	*get_cmd_with_fix_size_utilis(t_data *data, char *token, \
	int size)
{
	data->dst = malloc(sizeof(char) * (size + 1));
	if (!data->dst)
		return (NULL);
	while (token[data->count])
	{
		if (data->count == 0)
		{
			while (token[data->count] == ' ' && token[data->count])
				data->count++;
			if (token[data->count] != ' ' && token[data->count] != '\0')
			{
				while (data->index <= size)
				{
					if (token[data->count] == '>' || token[data->count] == '<')
						break ;
					data->dst[data->index] = token[data->count];
					data->index++;
					data->count++;
				}
				break ;
			}
		}
	}
	data->dst[data->index] = 0;
	return (data->dst);
}

void	init_struct(t_data *data)
{
	data->count = 0;
	data->index = 0;
	data->count_quots = 0;
	data->count_s_quots = 0;
	data->new_size = 0;
}

char	*get_cmd_with_fixes_size(char *token, int size)
{
	char	*dst;
	t_data	data;

	init_struct(&data);
	if (is_q_in_cmd(token))
	{
		while (token[data.count])
		{
			if ((token[data.count] == ' ' || token[data.count] == '>' \
				|| token[data.count] == '<') && (data.count_quots % 2 == 0 \
				&& data.count_s_quots % 2 == 0))
				break ;
			if (token[data.count] == '\'')
				data.count_s_quots++;
			if (token[data.count] == '\"')
				data.count_quots++;
			data.count++;
		}
		data.new_size = data.count;
		dst = ft_strndup(token, data.new_size);
	}
	else
		dst = get_cmd_with_fix_size_utilis(&data, token, size);
	return (dst);
}
