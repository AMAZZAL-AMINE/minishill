/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:55:08 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/21 22:00:45 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void echo_in_console(char **content) {
  int count = 0;
  builtin_redirections(content, NULL);
  while (content[count]) {
    if (str_cmp(content[count], "<<") || str_cmp(content[count], ">>")
      || str_cmp(content[count], "<") || str_cmp(content[count], ">")) {
      break;
    }
    write(1, ft_strjoin(content[count], " "), ft_strlen(content[count]) + 1);
    count++;
  }
  printf("\n");
  exit(0);
}

int echo_cmd(t_parsing *shell) {
  int chld_pid = fork();
  if (chld_pid == 0) {
    if (search_for_heardoc(shell->args))
      herdoc(shell->args);
    echo_in_console(shell->args);
  }
  waitpid(chld_pid, NULL, 0);
  return 0;
}