/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utilis_update_exported_var.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 10:22:07 by mamazzal          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/07/25 16:51:24 by rouali           ###   ########.fr       */
=======
/*   Updated: 2023/07/25 16:10:01 by mamazzal         ###   ########.fr       */
>>>>>>> 8c961a81de76705618d01c1a0d24ea3e98f6d4a5
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
				return ;
			}
		}
		free_double(splited);
		count++;
	}
	return ;
}
