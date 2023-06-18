/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execut.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 07:40:31 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/18 16:00:17 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int length_cmd(char *cmd) {
  int count = ft_strlen(cmd) - 1;
  while (count != 0 && cmd[count] != '/') {
    count--;
  }
  return count;
}

void run_simple_commande(int is_path, t_parsing *shell, char **content) {
  if (is_path == 1) {
    if (execve(shell->cmd, join_two_dim_arr(shell->cmd + ft_strlen("/bin/"), content), NULL) == -1) {
      printf("minishell: %s: command not found\n", shell->cmd);
      exit(127);
    }
  }else  {
    if (execve(find_cmd_path(shell->cmd), join_two_dim_arr(shell->cmd, content), NULL)) {
      printf("minishell: %s: command not found\n", shell->cmd);
      exit(127);
    }
  }
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
    if (str_cmp(find_cmd_path(shell->cmd + length_cmd(shell->cmd)), shell->cmd)) {
      if (is_redirec_output(shell->args) == 1) {
        redirect(1, shell, content);
      }else {
        run_simple_commande(1, shell, content);
      }
    }else {
      if (is_redirec_output(shell->args) == 1) {
       redirect(0, shell, content);
      }else {
        run_simple_commande(0, shell, content); 
      }
    }
    wait(NULL);
  }
  waitpid(pid, NULL, 0);
  return;
}
