/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_func_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:08:35 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/12 11:31:53 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int all_functions_errors(char *line, t_minishell *ms, t_parsing *shell) {
  if (single_quots_arr(line) || cmd_is_only_dolar(shell->cmd)) {
    if (cmd_is_only_dolar(shell->cmd)) {
        ft_putstr_fd("minishell: ", 2);
        ft_putstr_fd(shell->cmd, 2);
        ft_putstr_fd(": command not found\n", 2);
        captur.exit_status = 127;
    }
    return 1;
  }
  (void)ms;
  (void)shell;
  return 0;
}
