/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_redirections.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 10:40:31 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/20 13:30:50 by mamazzal         ###   ########.fr       */
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
      if (is_dolar_(new_content[count]) && is_bettwen_double(new_content[count])) {
        new_content[count] = expand(new_content[count], mini);
        // new_content[count] = get_value_with_no_moure_then_space(new_content[count]);
      }
      new_content[count] = remove_quots(new_content[count]);
      count++;
    }
    count = 0;
    while (content[count]) {
      if (str_cmp(">", content[count])) {
        if (content[count + 1] && !is_ambiguous_file(content[count + 1], mini)) {
          captur = redirect_output(new_content, count);
          if (captur != 0)
            break;
        }else {
          captur = 1;
          break;
        }
      }
      else if (str_cmp("<", content[count])) {
        if (content[count + 1] && !is_ambiguous_file(content[count + 1], mini)) {
          captur = redirect_input(new_content, count);
          if (captur != 0)
            break;
        }else {
          captur = 1;
          break;
        }
      }
      else if (str_cmp(">>", content[count])) {
        if (content[count + 1] && !is_ambiguous_file(content[count + 1], mini)) {
          captur = appned(new_content, count);
          if (captur != 0)
            break;
        }else {
          captur = 1;
          break;
        }
      }
      count++;
    }
    shell->args = get_args_without_redirections(shell->args);
  }
  return captur;
}
