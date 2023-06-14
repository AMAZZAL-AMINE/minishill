/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 07:40:31 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/14 20:12:26 by mamazzal         ###   ########.fr       */
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

void ls(t_parsing *shell) {
  int pid = fork();
  if (pid == 0) {
    int count = 0;
    char **content = shell->args;
    if (is_redirec_output(shell->args) == 1) {
      int fd = open(shell->args[find_file_after_redir(shell->args)], O_CREAT | O_WRONLY | O_TRUNC, 0777);
    
      fork();
      if (execve("/bin/ls", join_two_dim_arr(shell->cmd, get_only_what_ineed_in_arr(shell->args)), NULL) == -1) {
        printf("minishell: %s: command not found\n", shell->cmd);
        exit(127);
      }
      int out_p = dup(1);
      dup2(fd, out_p);
      close(fd);
    }else {      
      while (shell->args[count]) {
        content[count] = ft_strdup(remove_quots(shell->args[count]));
        count++;
      }
      if (execve("/bin/ls", join_two_dim_arr(shell->cmd, content), NULL) == -1) {
        printf("minishell: %s: command not found\n", shell->cmd);
        exit(127);
      }
    }
    wait(NULL);
  }
  waitpid(pid, NULL, 0);
  return;
}
