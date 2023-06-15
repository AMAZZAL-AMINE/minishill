/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execut.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 07:40:31 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/15 21:18:16 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void run_simple_commande(int is_path, t_parsing *shell, char **content) {
  if (is_path == 1) {
    if (execve(shell->cmd, join_two_dim_arr(shell->cmd + ft_strlen("/bin/"), content), NULL) == -1) {
      printf("minishell: %s: command not found\n", shell->cmd);
      exit(127);
    }
  }else  {
    if (execve(ft_strjoin("/bin/", shell->cmd),join_two_dim_arr(shell->cmd, content), NULL)) {
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
    if (!ft_strncmp("/bin/", shell->cmd, ft_strlen("/bin/"))) {
      if (is_redirec_output(shell->args) == 1) {
        redirect_output(1, shell, content);
      }else {
        run_simple_commande(1, shell, content);
      }
    }else {
      if (is_redirec_output(shell->args) == 1) { 
       redirect_output(0, shell, content);
      }else {
        run_simple_commande(0, shell, content); 
      }
    }
    wait(NULL);
  }
  waitpid(pid, NULL, 0);
  return;
}
