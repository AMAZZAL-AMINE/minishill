/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_the_dir_name.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 11:30:09 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/21 11:28:47 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_the_dir_name(char *dir_name)
{
	struct stat	file_stat;

	stat(dir_name, &file_stat);
	if (S_ISDIR(file_stat.st_mode))
	{
		captur.exit_status = 0;
		return (0);
	}
	if (access(dir_name, F_OK) == -1)
	{
		captur.exit_status = 1;
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(dir_name, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		return (1);
	}
	if (S_ISREG(file_stat.st_mode))
	{
		captur.exit_status = 1;
		ft_putstr_fd("minishell: cd", 2);
		ft_putstr_fd(dir_name, 2);
		ft_putstr_fd(": Not a directory\n", 2);
		return (1);
	}
	return (0);
}
