/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:22:04 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/16 18:25:58 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int is_not_num(char *arg) {
  int count = 0;
  while (arg[count]) {
    if (!ft_isdigit(arg[count]) && (arg[count] != '-' && arg[count] != '+')) {
      return 1;
    }
    count++;
  }
  return 0;
}

void exit_shell(t_parsing *shell, t_minishell *minishell, int index, int size) {
  if ((index - 1 > 0 && str_cmp(minishell->parsing[index - 1].cmd, "|")) || (index + 1 <= size && str_cmp(minishell->parsing[index + 1].cmd, "|"))) {
    if (shell->args[0] && is_not_num(shell->args[0])) {
      captur.exit_status = 1;
      ft_putstr_fd("minishell: exit: ", 2);
      ft_putstr_fd(shell->args[0], 2);
      ft_putstr_fd(": numeric argument required\n", 2);
      return ;
    }else if (count_length_two_arr(shell->args) > 1) {
      captur.exit_status = 1;
      ft_putstr_fd("minishell: exit: too many arguments\n", 2);
      return ;
    }
    captur.exit_status = 0;
    return ;
  }
  ft_putstr_fd("exit\n", 1);
  if (shell->args[0] && is_not_num(shell->args[0])) {
    captur.exit_status = 1;
    ft_putstr_fd("minishell: exit: ", 2);
    ft_putstr_fd(shell->args[0], 2);
    ft_putstr_fd(": numeric argument required\n", 2);
    exit(255);
  }else if (count_length_two_arr(shell->args) > 1) {
    captur.exit_status = 1;
    ft_putstr_fd("minishell: exit: too many arguments\n", 2);
    return ;
  }
  if (!shell->args[0]) {
    exit(0);
  }
  captur.exit_status = 0;
  exit(ft_atoi(shell->args[0]));
}
