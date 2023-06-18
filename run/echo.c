/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:55:08 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/18 17:27:06 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void echo_redirect_to_file(char **content, char *file, int index) {
  (void) content;
  (void)file;
  (void)index;
  return;
}

void echo_in_console(char **content, char *cmd) {
  int chld_pid = fork();
  if (chld_pid == 0) {
    int count = 0;
    while (content[count]) {  
      content[count] = remove_quots(content[count]);
      count++;
    }
    if (execve("/bin/echo", join_two_dim_arr(cmd, content), NULL) == -1) {
      printf("shell: %s: command not found\n", cmd);
      exit(127);
    }
    wait(NULL);
  }
  waitpid(chld_pid, NULL, 0);
  return;
}

int echo_cmd(t_parsing *shill) {
  int count = 0;
  while (shill->args[count]) {
    if (ft_strncmp(">", shill->args[count], ft_strlen(">")) == 0) {
      shill->is_re_to_file = 1;
      break;
    }
    count++;
  }
  if (shill->is_re_to_file == 1) {
    echo_redirect_to_file(shill->args, shill->args[count + 1], count);
  }else {
    echo_in_console(shill->args, shill->cmd);
  }
  return 0;
}