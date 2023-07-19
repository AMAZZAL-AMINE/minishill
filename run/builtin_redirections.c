/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_redirections.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 10:40:31 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/19 18:01:34 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int is_dolar_(char *str) {
  int count = 0;
  while (str[count]) {
    if (str[count] == '$')
      return 1;
    count++;
  }
  return 0;
}

int builtin_redirections(char **content, t_parsing *shell, t_minishell *mini) {
  int captur = 0;
  if (search_for_heardoc(content))
    herdoc(content, mini);
  if (is_redirec_output(content)) {
    int count = 0;
    char **new_content = duplicate_content(content);
    count = 0;
    while (new_content[count]) {
      new_content[count] = remove_quots(new_content[count]);
      if (is_dolar_(new_content[count]))
        new_content[count] = expand(new_content[count], mini);
      count++;
    }
    count = 0;
    while (content[count]) {
      if (str_cmp(">", content[count])) {
        captur = redirect_output(content, count);
        if (captur != 0)
          break;
      }
      else if (str_cmp("<", content[count])) {
        captur = redirect_input(content, count);
        if (captur != 0)
          break;
      }
      else if (str_cmp(">>", content[count])) {
        captur = appned(content, count);
        if (captur != 0)
          break;
      }
      count++;
    }
    shell->args = get_args_without_redirections(shell->args);
  }
  return captur;
}
