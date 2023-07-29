/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_commande_args.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:23:36 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/29 18:44:31 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	chekc_is_quots(char *str)
{
	int	count;
	int	count_quots;

	count = 0;
	count_quots = 0;
	while (str[count])
	{
		if (str[count] == '\'' || str[count] == '\"')
			count_quots++;
		count++;
	}
	if (count_quots % 2 == 0)
		return (1);
	else
		return (0);
}

typedef struct t_data
{
	int		count;
	int		save;
	int		index;
	int		stopen;
	int		within_quots;
	int		within_quots_two;
	char	**dst;
}	t_data;

int	init_dara_struct_split(t_data *data, char *token)
{
	data->count = 0;
	data->save = 0;
	data->index = 0;
	data->stopen = 0;
	data->within_quots = 0;
	data->within_quots_two = 0;
	data->dst = ft_malloc(sizeof(char *) * (count_splited_words(token) + 1), 0, ALLOC, 0);
	if (!data->dst)
		return (0);
	return (1);
}

int	split_commande_args_utilis_part1(char *token, \
	t_minishell __unused *minishell, t_data *data)
{
	while ((token[data->count] == ' ') && (data->within_quots % 2 == 0 \
		&& data->within_quots_two % 2 == 0))
		data->count++;
	data->stopen = data->count;
	if (token[data->count] == '\"')
		data->within_quots++;
	if (token[data->count] == '\'')
		data->within_quots_two++;
	while (token[data->count])
	{
		if ((token[data->count] == '>' || token[data->count] == '<') \
			&& (data->within_quots % 2 == 0 && data->within_quots_two % 2 == 0))
			break ;
		data->save++;
		data->count++;
		if (token[data->count] == '\"')
			data->within_quots++;
		if (token[data->count] == '\'')
			data->within_quots_two++;
		if (token[data->count] == ' ' && (data->within_quots % 2 == 0 \
			&& data->within_quots_two % 2 == 0))
			break ;
	}
	return (0);
}

int	split_commande_args_utilis_part2(char *token, t_data *data)
{
	if (data->save > 0)
	{
		data->dst[data->index] = ft_strndup_new(&token[data->stopen], \
			data->save);
		data->index++;
	}
	if ((token[data->count] == '>' || token[data->count] == '<') \
		&& (data->within_quots % 2 == 0 && data->within_quots_two % 2 == 0))
	{
		data->dst[data->index] = ft_strndup(&token[data->count], \
			get_rederection_length(&token[data->count]));
		data->index++;
	}
	return (0);
}

char	**split_commande_args(char *token, t_minishell __unused *minishell)
{
	t_data	data;

	if (!init_dara_struct_split(&data, token))
		return (NULL);
	while (token[data.count])
	{
		split_commande_args_utilis_part1(token, minishell, &data);
		split_commande_args_utilis_part2(token, &data);
		data.save = 0;
		if ((token[data.count] == '>' || token[data.count] == '<') \
			&& (data.within_quots % 2 == 0 && data.within_quots_two % 2 == 0))
			data.count += get_rederection_length(&token[data.count]);
		else
			if (token[data.count])
				data.count++;
	}
	data.dst[data.index] = NULL;
	data.dst = remove_space_from_dst(data.dst);
	(void)minishell;
	return (data.dst);
}
