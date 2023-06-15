/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execut.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 07:40:31 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/15 14:47:51 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int is_redirec_output(char **args) {
  int count = 0;
  int is_redirec = 0;
  while (args[count]) {
    if (args[count][0] == '>' && args[count][1] == 0) {
      is_redirec = 1;
    }
    count++;
  }
  return is_redirec;
}

int find_file_after_redir(char **args) {
  int count = 0;
  while (args[count]) {
    if (args[count][0] == '>' && args[count][1] == 0) {
      return (count + 1);
    }
    count++;
  }
  return count;
}

char **get_only_what_ineed_in_arr(char **args) {
  int count = 0;
  char **dst = malloc(sizeof(char *) * (find_file_after_redir(args)));
  while (count < (find_file_after_redir(args) - 1)) {
    dst[count] = ft_strdup(args[count]);
    count++;
  }
  dst[count] = NULL;
  return dst;
}

char **new_content(char **content) {
  int count = 0;
  int index = 0;
  while (content[index][0] != '>') {
    index++;
  }
  char **dst = malloc(sizeof(char *) * (index + 1));
  while (count < index) {
    dst[count] = ft_strdup(content[count]);
    count++;
  }
  dst[count] = NULL;
  return dst;
}

void execut(t_parsing *shell) {
  int pid = fork();
  if (pid == 0) {
    int count = 0;
    char **content = shell->args;
    while (content[count]) {
      content[count] = remove_quots(content[count]);
      count++;
    }
    if (!ft_strncmp("/bin/", shell->cmd, ft_strlen("/bin/"))) {
      if (is_redirec_output(shell->args) == 1) {
        int fd = open(shell->args[find_file_after_redir(shell->args)], O_WRONLY | O_CREAT | O_TRUNC, 0644);
        dup2(fd, 1);
        if (execve(shell->cmd, join_two_dim_arr(shell->cmd + ft_strlen("/bin/"), new_content(content)), NULL) == -1) {
            printf("minishell: %s: command not found\n", shell->cmd);
            exit(127);
        }
      }else {
        if (execve(shell->cmd, join_two_dim_arr(shell->cmd + ft_strlen("/bin/"), content), NULL) == -1) {
            printf("minishell: %s: command not found\n", shell->cmd);
            exit(127);
        }
      }
    }else {
      if (is_redirec_output(shell->args) == 1) { 
        int fd = open(shell->args[find_file_after_redir(shell->args)], O_WRONLY | O_CREAT | O_TRUNC, 0644);
        dup2(fd, 1);
        if (execve(ft_strjoin("/bin/", shell->cmd),join_two_dim_arr(shell->cmd, new_content(content)), NULL) == -1) {
            printf("minishell: %s: command not found\n", shell->cmd);
            exit(127);
        }
      }else {
        if (execve(ft_strjoin("/bin/", shell->cmd),join_two_dim_arr(shell->cmd, content), NULL)) {
          printf("minishell: %s: command not found\n", shell->cmd);
          exit(127);
        }
      }
    }
    wait(NULL);
  }
  waitpid(pid, NULL, 0);
  return;
}
