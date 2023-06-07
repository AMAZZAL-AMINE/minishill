/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_in_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:35:30 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/07 10:09:30 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int is_redirect_output(t_cmd_table *table) {
  int count = 0;
  while (table->args[count]) {
    if (table->args[count][0] == '>') {
        return 1;
    }
    count++;
  }
  return 0;
}

int posi_file_nm(t_cmd_table *table) {
  int count = 0;
  while (table->args[count]) {
    if (table->args[count][0] == '>') {
      return count + 1;
    }
    count++;
  }
  return 0;
}

int cmd_echo(t_cmd_table *table) {
  int count = 1;
  if (is_redirect_output(table) == 1) {
      int fd = open(table->args[posi_file_nm(table)], O_CREAT | O_WRONLY | O_TRUNC, 0644);
      if (fd > 2) {
        while (table->args[count] && table->args[count][0] != '>') {
          write(fd, &table->args[count], ft_strlen(table->args[count]));
          count++;
        }
    }
  }else {
    run_cmd(table);
  }
  return 0;
}

