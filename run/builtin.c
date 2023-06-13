/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:04:47 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/13 19:11:02 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void builtin(t_minishell *shell, char *line) {
  int count = 0;
  int size_cmd = ft_count_tokens(line) * 2;
  while (count <= size_cmd) {
    if (count % 2 == 0) {
      if (ft_strncmp("echo", shell->parsing[count].cmd, ft_strlen("echo")) == 0) {
        echo_cmd(&shell->parsing[count]);
      }
    }

    count++;
  }
}