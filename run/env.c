/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:41:41 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/25 16:43:36 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_env(char *env)
{
	int count = 0;
	while(env[count])
	{
		if (env[count] == '=') {
			return 1;
		}	
		count++;
	}
	return 0;
}

void	get_env(t_env __unused *env, t_minishell *minishell, char **content)
{
	int		count;

	count = 0;
	if (search_for_heardoc(content))
		herdoc(content, minishell);
	if (content[0])
	{
		printf("env: %s: No such file or directory\n", \
			content[0]);
		captur.exit_status = 127;
		return ;
	}
	while (minishell->env_v[count])
	{
		if (check_env(minishell->env_v[count]))
			printf("%s\n", minishell->env_v[count]);
		count++;
	}
	captur.exit_status = 0;
}
