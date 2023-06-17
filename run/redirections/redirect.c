/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 21:03:03 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/17 23:49:27 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void redirect(int is_path, t_parsing *shell, char **content) {
  if (is_path == 1) {
    int last_fd_readed = 0;
    int fd = 0;
    int fd2 = 0;
    if (shell->n_in_files >= 1 || shell->n_out_files >= 1) {
      int count = 0;
      while (content[count]) {
        if (str_cmp(">", content[count]))
          redirect_output(&fd, content, count, &last_fd_readed);
        if (str_cmp("<", content[count]))
          redirect_input(&fd2, content, count, &last_fd_readed);
        if (str_cmp(">>", content[count]))
         appned(&fd, content, count, &last_fd_readed);
        if (str_cmp("<<", content[count]))
         herdoc(&fd, &fd2, content, count, &last_fd_readed);
        count++;
      }
    }
    if (last_fd_readed == 0)
      dup2(fd2, 0);
    else if (last_fd_readed == 1)
      dup2(fd, 1);
    else if (last_fd_readed == 2)
      dup2(fd, 1);
    if (execve(shell->cmd, join_two_dim_arr(shell->cmd + ft_strlen("/bin/"), new_content(content)), NULL) == -1) {
      printf("minishell: %s: command not found\n", shell->cmd);
      exit(127);
    }
  }else {
    int last_fd_readed = 0;
    int fd = 0;
    int fd2 = 0;
    if (shell->n_in_files >= 1 || shell->n_out_files >= 1) {
      int count = 0;
      while (content[count]) {
        if (str_cmp(">", content[count]))
          redirect_output(&fd, content, count, &last_fd_readed);
        if (str_cmp("<", content[count]))
          redirect_input(&fd2, content, count, &last_fd_readed);
        if (str_cmp(">>", content[count]))
         appned(&fd, content, count, &last_fd_readed);
        if (str_cmp("<<", content[count]))
         herdoc(&fd, &fd2, content, count, &last_fd_readed);
        count++;
      }
    }
    if (last_fd_readed == 0)
      dup2(fd2, 0);
    else if (last_fd_readed == 1)
      dup2(fd, 1);
    else if (last_fd_readed == 2)
      dup2(fd, 1);
    if (execve(ft_strjoin("/bin/", shell->cmd), join_two_dim_arr(shell->cmd, new_content(content)), NULL) == -1) {
      printf("minishell: %s: command not found\n", shell->cmd);
      exit(127);
    }
  }
}
