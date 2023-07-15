/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:04:47 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/15 15:48:07 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int is_it_bultin_or_not(t_minishell *shell, int count) {
   if ((str_cmp("echo", shell->parsing[count].cmd) || str_cmp("/bin/echo", shell->parsing[count].cmd))
      || (str_cmp("cd", shell->parsing[count].cmd) || str_cmp("/usr/bin/cd", shell->parsing[count].cmd))
      || (str_cmp("clear", shell->parsing[count].cmd))
      || (str_cmp("pwd", shell->parsing[count].cmd) || str_cmp("/bin/pwd", shell->parsing[count].cmd))
      || (str_cmp("exit", shell->parsing[count].cmd))
      || (str_cmp("env", shell->parsing[count].cmd))
      || (str_cmp("export", shell->parsing[count].cmd))
      || (str_cmp("unset", shell->parsing[count].cmd)))
        return (1);
      return (0);
}

void builtin(t_minishell *shell, char *line) {
  int count = 0;
  int size_cmd = ft_count_tokens(line) * 2;
  int is_betwwen_pipe = 0;
  while (count <= size_cmd) {
    if (count % 2 == 0) {
      if (handle_undfined_file(shell->parsing[count].args))
        break;
      // is_commande_var(&shell->parsing[count], shell, count);
      if (all_functions_errors(line, shell, &shell->parsing[count]))
        break;
      check_cmd_exist(&shell->parsing[count], shell);
      // expand(&shell->parsing[count], shell);
      if (is_it_bultin_or_not(shell, count))
      {
        if (count + 1 <= size_cmd && (str_cmp(shell->parsing[count + 1].cmd, "|"))) {
          if (count - 1 >= 0  && str_cmp(shell->parsing[count - 1].cmd, "|"))
            is_betwwen_pipe = 1;
          if (is_betwwen_pipe == 0)
            pipe(shell->pipefd);
          else
            pipe(shell->pipefd2);
          int pid = fork();
          if (pid == 0) {
            if (is_betwwen_pipe == 0) {
              close(shell->pipefd[0]);
              dup2(shell->pipefd[1], STDOUT_FILENO);
            }else {
              close(shell->pipefd[0]);
              dup2(shell->pipefd[1], STDOUT_FILENO);
              close(shell->pipefd[1]);
              close(shell->pipefd2[0]);
              dup2(shell->pipefd2[1], STDOUT_FILENO);
              close(shell->pipefd2[1]);
            }
            if (builtin_redirections(shell->parsing[count].args, &shell->parsing[count]) == 0) {
              run_buitins(shell, count, size_cmd);
              exit(0);
            }else 
              exit(1);
          }
          else {
            if (is_betwwen_pipe == 0) {
              close(shell->pipefd[1]);
              dup2(shell->pipefd[0], STDIN_FILENO);
              close(shell->pipefd[0]);
              wait(NULL);
            }else {
              close(shell->pipefd[1]);
              dup2(shell->pipefd[0], STDIN_FILENO);
              close(shell->pipefd[0]);
              close(shell->pipefd2[1]);
              dup2(shell->pipefd2[0], STDIN_FILENO);
              close(shell->pipefd2[0]);
              wait(NULL);
            }
          }
        }else {
          if (builtin_redirections(shell->parsing[count].args, &shell->parsing[count]) == 0) {
            run_buitins(shell, count, size_cmd);
          }
        }
      }
      else
      {
        if (ft_strlen(shell->parsing[count].cmd) > 0) {
          if (count + 1 <= size_cmd && (str_cmp(shell->parsing[count + 1].cmd, "|"))) {
            if (count - 1 >= 0  && str_cmp(shell->parsing[count - 1].cmd, "|")) {
                execut(&shell->parsing[count], shell, 2);
            }
            else {
              if (check_cmd_type(shell->parsing[count].cmd) == 0) {
                execut(&shell->parsing[count], shell, 1);
              }
            }
          }else {
            if (check_cmd_type(shell->parsing[count].cmd) == 0) {
              execut(&shell->parsing[count], shell, 0);
            }
          }
        }else {
          captur.exit_status = 0;
        }
      }
    }
    count++;
  }
  dup2(shell->_stdin,   STDIN_FILENO);
  dup2(shell->_stdout,  STDOUT_FILENO);
}
