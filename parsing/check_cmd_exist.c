/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd_exist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:40:48 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/11 21:58:59 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


void check_cmd_exist(t_parsing *shell, t_minishell *ms) {
  char *old_cmd = ft_strdup(shell->cmd);
  if (ft_strlen(old_cmd) == 0) {
    if (shell->args[0]) {
      shell->cmd = ft_strdup(shell->args[0]);
      shell->args = shell->args + 1;
    }
  }
  if (shell->cmd[0] == '$' && shell->cmd[1]) {
    if (shell->cmd[1] == '?') {
      shell->cmd = ft_itoa(captur.exit_status);
    }else if (get_env_value(&shell->cmd[1], ms) != NULL) {
      shell->cmd = get_env_value(&shell->cmd[1], ms);
    }
    if (!old_cmd) {
      if (shell->args[0]) {
        shell->cmd = ft_strdup(shell->args[0]);
        shell->args = shell->args + 1;
      }
    }
  }
}
