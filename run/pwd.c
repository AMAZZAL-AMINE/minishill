/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 11:01:26 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/21 11:19:37 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	pwd(t_parsing __unused *shell)
{
	char	*buff;

	buff = getcwd(NULL, 0);
	if (buff == NULL)
	{
		printf("PWD: error");
		exit(2);
	}
	ft_putstr_fd(buff, 1);
	ft_putchar_fd('\n', 1);
	captur.exit_status = 0;
	free(buff);
}
