/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utilis_export_to_env.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 10:20:22 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/30 22:21:07 by mamazzal         ###   ########.fr       */
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
		spli = ft_strtok(shell->env_v[count], '=');
		if (str_cmp(name, spli[0]))
		{
			free_double(spli);
			return (1);
		}
		free_double(spli);
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
	char	*tmp;

	count = shell->n_var_env;
	if (ft_strchr(content, '=') != NULL)
	{
		tmp = ft_strjoin_tok(name, "=");
		shell->env_v[count] = ft_strjoin_tok(tmp, value);
		free(tmp);
	}
	else
		shell->env_v[count] = ft_strjoin_tok(name, "");
	shell->n_var_env += 1;
	free(name);
}

int	export_to_en(t_minishell *shell, char *name, char *value, char *content)
{
	if (export_not_valid_utilis(name))
	{
		free(name);
		return (1);
	}
	if (search_is_already_exported(name, shell))
	{
		update_exported_var(content, shell, name, value);
		free(name);
		return (0);
	}
	update_env_array_string(shell, name, value, content);
	return (0);
}
