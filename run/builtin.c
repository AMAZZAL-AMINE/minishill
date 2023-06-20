/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:04:47 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/20 16:45:45 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void builtin(t_minishell *shell, char *line) {
  int count = 0;
  int size_cmd = ft_count_tokens(line) * 2;
  while (count <= size_cmd) {
    if (count % 2 == 0) {
      if (str_cmp("echo", shell->parsing[count].cmd) || str_cmp("/bin/echo", shell->parsing[count].cmd)) {
        echo_cmd(&shell->parsing[count]);
      }else if (str_cmp("cd", shell->parsing[count].cmd) || str_cmp("/usr/bin/cd", shell->parsing[count].cmd)) {
        change_dir(&shell->parsing[count]);
      }else if (str_cmp("clear", shell->parsing[count].cmd)) {
        clear();
      }else if (str_cmp("pwd", shell->parsing[count].cmd) || str_cmp("/bin/pwd", shell->parsing[count].cmd)) {
        pwd(&shell->parsing[count]);
      }else if (str_cmp("exit", shell->parsing[count].cmd)) {
        exit_shell(&shell->parsing[count]);
      }else if (str_cmp("env", shell->parsing[count].cmd)) {
        get_env(shell->env, shell);
      }else if (str_cmp("export", shell->parsing[count].cmd)) {
        export(&shell->parsing[count], shell);
      }else if (str_cmp("unset", shell->parsing[count].cmd)) {
        unset(shell, &shell->parsing[count]);
      }else if (str_cmp("|", shell->parsing[count].cmd)) {
        pip_exec(&shell->parsing[count], shell);
      }else {
        execut(&shell->parsing[count], shell);
      }
    }
    count++;
  }
}