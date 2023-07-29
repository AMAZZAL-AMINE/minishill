/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:29:23 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/30 00:38:21 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_env_oldpwd(char **conten)
{
	int	count;

	count = 0;
	while (conten[count])
	{
		if (ft_strnstr(conten[count], "OLDPWD", ft_strlen("OLDPWD")) != NULL)
			return (conten[count]);
		count++;
	}
	return (NULL);
}

int	update_oldpwd(t_parsing __unused *shell, t_minishell *mini)
{
	char	*tmp;
	char	*oldpwd;

	tmp = getcwd(NULL, 0);
	oldpwd = get_env_oldpwd(mini->env_v);
	update_exported_var(oldpwd, \
		mini, "OLDPWD", tmp);
	free(tmp);
	return (0);
}

int	is_redirec(char *args)
{
	if (str_cmp(args, ">") || str_cmp(args, ">>") \
		|| str_cmp(args, "<") || str_cmp(args, "<<"))
		return (1);
	return (0);
}

void	change_dir(t_parsing *shell, t_minishell *minishell, \
	int index, int size)
{
	char	*home;

	if ((index - 1 > 0 && str_cmp(minishell->parsing[index - 1].cmd, "|")) \
		|| (index + 1 <= size \
		&& str_cmp(minishell->parsing[index + 1].cmd, "|")))
		return (cd_between_pipe_cd_status());
	if (shell->args[0] && !is_redirec_output(&shell->args[0]))
	{
		if (check_the_dir_name(shell->args[0]) != 0)
			return ;
		update_oldpwd(shell, minishell);
		if (chdir(shell->args[0]) == -1)
			return (cd_err(shell->args[0]));
	}
	else if (shell->args[0] == NULL || is_redirec_output(&shell->args[0]))
	{
		home = get_env_value("HOME", minishell);
		if (home == NULL)
			return (home_not_set());
		if (chdir(home) == -1)
			return (cd_err(home));
	}
	captur.exit_status = 0;
}
