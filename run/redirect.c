/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 21:03:03 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/17 13:41:41 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void redirect(int is_path, t_parsing *shell, char **content) {
  int last_fd_readed = 0;
  if (is_path == 1) {
    int fd = 0;
    int fd2 = 0;
    if (shell->n_in_files >= 1 || shell->n_out_files >= 1) {
      int count = 0;
      while (content[count]) {
        if (str_cmp(">", content[count])) {
          fd = open(content[count + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
          if (fd  < 0) {
            dup2(2, 1);
            printf("minishell: %s: No such file or directory\n", content[count + 1]);
            last_fd_readed = 1;
            exit(127);
          }
          dup2(fd, 1);
          last_fd_readed = 1;
        }
        if (str_cmp("<", content[count])) {
          fd2 = open(content[count + 1], O_RDONLY);
          if (fd2  < 0) {
            dup2(2, 1);
            printf("minishell: %s: No such file or directory\n", content[count + 1]);
            last_fd_readed = 1;
            exit(127);
          }
          dup2(fd2, 0);
          last_fd_readed = 0;
        }
        if (str_cmp(">>", content[count])) {
          fd = open(content[count + 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
          if (fd  < 0) {
            dup2(2, 1);
            printf("minishell: %s: No such file or directory\n", content[count + 1]);
            last_fd_readed = 1;
            exit(127);
          }
          dup2(fd, 1);
          last_fd_readed = 2;
        }
        count++;
      }
    }
    // if (last_fd_readed == 0)
    //   dup2(fd2, 0);
    // else if (last_fd_readed == 1)
    //   dup2(fd, 1);
    if (execve(shell->cmd, join_two_dim_arr(shell->cmd + ft_strlen("/bin/"), new_content(content)), NULL) == -1) {
      printf("minishell: %s: command not found\n", shell->cmd);
      exit(127);
    }
  }else {
    int fd = 0;
    int fd2 = 0;
 
    if (shell->n_out_files >= 1 || shell->n_in_files >= 1) {
      int count = 0;
      while (content[count]) {
        if (str_cmp(">", content[count])) {
          fd = open(content[count + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
          if (fd  < 0) {
            dup2(2, 1);
            printf("minishell: %s: No such file or directory\n", content[count + 1]);
            last_fd_readed = 1;
            exit(127);
          }
          dup2(fd, 1);
          last_fd_readed = 1;
        }
        if (str_cmp("<", content[count])) {
          fd2 = open(content[count + 1], O_RDONLY);
          if (fd2  < 0) {
            dup2(2, 1);
            printf("minishell: %s: No such file or directory\n", content[count + 1]);
            last_fd_readed = 1;
            exit(127);
          }
          dup2(fd2, 0);
          last_fd_readed = 0;
        }
        if (str_cmp(">>", content[count])) {
          fd = open(content[count + 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
          if (fd  < 0) {
            dup2(2, 1);
            printf("minishell: %s: No such file or directory\n", content[count + 1]);
            last_fd_readed = 1;
            exit(127);
          }
          dup2(fd, 1);
          last_fd_readed = 2;
        }
        count++;
      }
    }
    // if (last_fd_readed == 0)
    //   dup2(fd2, 0);
    // else if (last_fd_readed == 1)
    //   dup2(fd, 1);
    if (execve(ft_strjoin("/bin/", shell->cmd), join_two_dim_arr(shell->cmd, new_content(content)), NULL) == -1) {
      printf("minishell: %s: command not found\n", shell->cmd);
      exit(127);
    }
  }
}
