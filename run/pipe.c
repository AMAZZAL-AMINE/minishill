/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:10:18 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/11 14:29:26 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void _pipe(t_parsing *shell, t_minishell   *mini, char *line) {
  int pipefd[2];
  int prev_pipefd[2] = {-1, -1};
  int count = 0;
  int size_cmd = ft_count_tokens(line) * 2;
  while (count <= size_cmd) {
    if (count % 2 == 0) {
      check_cmd_exist(&shell[count], mini);
      expand(&shell[count], mini);
      if (count + 1 <= size_cmd && (str_cmp(shell[count + 1].cmd, "|"))) {
        pipe(pipefd);
        if (prev_pipefd[0] != -1) {
          dup2(prev_pipefd[0], STDIN_FILENO);
          close(prev_pipefd[0]);
          close(prev_pipefd[1]);
        }
        if (shell[count].fd_out != -1) {
          dup2(shell[count].fd_out, STDOUT_FILENO);
          close(shell[count].fd_out);
        }
        if (shell[count].fd_in != -1) {
          dup2(shell[count].fd_in, STDIN_FILENO);
          close(shell[count].fd_in);
        }
        shell[count].fd_out = pipefd[1];
        shell[count + 1].fd_in = pipefd[0];
        execut(&shell[count], mini, 0);
        prev_pipefd[0] = pipefd[0];
        prev_pipefd[1] = pipefd[1];
      } else {
        if (prev_pipefd[0] != -1) {
          dup2(prev_pipefd[0], STDIN_FILENO);
          close(prev_pipefd[0]);
          close(prev_pipefd[1]);
        }
        if (shell[count].fd_out != -1) {
          dup2(shell[count].fd_out, STDOUT_FILENO);
          close(shell[count].fd_out);
        }
        if (shell[count].fd_in != -1) {
          dup2(shell[count].fd_in, STDIN_FILENO);
          close(shell[count].fd_in);
        }
        execut(&shell[count], mini, 0);
      }
    }
    count++;
  }
}
