/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:48:42 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/25 17:02:46 by rouali           ###   ########.fr       */
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
					while ((index + 1) < ms->n_var_env)
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
	unset_arr_string(ms, shell);
	captur.exit_status = 0;
}
