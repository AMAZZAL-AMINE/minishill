/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_can_access.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:01:40 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/19 19:28:30 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int _search(char *str, char obj) {
  int count = 0;
  while (str[count]) {
    if (str[count] == obj) {
      return 1;
    }
    count++;
  }
  return 0;
}

int is_can_access(char *arg, t_parsing *shell) {
  if (_search(arg, '/')) {
    if (access(arg, F_OK) == -1) {
      ft_putstr_fd("minishell: ", 2);
      ft_putstr_fd(shell->cmd, 2);
      ft_putstr_fd(": No such file or directory\n", 2);
      return 1;
    }
  }

  return 0;
}
