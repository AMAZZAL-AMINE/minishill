/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_segnal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 22:13:34 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/30 22:14:39 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	heredoc_segnal(int sig)
{
	captur.is_press_ctrl_c = 0;
	if (sig == SIGINT)
	{
		printf("\n");
		exit(0);
	}
}

int	is_eof_in_quot_fun(char *arg)
{
	int	count;

	count = 0;
	while (arg[count])
	{
		if (arg[count] == '\'')
			return (1);
		else if (arg[count] == '\"')
			return (1);
		count++;
	}
	return (0);
}
