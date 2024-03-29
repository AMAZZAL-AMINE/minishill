/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:02:51 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/30 21:41:45 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_env_value(char *what, t_minishell *shell)
{
	int		count;
	char	**content;

	count = 0;
	content = NULL;
	while (shell->n_var_env > count)
	{
		content = ft_strtok(shell->env_v[count], '=');
		if (str_cmp(content[0], what))
		{
			free_double(content);
			return (shell->env_v[count] + ft_strlen(what) + 1);
		}
		free_double(content);
		count++;
	}
	return (NULL);
}

char	*find_cmd_path(char *cmd, t_minishell *shell, t_parsing *s)
{
	int			count;
	char		*path;
	char		**paths;
	struct stat	state;

	count = 0;
	path = NULL;
	paths = ft_strtok(get_env_value("PATH", shell), ':');
	if (is_can_access(cmd, s))
	{
		captur.exit_status = 127;
		exit(127);
	}
	if (paths == NULL)
		return (cmd);
	while (paths[count])
	{
		path = ft_strjoin_tok(ft_strjoin_tok(paths[count], "/"), cmd);
		if (stat(path, &state) == 0)
			return (path);
		count++;
	}
	free_double(paths);
	return (cmd);
}
