/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:04:47 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/17 14:20:34 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdlib.h>
void builtin(t_minishell *shell, char *line) {
  int count = 0;
  int size_cmd = ft_count_tokens(line) * 2;
  while (count <= size_cmd) {
    if (count % 2 == 0) {
      if (!ft_strncmp("echo", shell->parsing[count].cmd, ft_strlen(shell->parsing[count].cmd)) ||
        !ft_strncmp("/bin/echo", shell->parsing[count].cmd, ft_strlen(shell->parsing[count].cmd))) {
        echo_cmd(&shell->parsing[count]);
      }else if (ft_strncmp("clear", shell->parsing[count].cmd, ft_strlen(shell->parsing[count].cmd)) == 0) {
        clear();
      }else {
        execut(&shell->parsing[count]);
      }
    }
    count++;
  }
}