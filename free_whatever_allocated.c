/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_whatever_allocated.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 21:29:11 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/25 16:57:09 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	double_free(char **str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		free(str[index]);
		index++;
	}
	free(str);
}

void	free_whatever_allocated(t_minishell *minishell, \
	char __unused *line)
{
	int	count;

	count = 0;
	while (count <= minishell->n_cmd)
	{
		free(minishell->parsing[count].cmd);
		double_free(minishell->parsing[count].args);
		count++;
	}
	free(minishell->parsing);
	free(minishell->env_v);
	free(minishell->shlvl);
}