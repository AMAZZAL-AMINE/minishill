/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:21:08 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/18 15:51:02 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(void)
{
  t_minishell    *minishell;
  char           *line;

  minishell = malloc(sizeof(t_minishell));
  if (!minishell)
    return 0;
  while (1)
  {
    line = readline("\033[0;35mminishell ~>\033[0m ");
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
