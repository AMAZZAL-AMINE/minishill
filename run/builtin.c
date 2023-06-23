/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:04:47 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/23 20:01:58 by mamazzal         ###   ########.fr       */
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
  while (count <= size_cmd) {
    if (count % 2 == 0) {
      if (is_it_bultin_or_not(shell, count))
      {
        shell->_stdin = dup(STDIN_FILENO);
        shell->_stdout = dup(STDOUT_FILENO);
        builtin_redirections(shell->parsing[count].args, &shell->parsing[count]);
        run_buitins(shell, count);
        dup2(shell->_stdin, STDIN_FILENO);
        dup2(shell->_stdout, STDOUT_FILENO);
      }
      else
        execut(&shell->parsing[count], shell);
    }
    count++;
  }
}
