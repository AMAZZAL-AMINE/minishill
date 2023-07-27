/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:05:53 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/27 15:19:52 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

typedef struct t_data
{
	int		count;
	char	*var;
	char	*value;
	int		return_status;
	char	**arg_splited;
	int		is_last_equal;
	char	**new_args;
}	t_data;

void	run_utilis(t_data *data, t_minishell *ms)
{
	if (data->new_args[data->count][ft_strlen(data->new_args[data->count]) - 1] \
		== '=')
		data->is_last_equal = 1;
	if (str_cmp(data->new_args[data->count], "=") \
		|| data->new_args[data->count][0] == '=')
	{
		if (data->new_args[data->count][0] == '=')
			data->var = data->new_args[data->count];
		else
			data->var = "=";
	}
	else
	{
		data->arg_splited = ft_split(data->new_args[data->count], '=');
		data->var = data->arg_splited[0];
	}
	data->value = data->new_args[data->count] + (ft_strlen(data->var) + 1);
	if (!data->value)
		data->value = "";
	if (export_to_en(ms, data->var, \
		data->value, data->new_args[data->count]) == 1)
		data->return_status = 1;
	free_double(data->arg_splited);
}

void	init_data(t_data *data, t_parsing *shell)
{
	data->count = 0;
	data->var = NULL;
	data->value = NULL;
	data->return_status = 0;
	data->is_last_equal = 0;
	data->new_args = shell->args;
}

void	export(t_parsing *shell, t_minishell *ms)
{
	t_data	data;

	init_data(&data, shell);
	if (!*data.new_args)
		get_exported_vars(ms);
	else
	{
		while (data.new_args[data.count])
		{
			run_utilis(&data, ms);
			data.count++;
		}
	}
	if (data.return_status == 1)
		captur.exit_status = 1;
	else
		captur.exit_status = 0;
}
