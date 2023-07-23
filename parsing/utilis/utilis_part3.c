/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis_part3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:08:21 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/22 22:10:41 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_count_tokens(char *line)
{
	int	count;
	int	count_tokens;
	int	opened_quote;
	int	s_opened_quote;

	count = 0;
	count_tokens = 0;
	opened_quote = 0;
	s_opened_quote = 0;
	while (line[count] != '\0')
	{
		if (line[count] == '\"')
			opened_quote++;
		if (line[count] == '\'')
			s_opened_quote++;
		if (line[count] == '|' && \
			(opened_quote % 2 == 0 && s_opened_quote % 2 == 0))
			count_tokens++;
		count++;
	}
	return (count_tokens);
}

typedef struct t_data
{
	int	count;
	int	index;
	int	size;
}	t_data;

void	init_tdata(t_data *data, char *token)
{
	data->count = 0;
	data->index = 0;
	data->size = ft_strlen(token);
}

int	commande_length(char *token)
{
	t_data	data;

	init_tdata(&data, token);
	while (data.count < data.size)
	{
		if (data.count == 0)
		{
			while (token[data.count] == ' ' && token[data.count])
				data.count++;
			if (token[data.count] != '\0')
			{
				while (token[data.count] && token[data.count] != ' ')
				{
					if (token[data.count] == '>' || token[data.count] == '<')
						return (data.index);
					data.index++;
					data.count++;
				}
			}
		}
		data.count++;
	}
	if (token[data.index] == ' ')
		return (data.index--);
	return (data.index);
}
