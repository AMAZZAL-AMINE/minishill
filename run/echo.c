/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:55:08 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/11 15:23:16 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void echo_in_console(char **content) {
  int count = 0;
  count = 0;
  while (content[count]) {
    if (str_cmp(content[count], "<<") || str_cmp(content[count], ">>")
      || str_cmp(content[count], "<") || str_cmp(content[count], ">")) {
      break;
    }
    if (count == 0) {
      while (content[count] && str_cmp("-n", content[count])) {
        count++;
      }
    }
    if (content[count]) {
      if (content[count + 1] != NULL) {
        write(1, ft_strjoin(content[count], " "), ft_strlen(content[count]) + 1);
      }else {
        write(1, content[count], ft_strlen(content[count]));
      }
    }else {
      break;
    }
    count++;
  }
  if (content[0] == NULL || !str_cmp("-n", content[0])) {
    write(1, "\n", 1);
  }
}

int echo_cmd(t_parsing *shell) {
  echo_in_console(shell->args);
  captur.exit_status = 0;
  return 0;
}
