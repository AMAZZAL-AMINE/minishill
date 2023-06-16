/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_all_in_current_place.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:44:15 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/16 19:13:37 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void count_redirections(t_minishell *shell) {
  int  count = 0;
  int index = 0;
  int count_out = 0;
  int count_in = 0;
  while (count <= shell->n_cmd) {
    index = 0;
    count_out = 0;
    count_in = 0;
    while (shell->parsing[count].args[index]) {
      if (!ft_strncmp(shell->parsing[count].args[index], ">", ft_strlen(shell->parsing[count].args[index]))) {
        count_out++;
      }else if (!ft_strncmp(shell->parsing[count].args[index], "<", ft_strlen(shell->parsing[count].args[index]))) {
        count_in++;
      }
      index++;
    }
    shell->parsing[count].n_out_files = count_out;
    shell->parsing[count].n_in_files = count_in;
    count++;
  }
}