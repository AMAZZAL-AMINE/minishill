/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:48:42 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/11 15:23:57 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void unset(t_minishell *ms, t_parsing *shell) {
  int count = 0;
  while (shell->args[count]) {
    int index = 0;
    while (ms->env_v[index]) {
      char **splpited = ft_split(ms->env_v[index], '=');
      if (str_cmp(shell->args[count], splpited[0])) {
        while ((index + 1) <= ms->n_var_env) {
          ms->env_v[index] = ms->env_v[index + 1];
          index++;
        }
        break;
      }
      index++;
    }
    count++;
  }

  count = 0;
  while (shell->args[count]) {
    int index = 0;
    while (index < ms->n_var_env) {
      if (str_cmp(ms->env[index].name, shell->args[count])) {
        while (index <= ms->n_var_env) {
          ms->env[index] = ms->env[index + 1];
          index++;
        }
        ms->n_var_env--;
        break;
      }
      index++;
    }
    count++;
  }
  captur.exit_status = 0;
}
 