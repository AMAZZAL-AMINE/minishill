/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   appned.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 22:56:25 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/27 18:51:17 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	no_file_or_dir(char *filename)
{
	captur.exit_status = 1;
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(filename, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
	return (1);
}

int	is_dir(char *filename)
{
	captur.exit_status = 1;
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(filename, 2);
	ft_putstr_fd(": is a directory\n", 2);
	return (1);
}

int	appned(char **content, int count)
{
	struct stat	file_stat;
	int			fd;

	stat(content[count + 1], &file_stat);
	if (S_ISDIR(file_stat.st_mode))
		return (is_dir(content[count + 1]));
	fd = open(content[count + 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (access(content[count + 1], F_OK) == -1)
		return (no_file_or_dir(content[count + 1]));
	if (access(content[count + 1], W_OK))
	{
		captur.exit_status = 1;
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(content[count + 1], 2);
		ft_putstr_fd(": Permission denied\n", 2);
		return (1);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
}
