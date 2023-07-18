/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execut.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 07:40:31 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/18 22:47:55 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int length_cmd(char *cmd) {
  int count = ft_strlen(cmd) - 1;
  while (count >= 0 && cmd[count] != '/') {
    count--;
  }
  return count + 1;
}

void run_simple_commande(int is_path, t_parsing *shell, char **content, t_minishell *mini) {
  if (is_cmd_redirected(shell->cmd)) {
    captur.exit_status = 0;
    exit(0);
  }
  if (is_path == 1) {
    if (execve(shell->cmd, join_two_dim_arr(shell->cmd + ft_strlen("/bin/"), content), mini->env_v) == -1)
      cmd_not_found(shell->cmd, mini);
  }else  {
    if (execve(find_cmd_path(shell->cmd, mini, shell), join_two_dim_arr(shell->cmd, content), mini->env_v))
      cmd_not_found(shell->cmd, mini);
  }
}

void execut(t_parsing *shell, t_minishell *mini, int ispipe) {
  int status;
  if (search_for_heardoc(shell->args))
    herdoc(shell->args, mini);
  if (ispipe == 1) {
    pipe(mini->pipefd);
  }else if (ispipe == 2) {
    pipe(mini->pipefd2);
  }
  
  int pid = fork();
  if (pid == 0) {
    if(ispipe == 1) {
      close(mini->pipefd[0]);
      dup2(mini->pipefd[1], STDOUT_FILENO);
      close(mini->pipefd[1]);
    }else if (ispipe == 2) {
      close(mini->pipefd[0]);
      dup2(mini->pipefd[1], STDOUT_FILENO);
      close(mini->pipefd[1]);
      close(mini->pipefd2[0]);
      dup2(mini->pipefd2[1], STDOUT_FILENO);
      close(mini->pipefd2[1]);
    }
    int check = 0;
    if (is_redirec_output(shell->args) == 1) {
      check = 1;
      if (redirect(1, shell, shell->args) != 0)
        exit(1);
    }
    if (check == 1 && ft_strlen(shell->cmd) == 0)
      exit(0);
    int size_new_vars = count_length_two_arr(shell->args);
    char **new_arg = malloc(sizeof(char *) * (size_new_vars + 1));
    shell->args = get_new_arg(new_arg, shell->args, size_new_vars, mini);
    if (str_cmp(find_cmd_path(shell->cmd + length_cmd(shell->cmd), mini, shell), shell->cmd)) {
      run_simple_commande(1, shell, shell->args, mini);
    }else {
      run_simple_commande(0, shell, shell->args, mini);
    }
  }else {
    if (ispipe == 1) {
      close(mini->pipefd[1]);
      dup2(mini->pipefd[0], STDIN_FILENO);
      close(mini->pipefd[0]);
    }
    else if (ispipe == 2) {
      close(mini->pipefd[1]);
      dup2(mini->pipefd[0], STDIN_FILENO);
      close(mini->pipefd[0]);
      close(mini->pipefd2[1]);
      dup2(mini->pipefd2[0], STDIN_FILENO);
      close(mini->pipefd2[0]);
    }
    if (!ispipe)
      waitpid(pid, &status, 0);
    else 
      waitpid(pid, &status, WNOHANG);
    captur.exit_status = status / 256;
  }
}
