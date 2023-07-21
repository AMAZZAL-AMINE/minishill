/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utilis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:23:29 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/21 20:22:52 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	home_not_set(void)
{
	ft_putstr_fd("minishell: cd: ", 2);
	ft_putstr_fd("HOME not set\n", 2);
	captur.exit_status = 1;
	return ;
}

void	cd_err(char *dir)
{
	captur.exit_status = 1;
	ft_putstr_fd("minishell: cd: ", 2);
	ft_putstr_fd(dir, 2);
	ft_putstr_fd("/: Permission denied\n", 2);
	return ;
}

void	cd_between_pipe_cd_status(void)
{
	captur.exit_status = 0;
}
