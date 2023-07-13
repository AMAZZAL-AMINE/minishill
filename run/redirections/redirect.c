/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 21:03:03 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/12 15:07:15 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int redirect(int is_path, t_parsing *shell, char **content) {
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
  (void)is_path;
  (void)shell;
  return captur;
}
