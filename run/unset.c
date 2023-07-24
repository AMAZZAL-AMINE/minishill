/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:48:42 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/24 19:24:04 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	unset_arr_string(t_minishell *ms, t_parsing *shell)
{
	int		count;
	int		index;
	char	**splpited;

	count = -1;
	while (shell->args[++count])
	{
		if (!unset_not_valid_identifier(shell->args[count]))
		{
			index = -1;
			while (ms->env_v[++index])
			{
				splpited = ft_split(ms->env_v[index], '=');
				if (str_cmp(shell->args[count], splpited[0]))
				{
					while ((index + 1) <= ms->n_var_env)
					{
						ms->env_v[index] = ms->env_v[index + 1];
						index++;
					}
					break ;
				}
			}
		}
	}
}

void	unset(t_minishell *ms, t_parsing *shell)
{
	int		count;
	int		index;

	unset_arr_string(ms, shell);
	count = 0;
	while (shell->args[count])
	{
		index = 0;
		while (index < ms->n_var_env)
		{
			if (str_cmp(ms->env[index].name, shell->args[count]))
			{
				while (index <= ms->n_var_env)
				{
					if (index + 1 <= ms->n_var_env)
						ms->env[index] = ms->env[index + 1];
					index++;
				}
				ms->n_var_env--;
				break ;
			}
			index++;
		}
		count++;
	}
	captur.exit_status = 0;
}
