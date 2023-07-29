/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd_exist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:40:48 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/29 18:47:14 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_cmd_exist(t_parsing *shell, t_minishell __unused *ms)
{
	char	*old_cmd;

	old_cmd = ft_strdup(shell->cmd);
	if (ft_strlen(old_cmd) == 0)
	{
		if (shell->args[0] && (shell->args[0][0] != '>' \
			&& shell->args[0][0] != '<'))
		{
			shell->cmd = ft_strdup(shell->args[0]);
			shell->args = shell->args + 1;
		}
	}
	//free(old_cmd);
}
