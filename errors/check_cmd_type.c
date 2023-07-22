/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:50:12 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/21 11:52:51 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_is_file(char *cmd)
{
	if (cmd[1] && ((cmd[0] == '.' && cmd[1] == '/') || cmd[0] == '/'))
		return (1);
	return (0);
}

int	run_file(char *cmd)
{
	struct stat	file_stat;

	stat(cmd, &file_stat);
	if (S_ISDIR(file_stat.st_mode))
	{
		captur.exit_status = 126;
		ft_putstr_fd("minishell : ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": is a directory\n", 2);
		return (126);
	}
	if (access(cmd, F_OK) == -1)
	{
		captur.exit_status = 127;
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		return (127);
	}

	if (access(cmd, X_OK))
	{
		captur.exit_status = 126;
		ft_putstr_fd("minishell : ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": Permission denied\n", 2);
		return (126);
	}

	return (0);
}

int	check_cmd_type(char *cmd)
{
	if (check_is_file(cmd))
	{
		if (run_file(cmd) != 0)
			return (127);
	}
	return (0);
}
