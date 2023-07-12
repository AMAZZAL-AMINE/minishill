/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_redirections.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 10:40:31 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/11 15:02:22 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int builtin_redirections(char **content, t_parsing *shell) {
  int captur = 0;
  if (search_for_heardoc(content))
    herdoc(content);
  if (is_redirec_output(content)) {
    int count = 0;
    while (content[count]) {
      if (str_cmp(">", content[count]))
        captur = redirect_output(content, count);
      else if (str_cmp("<", content[count]))
        captur = redirect_input(content, count);
      else if (str_cmp(">>", content[count]))
        captur = appned(content, count);
      count++;
    }
    (void)shell;
  }
  return captur;
}
