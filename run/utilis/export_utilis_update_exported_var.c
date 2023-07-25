/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utilis_update_exported_var.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 10:22:07 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/25 18:45:50 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../minishell.h"


void	update_exported_var(char *content, \
	t_minishell *shell, char *name, char *value)
{
	int		count;
	char	**splited;

	count = 0;
	while (count < shell->n_var_env)
	{
		splited = ft_split(shell->env_v[count], '=');
		if (str_cmp(name, splited[0]))
		{
			if (ft_strchr(content, '=') != NULL)
			{
				shell->env_v[count] = ft_strjoin(ft_strjoin(name, "="), value);
				free_double(splited);
				return ;
			}
		}
		free_double(splited);
		count++;
	}
	return ;
}
