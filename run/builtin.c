/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:04:47 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/17 19:55:57 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdlib.h>
void builtin(t_minishell *shell, char *line) {
  int count = 0;
  int size_cmd = ft_count_tokens(line) * 2;
  while (count <= size_cmd) {
    if (count % 2 == 0) {
      if (str_cmp("echo", shell->parsing[count].cmd) || str_cmp("/bin/echo", shell->parsing[count].cmd)) {
        echo_cmd(&shell->parsing[count]);
      }else if (str_cmp("clear", shell->parsing[count].cmd)) {
        clear();
      }else if (str_cmp("|", shell->parsing[count].cmd)) {
        pip_exec(&shell->parsing[count], shell);
      }else {
        execut(&shell->parsing[count]);
      }
    }
    count++;
  }
}