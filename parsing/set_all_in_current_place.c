/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_all_in_current_place.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:44:15 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/22 16:34:19 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	count_redirections(t_minishell *shell)
{
	int	count;
	int	index;
	int	count_out;
	int	count_in;

	count = 0;
	while (count <= shell->n_cmd)
	{
		index = 0;
		count_out = 0;
		count_in = 0;
		while (shell->parsing[count].args[index])
		{
			if (str_cmp(shell->parsing[count].args[index], ">"))
				count_out++;
			else if (str_cmp(shell->parsing[count].args[index], "<"))
				count_in++;
			else if (str_cmp(shell->parsing[count].args[index], ">>"))
				count_out++;
			else if (str_cmp(shell->parsing[count].args[index], "<<"))
				count_in++;
			index++;
		}
		shell->parsing[count].n_out_files = count_out;
		shell->parsing[count].n_in_files = count_in;
		count++;
	}
}
