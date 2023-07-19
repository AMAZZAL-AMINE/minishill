/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 21:03:03 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/18 23:58:41 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int redirect(int is_path, t_parsing *shell, char **content, t_minishell __unused *mini) {
    int captur = 0;
    int count = 0;
    while (content[count]) {
      if (str_cmp(">", content[count])) {
        captur = redirect_output(content, count);
        if (captur != 0)
          break;
      }
      if (str_cmp("<", content[count])) {
        captur = redirect_input(content, count);
        if (captur != 0)
          break;
      }
      if (str_cmp(">>", content[count])) {
        captur = appned(content, count);
        if (captur != 0)
          break;
      }
      count++;
    }
    shell->args = get_args_without_redirections(shell->args);
  (void)is_path;
  return captur;
}
