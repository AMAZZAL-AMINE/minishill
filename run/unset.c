/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:48:42 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/30 22:08:45 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

typedef struct t_data
{
	int		count;
	int		index;
	char	**splpited;
}	t_data;

void	unset_arr_string(t_minishell *ms, t_parsing *shell)
{
	t_data	data;

	data.count = -1;
	while (shell->args[++data.count])
	{
		if (!unset_not_valid_identifier(shell->args[data.count]))
		{
			data.index = -1;
			while (ms->env_v[++data.index])
			{
				data.splpited = ft_strtok(ms->env_v[data.index], '=');
				if (str_cmp(shell->args[data.count], data.splpited[0]))
				{
					while ((data.index + 1) < ms->n_var_env)
					{
						ms->env_v[data.index] = ms->env_v[data.index + 1];
						data.index++;
					}
					free_double(data.splpited);
					break ;
				}
				free_double(data.splpited);
			}
		}
	}
}

void	unset(t_minishell *ms, t_parsing *shell)
{
	unset_arr_string(ms, shell);
	captur.exit_status = 0;
}
