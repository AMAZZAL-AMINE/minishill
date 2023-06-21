/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:41:41 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/21 22:16:40 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


void get_env(t_env *env, t_minishell *minishell, char **content) {
  int count = 0;
  int pid = fork();
  if (pid == 0) {
    if (search_for_heardoc(content))
      herdoc(content);
    builtin_redirections(content, NULL);
    while (count < minishell->n_var_env) {
      if (env[count].is_haver_equal == 1) {
        printf("%s=%s\n", env[count].name, env[count].value);
      }
      count++;
    }
    exit(0);
  }
  waitpid(pid, NULL, 0);
}