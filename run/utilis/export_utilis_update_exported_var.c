/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utilis_update_exported_var.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 10:22:07 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/25 16:10:01 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	update_exported_var_structr(t_minishell *shell, char *name, \
	char *value, char *content)
{
	int	count;

	count = 0;
	while (count < shell->n_var_env)
	{
		if (str_cmp(name, shell->env[count].name))
		{
			if (ft_strchr(content, '=') != NULL)
			{
				shell->env[count].is_haver_equal = 1;
				shell->env[count].value = value;
			}
		}
		count++;
	}
}

void	update_exported_var(char *content, \
	t_minishell *shell, char *name, char *value)
{
	int		count;
	char	**splited;

	update_exported_var_structr(shell, name, value, content);
	count = 0;
	while (count < shell->n_var_env)
	{
		splited = ft_split(shell->env_v[count], '=');
		if (str_cmp(name, splited[0]))
		{
			if (ft_strchr(content, '=') != NULL)
			{
				shell->env_v[count] = ft_strjoin(ft_strjoin(name, "="), value);
				return ;
			}
		}
		free_double(splited);
		count++;
	}
	return ;
}
