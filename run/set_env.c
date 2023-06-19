/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:39:28 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/19 23:02:31 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int count_env_vars(char **envs) {
  int count = 0;
  while (envs[count]) {
    count++;
  }
  return count;
}

void set_env(t_minishell *shell) {
  int count = 0;
  int size = count_env_vars(shell->env_v);
  shell->env = malloc(sizeof(t_env) * (size + 1));
  while (count < size) {
    if (ft_strchr(shell->env_v[count], '=') != NULL) {
      shell->env[count].is_haver_equal = 1;
    }
    char **splited = ft_split(shell->env_v[count], '=');
    shell->env[count].name = splited[0];
    shell->env[count].value = splited[1];
    count++;
  }
  shell->n_var_env = size;
}