/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_redirections.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 10:40:31 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/24 19:02:30 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void builtin_redirections(char **content, t_parsing *shell) {
  
  if (search_for_heardoc(content))
    herdoc(content);
  if (is_redirec_output(content)) {
    int count = 0;
    while (content[count]) {
      if (str_cmp(">", content[count]))
        redirect_output(content, count);
      else if (str_cmp("<", content[count]))
        redirect_input(content, count);
      else if (str_cmp(">>", content[count]))
        appned(content, count);
      count++;
    }
    (void)shell;
  }
}
