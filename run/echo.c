/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:55:08 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/20 17:08:32 by mamazzal         ###   ########.fr       */
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
  if (execve("/bin/echo", join_two_dim_arr(cmd, content), NULL) == -1) {
    printf("shell: %s: command not found\n", cmd);
    exit(127);
  }
  return;
}

int echo_cmd(t_parsing *shill) {
  int chld_pid = fork();
  if (chld_pid == 0) {
    echo_in_console(shill->args, shill->cmd);
  }
  waitpid(chld_pid, NULL, 0);
  return 0;
}