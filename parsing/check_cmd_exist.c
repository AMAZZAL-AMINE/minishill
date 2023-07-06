/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd_exist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:40:48 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/06 18:48:30 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void check_cmd_exist(t_parsing *shell, t_minishell *ms) {
  if (shell->cmd[0] == '$' && shell->cmd[1]) {
    if (shell->cmd[1] == '?') {
      shell->cmd = ft_itoa(ms->caputre_exit_status);
    }else if (get_env_value(&shell->cmd[1], ms) != NULL) {
      shell->cmd = get_env_value(&shell->cmd[1], ms);
    }
  }
}