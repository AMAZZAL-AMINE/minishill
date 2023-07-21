/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utilis_part1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:58:36 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/21 20:23:01 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	open_child_between_pieps(t_minishell *mini, int is_between)
{
	if (is_between)
	{
		close(mini->pipefd[0]);
		dup2(mini->pipefd[1], STDOUT_FILENO);
		close(mini->pipefd[1]);
		close(mini->pipefd2[0]);
		dup2(mini->pipefd2[1], STDOUT_FILENO);
		close(mini->pipefd2[1]);
	}
	else
	{
		close(mini->pipefd[0]);
		dup2(mini->pipefd[1], STDOUT_FILENO);
		close(mini->pipefd[1]);
	}
}

void	close_child_between_pieps(t_minishell *mini, int is_between)
{
	if (is_between)
	{
		close(mini->pipefd[1]);
		dup2(mini->pipefd[0], STDIN_FILENO);
		close(mini->pipefd[0]);
		close(mini->pipefd2[1]);
		dup2(mini->pipefd2[0], STDIN_FILENO);
		close(mini->pipefd2[0]);
	}
	else
	{
		close(mini->pipefd[1]);
		dup2(mini->pipefd[0], STDIN_FILENO);
		close(mini->pipefd[0]);
	}
}
