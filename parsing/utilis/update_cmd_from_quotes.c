/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_cmd_from_quotes.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:46:14 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/22 20:34:38 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

typedef struct t_data
{
	int		len;
	int		count_s_quot;
	int		count_d_quot;
	int		count;
	int		index;
	char	*new_cmd;
}	t_data;

void	init_data_structer_update(t_data *data)
{
	data->len = 0;
	data->count_s_quot = 0;
	data->count_d_quot = 0;
	data->count = 0;
	data->index = 0;
}

int	update_utilis(t_data *data, char *cmd)
{
	data->len = data->count;
	data->count_d_quot = 0;
	data->count_s_quot = 0;
	data->new_cmd = malloc(sizeof(char) * (data->len + 1));
	if (!data->new_cmd)
		return (0);
	data->count = 0;
	while (cmd[data->count])
	{
		if (cmd[data->count] == '\'' && data->count_d_quot == 0)
			data->count_s_quot++;
		else if (cmd[data->count] == '\"' && data->count_s_quot == 0)
			data->count_d_quot++;
		else
		{
			data->new_cmd[data->index] = cmd[data->count];
			data->index++;
		}
		data->count++;
	}
	data->new_cmd[data->index] = '\0';
	return (1);
}

char	*update_cmd_from_quotes(char *cmd)
{
	t_data	data;

	init_data_structer_update(&data);
	while (cmd[data.count])
	{
		if (cmd[data.count] == '\"' && data.count_s_quot == 0)
			data.count_d_quot++;
		if (cmd[data.count] == '\'' && data.count_d_quot == 0)
			data.count_s_quot++;
		data.count++;
	}
	if (!update_utilis(&data, cmd))
		return (NULL);
	return (data.new_cmd);
}
