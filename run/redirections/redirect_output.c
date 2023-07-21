/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 22:49:49 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/21 19:38:31 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	redirect_output(char **content, int count)
{
	struct stat	file_stat;
	int			fd;

	stat(content[count + 1], &file_stat);
	if (S_ISDIR(file_stat.st_mode))
	{
		captur.exit_status = 1;
		ft_putstr_fd("minishell : ", 2);
		ft_putstr_fd(content[count + 1], 2);
		ft_putstr_fd(": is a directory\n", 2);
		return (1);
	}
	fd = open(content[count + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (access(content[count + 1], F_OK) == -1)
		return (no_file_or_dir(content[count + 1]));
	if (access(content[count + 1], W_OK) == -1)
		return (no_permission(content[count + 1]));
	dup2(fd, STDOUT_FILENO);
	captur.exit_status = 0;
	close(fd);
	return (0);
}
