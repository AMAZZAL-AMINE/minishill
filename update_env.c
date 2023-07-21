/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 20:16:43 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/21 10:12:49 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ITERM_SESSION_ID

#include "minishell.h"

char	*get_value_from_env(char **conten, char *what)
{
	int	count;

	count = 0;
	while (conten[count])
	{
		if (ft_strnstr(conten[count], what, ft_strlen(what)) != NULL)
			return (conten[count]);
		count++;
	}
	return ("");
}

void	update_env_ontime(t_parsing __unused *shell, t_minishell *mini)
{
	update_exported_var(get_value_from_env(mini->env_v, \
		"ITERM_SESSION_ID"), mini, \
		"ITERM_SESSION_ID", getenv("ITERM_SESSION_ID"));
	update_exported_var(get_value_from_env(mini->env_v, \
		"LS_COLORS"), mini, "LS_COLORS", getenv("LS_COLORS"));
	update_exported_var(get_value_from_env(mini->env_v, \
		"empty"), mini, "empty", getenv("empty"));
	update_exported_var(get_value_from_env(mini->env_v, \
		"equals"), mini, "equals", getenv("equals"));
	update_exported_var(get_value_from_env(mini->env_v, \
		"SHLVL"), mini, "SHLVL", mini->shlvl);
	return ;
}
