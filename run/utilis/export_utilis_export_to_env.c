/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utilis_export_to_env.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 10:20:22 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/25 17:17:09 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	search_is_already_exported(char *name, t_minishell *shell)
{
	int		count;
	char	**spli;

	count = 0;
	while (count < shell->n_var_env)
	{
		//khasso itfriyaa spli
		spli = ft_split(shell->env_v[count], '=');
		if (str_cmp(name, spli[0]))
			return (1);
		count++;
	}
	return (0);
}

int	export_not_valid_utilis(char *name)
{
	if (exp_not_valid_identifier(name))
	{
		captur.exit_status = 1;
		return (1);
	}
	return (0);
}

void	update_env_array_string(t_minishell *shell, char *name, \
	char *value, char *content)
{
	int		count;
	char	**new_env;

	new_env = malloc(sizeof(char *) * (shell->n_var_env + 2));
	count = 0;
	while (count < shell->n_var_env)
	{
		new_env[count] = shell->env_v[count];
		count++;
	}
	if (ft_strchr(content, '=') != NULL)
		new_env[count] = ft_strjoin(ft_strjoin(name, "="), value);
	else
		new_env[count] = name;
	shell->n_var_env += 1;
	shell->env_v = new_env;
}

int	export_to_en(t_minishell *shell, char *name, char *value, char *content)
{
	if (export_not_valid_utilis(name))
		return (1);
	if (search_is_already_exported(name, shell))
	{
		update_exported_var(content, shell, name, value);
		return (0);
	}
	update_env_array_string(shell, name, value, content);
	return (0);
}
