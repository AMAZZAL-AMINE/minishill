/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:36:52 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/22 19:59:14 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

typedef struct t_data
{
	char	**dst;
	int		index;
	int		count;
	char	**dst_two;
}	t_data;

int	init_data_structer_sort_args(t_data *data, char **oldargs)
{
	data->index = 0;
	data->count = 0;
	data->dst = malloc(sizeof(char *) * \
		(count_redirection_and_files(oldargs) + 1));
	if (!data->dst)
		return (1);
	return (0);
}

int	is_redirect(char *red)
{
	if (str_cmp(red, ">") || str_cmp(red, ">>") \
		|| str_cmp(red, "<") || str_cmp(red, "<<"))
		return (1);
	return (0);
}

void	split_redirection_and_files(t_data *data, char **oldargs)
{
	while (oldargs[data->count])
	{
		if (is_redirect(oldargs[data->count]))
		{
			data->dst[data->index] = oldargs[data->count];
			data->index++;
			data->count++;
			if (!oldargs[data->count])
				break ;
			if (oldargs[data->count])
			{
				data->dst[data->index] = oldargs[data->count];
				data->index++;
			}
		}
		if (!*oldargs[data->count])
			break ;
		data->count++;
	}
	data->dst[data->index] = NULL;
}

void	split_args_are_not_redirections(t_data *data, char **oldargs)
{
	while (oldargs[data->count])
	{
		if (data->count == 0 && !is_redirect(oldargs[data->count]))
		{
			data->dst_two[data->index] = oldargs[data->count];
			data->index++;
		}
		else
		{
			if (data->count - 1 >= 0 && !is_redirect(oldargs[data->count - 1]) \
				&& !is_redirect(oldargs[data->count]))
			{
				data->dst_two[data->index] = oldargs[data->count];
				data->index++;
			}
		}
		data->count++;
	}
	data->dst_two[data->index] = NULL;
}

char	**sort_args(char **oldargs)
{
	t_data	data;

	if (init_data_structer_sort_args(&data, oldargs))
		return (NULL);
	split_redirection_and_files(&data, oldargs);
	data.dst_two = malloc(sizeof(char *) * \
		(count_argment_without_red(oldargs) + 1));
	data.index = 0;
	data.count = 0;
	split_args_are_not_redirections(&data, oldargs);
	return (join_tables(data.dst_two, data.dst));
}
