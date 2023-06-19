/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:41:41 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/19 22:56:50 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


void get_env(t_env *env, t_minishell *minishell) {
  int count = 0;
  int pid = fork();
  if (pid == 0) {
    while (count < minishell->n_var_env) {
      if (env[count].is_haver_equal == 1) {
        printf("%s=%s\n", env[count].name, env[count].value);
      }
      count++;
    }
  }
  waitpid(pid, NULL, 0);
}