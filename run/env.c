/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:41:41 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/21 16:47:41 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	get_env(t_env *env, t_minishell *minishell, char **content)
{
	int		count;
	char	*env_val;

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
	while (count < minishell->n_var_env)
	{
		if (env[count].is_haver_equal == 1)
		{
			env_val = env[count].value;
			printf("%s=%s\n", env[count].name, env_val);
		}
		count++;
	}
	captur.exit_status = 0;
}
