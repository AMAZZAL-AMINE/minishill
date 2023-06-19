/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:41:41 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/19 17:51:51 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


void get_env(t_env *env, t_minishell *minishell) {
  int count = 0;
  int pid = fork();
  if (pid == 0) {
    while (count < minishell->n_var_env) {
      printf("%s=%s\n", env[count].name, env[count].value);
      count++;
    }
  }
  waitpid(pid, NULL, 0);
}