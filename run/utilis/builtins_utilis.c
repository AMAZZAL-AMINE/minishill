/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utilis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 19:10:02 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/21 19:11:37 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	run_pipe_in_child(t_minishell *shell, int betwn_pipes)
{
	if (betwn_pipes)
	{
		close(shell->pipefd[0]);
		dup2(shell->pipefd[1], STDOUT_FILENO);
		close(shell->pipefd[1]);
		close(shell->pipefd2[0]);
		dup2(shell->pipefd2[1], STDOUT_FILENO);
		close(shell->pipefd2[1]);
	}
	else
	{
		close(shell->pipefd[0]);
		dup2(shell->pipefd[1], STDOUT_FILENO);
	}
}

void	close_pipe_in_child(t_minishell *shell, int betwn_pipes)
{
	if (betwn_pipes)
	{
		close(shell->pipefd[1]);
		dup2(shell->pipefd[0], STDIN_FILENO);
		close(shell->pipefd[0]);
		close(shell->pipefd2[1]);
		dup2(shell->pipefd2[0], STDIN_FILENO);
		close(shell->pipefd2[0]);
		wait(NULL);
	}
	else
	{
		close(shell->pipefd[1]);
		dup2(shell->pipefd[0], STDIN_FILENO);
		close(shell->pipefd[0]);
		wait(NULL);
	}
}

void	close_pipes(int is_betwwen_pipe, t_minishell *shell)
{
	if (is_betwwen_pipe == 0)
		close_pipe_in_child(shell, 0);
	else
		close_pipe_in_child(shell, 1);
}
