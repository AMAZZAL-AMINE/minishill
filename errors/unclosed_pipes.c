/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unclosed_pipes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:09:02 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/17 20:25:59 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int unclosed_pipe(t_minishell *mini) {
 int count = 0;
 if (str_cmp(mini->parsing[0].cmd, "|") || mini->parsing[0].cmd[0] == '|') {
  ft_putstr_fd("minishell: syntax error near unexpected token `|'\n", 2);
  captur.exit_status = 258;
  return 258;
 }else {
  while (count <= mini->n_cmd) {
    if (str_cmp(mini->parsing[count].cmd, "|") && (!ft_strlen(mini->parsing[count + 1].cmd) || str_cmp(mini->parsing[count + 1].cmd, "|"))) {
      ft_putstr_fd("minishell: syntax error near unexpected token `|'\n", 2);
      captur.exit_status = 258;
      return 258;
    }
    count++;
  }
 }
 return 0;
}

//echo hi |  "|"