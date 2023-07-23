/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_splited_words.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 01:09:55 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/23 01:40:59 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

typedef struct t_data
{
	int	count;
	int	count_quots;
	int	retured_value;
	int	helped_counter;
	int	saved;
}	t_data;

void	init_data_structer_count_words(t_data *data)
{
	data->count = 0;
	data->count_quots = 0;
	data->retured_value = 0;
	data->helped_counter = 0;
	data->saved = 0;
}

int	count_splited_words(char *token)
{
	t_data	data;

	init_data_structer_count_words(&data);
	while (token[data.count])
	{
		if (token[data.count] == '\'' || token[data.count] == '\"')
			data.count_quots++;
		if (((token[data.count] == ' ') && data.count_quots % 2 == 0) \
			|| data.count == 0)
			data.retured_value++;
		if ((token[data.count] == '>' || token[data.count] == '<') \
			&& data.count_quots % 2 == 0)
			data.helped_counter++;
		data.saved = data.count;
		while ((token[data.saved] == ' ') && data.count_quots % 2 == 0)
			data.saved++;
		if (data.saved == data.count)
			data.count++;
		else
			data.count = data.saved;
	}
	return (data.retured_value + data.helped_counter);
}
