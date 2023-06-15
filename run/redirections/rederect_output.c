/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rederect_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 21:03:03 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/15 21:21:04 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void redirect_output(int is_path, t_parsing *shell, char **content) {
  if (is_path == 1) {
    int fd = open(shell->args[find_file_after_redir(shell->args, '>')], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    dup2(fd, 1);
    if (execve(shell->cmd, join_two_dim_arr(shell->cmd + ft_strlen("/bin/"), new_content(content)), NULL) == -1) {
      printf("minishell: %s: command not found\n", shell->cmd);
      exit(127);
    }
  }else {
    int fd = open(shell->args[find_file_after_redir(shell->args, '>')], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    dup2(fd, 1);
    if (execve(ft_strjoin("/bin/", shell->cmd),join_two_dim_arr(shell->cmd, new_content(content)), NULL) == -1) {
        printf("minishell: %s: command not found\n", shell->cmd);
        exit(127);
    }
  }
}