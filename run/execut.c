/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execut.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 07:40:31 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/06 16:22:28 by mamazzal         ###   ########.fr       */
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

void run_simple_commande(int is_path, t_parsing *shell, char **content, t_minishell *mini) {
  if (is_cmd_redirected(shell->cmd)) {
    mini->caputre_exit_status = 0;
    exit(0);
  }
  if (is_path == 1) {
    if (execve(shell->cmd, join_two_dim_arr(shell->cmd + ft_strlen("/bin/"), new_content(content)), NULL) == -1) {
      printf("minishell: %s: command not found\n", shell->cmd);
      mini->caputre_exit_status = 127;
      exit(mini->caputre_exit_status);
    }
  }else  {
    if (execve(find_cmd_path(shell->cmd, mini), join_two_dim_arr(shell->cmd, new_content(content)), NULL)) {
      printf("minishell: %s: command not found\n", shell->cmd);
      mini->caputre_exit_status = 127;
      exit(mini->caputre_exit_status);
    }
  }
}

void execut(t_parsing *shell, t_minishell *mini) {
  int status;
  int pid = fork();
  
  if (pid == 0) {
    char **content = shell->args;
    if (str_cmp(find_cmd_path(shell->cmd + length_cmd(shell->cmd), mini), shell->cmd)) {
      if (is_redirec_output(shell->args) == 1)
        redirect(1, shell, content);
      run_simple_commande(1, shell, content, mini);
    }else {
      if (is_redirec_output(shell->args) == 1)
        redirect(0, shell, content);
      run_simple_commande(0, shell, content, mini); 
    }
  }
  waitpid(pid, &status, 0);
  mini->caputre_exit_status = status / 256;
  return;
}
