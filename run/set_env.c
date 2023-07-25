/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:39:28 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/25 16:47:41 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count_env_vars(char **envs)
{
	int	count;

	count = 0;
	while (envs[count])
		count++;
	return (count);
}

 
void	set_env(t_minishell *shell)
{
	shell->n_var_env = count_env_vars(shell->env_v);
}
	