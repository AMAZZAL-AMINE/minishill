/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:21:08 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/06 15:24:25 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int ac, char **av, char **env)
{
  (void)ac;
  (void)av;
  t_minishell    *minishell;
  char           *line;
  
  minishell = malloc(sizeof(t_minishell));
  if (!minishell)
    return 0;
  minishell->env_v = env;
  set_env(minishell);
  signal(SIGINT, handle_signals);
  while (1)
  {
    line = readline("\033[0;35mminishell ~>\033[0m ");
    handle_ctl_d(line);
    all_functions_errors(line);
    if (*line) {
      add_history(line);
      parsing_input(minishell, line);
      count_redirections(minishell);
      builtin(minishell, line);
    }
  }
  free(line);
  return 0;
}
