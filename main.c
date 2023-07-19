/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:21:08 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/19 14:40:25 by mamazzal         ###   ########.fr       */
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
  signal(SIGQUIT, handle_signals);
  signal(SIGINT, handle_signals);
  minishell->_stdin = dup(STDIN_FILENO);
  minishell->_stdout = dup(STDOUT_FILENO);
  captur.exit_status = 0;

  while (1)
  {
    update_env_ontime(NULL, minishell);
    line = readline("minishell ❯❯❯ ");
    handle_ctl_d(line);
    if (*line) {
      add_history(line);
      parsing_input(minishell, line);
      count_redirections(minishell);
      builtin(minishell, line);
      free(line);
    }
  }
  return 0;
}
