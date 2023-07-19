/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 21:03:03 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/19 18:01:28 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"



int redirect(int is_path, t_parsing *shell, char **content, t_minishell __unused *mini) {
    int captur = 0;
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
    while (new_content[count]) {
      if (str_cmp(">", new_content[count])) {
        captur = redirect_output(new_content, count);
        if (captur != 0)
          break;
      }
      if (str_cmp("<", new_content[count])) {
        captur = redirect_input(new_content, count);
        if (captur != 0)
          break;
      }
      if (str_cmp(">>", new_content[count])) {
        captur = appned(new_content, count);
        if (captur != 0)
          break;
      }
      count++;
    }
    shell->args = get_args_without_redirections(shell->args);
  (void)is_path;
  return captur;
}
