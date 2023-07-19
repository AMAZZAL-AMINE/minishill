/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unclosed_pipes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:09:02 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/19 21:26:55 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int unclosed_pipe(t_minishell *mini) {
 int count = 0;
 
  
 if (mini->n_cmd >= 1 &&  (str_cmp(mini->parsing[0].cmd, "|") || mini->parsing[0].cmd[0] == '|')) {
  ft_putstr_fd("minishell: syntax error near unexpected token `|'\n", 2);
  captur.exit_status = 258;
  return 258;
 }else if (mini->n_cmd >= 1 && mini->parsing[1].cmd && ft_strlen(mini->parsing[0].cmd) == 0 && str_cmp(mini->parsing[1].cmd, "|")) {
    if (mini->parsing[0].is_cmd_in_quotes || mini->parsing[0].is_cmd_var || (is_redirec_output(mini->parsing[0].args))) {
      return 0;
    }
    ft_putstr_fd("minishell: syntax error near unexpected token `|'\n", 2);
    captur.exit_status = 258;
    return 258;
 }else {
  while (count <= mini->n_cmd) {
    if (str_cmp(mini->parsing[count].cmd, "|") && (!ft_strlen(mini->parsing[count + 1].cmd) || str_cmp(mini->parsing[count + 1].cmd, "|"))) {
      if (mini->parsing[count + 1].is_cmd_in_quotes || mini->parsing[count + 1].is_cmd_var || (is_redirec_output(mini->parsing[count + 1].args))) {
        return 0;
      }
      ft_putstr_fd("minishell: syntax error near unexpected token `|'\n", 2);
      captur.exit_status = 258;
      return 258;
    }else if (ft_strlen(mini->parsing[count].cmd) > 1 && mini->parsing[count].cmd[0] == '|' && mini->parsing[count].cmd[1] == '|') {
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