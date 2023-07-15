/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:22:04 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/16 00:39:43 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void exit_shell(t_parsing *shell, t_minishell *minishell, int index, int size) {
  if ((index - 1 > 0 && str_cmp(minishell->parsing[index - 1].cmd, "|")) || (index + 1 <= size && str_cmp(minishell->parsing[index + 1].cmd, "|"))) {
    if (count_length_two_arr(shell->args) > 1) {
      captur.exit_status = 1;
      ft_putstr_fd("minishell: exit: too many arguments\n", 2);
      return ;
    }
    captur.exit_status = 0;
    return ;
  }
  ft_putstr_fd("exit\n", 1);
  if (count_length_two_arr(shell->args) > 1) {
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
