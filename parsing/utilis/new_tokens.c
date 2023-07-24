/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:09:46 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/24 21:19:36 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	find_index_pipe(char *line)
{
	int	count;
	int	opened_quote;
	int	opened_si_quot;

	count = 0;
	opened_quote = 0;
	opened_si_quot = 0;
	while (line[count] != '\0')
	{
		if (line[count] == '\"')
			opened_quote++;
		if (line[count] == '\'')
			opened_si_quot++;
		if (line[count] == '|')
			if ((opened_quote % 2 == 0 && opened_si_quot % 2 == 0))
				return (count);
		count++;
	}
	return (count);
}

char	*pip_strchr(char *arg)
{
	int	count;
	int	opened_quote;
	int	opened_si_quot;

	count = 0;
	opened_quote = 0;
	opened_si_quot = 0;
	while (arg[count])
	{
		if (arg[count] == '\"')
			opened_quote++;
		if (arg[count] == '\'')
			opened_si_quot++;
		if (arg[count] == '|')
			if ((opened_quote % 2 == 0 && opened_si_quot % 2 == 0))
				return (arg + (count + 1));
		count++;
	}
	return (NULL);
}

typedef struct t_data
{
	int		count;
	int		count_tokens;
	char	**tokens;
	char	*new_line;
}	t_data;

void	init_data_structer(t_data *data, char *line)
{
	data->count = 0;
	data->count_tokens = ft_count_tokens(line) * 2;
	data->tokens = malloc(sizeof(char *) * (data->count_tokens + 2));
	data->new_line = line;
}

int	utilis_func(t_data	*data)
{
	data->tokens[data->count] = ft_strndup(data->new_line, \
		find_index_pipe(data->new_line));
	data->new_line = pip_strchr(data->new_line);
	data->count++;
	if (!data->new_line)
		return (1);
	data->tokens[data->count] = "|";
	data->count++;
	return (0);
}

char	**new_tokens(char *line)
{
	t_data	data;

	init_data_structer(&data, line);
	if (!data.tokens)
		return (NULL);
	while (data.count <= data.count_tokens)
	{
		if (find_index_pipe(data.new_line) == 0)
		{
			data.tokens[data.count] = ft_strndup(data.new_line, \
				ft_strlen(data.new_line));
			data.count++;
		}
		else
			if (utilis_func(&data))
				break ;
	}
	data.tokens[data.count] = NULL;
	return (data.tokens);
}
