/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 22:45:05 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/27 18:51:17 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	no_permission(char *filename)
{
	captur.exit_status = 1;
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(filename, 2);
	ft_putstr_fd(": Permission denied\n", 2);
	return (1);
}

int	redirect_input(char **content, int count)
{
	int	fd;

	if (access(content[count + 1], F_OK) == -1)
	{
		captur.exit_status = 1;
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(content[count + 1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		return (1);
	}
	fd = open(content[count + 1], O_RDONLY);
	if (access(content[count + 1], W_OK))
		return (no_permission(content[count + 1]));
	if (fd == -1)
	{
		captur.exit_status = 1;
		close(STDOUT_FILENO);
		ft_putstr_fd("minishell: error opening a file", 2);
		return (1);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (0);
}
