/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 20:17:48 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/06 16:11:40 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void expand(t_parsing *shell, t_minishell *ms) {
  int count = 0;
  while (shell->args[count]) {
    if (shell->args[count][0] == '$') {
      if (shell->args[count][1] == '?') {
        shell->args[count] = ft_itoa(ms->caputre_exit_status);
      }else {
        shell->args[count] = get_env_value(&shell->args[count][1], ms);
      }
    }
    count++;
  }
}
