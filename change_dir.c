/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:40:01 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/06 12:53:15 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int change_dir(t_cmd_table *table) {
  int pid = fork();
  if (!table->args[1]) {
    chdir(getenv("HOME"));
    wait(NULL);
  }else {
    if (chdir(table->args[1]) == -1) {
      printf("cd: no such file or directory: %s\n", table->args[1]);
      exit(127);
    }else {
      wait(NULL);
    }
  }

  waitpid(pid, NULL, 1);
  return 0;
}