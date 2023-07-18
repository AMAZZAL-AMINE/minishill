/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quots_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:53:31 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/18 13:42:43 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int single_quots_arr(char *line) {
  int count = 0;
  int count_quots = 0;
  int count_s_quots = 0;
  while (line[count]) {
    if (line[count] == '\"' && count_s_quots == 0) {
      count_quots++;
    }
    if (line[count] == '\'' && count_quots == 0)
      count_s_quots++;
    count++;
  }

  if (count_quots % 2 != 0 || count_s_quots % 2 != 0) {
    ft_putstr_fd("minishell: unexpected EOF while looking for matching\n", 2);
    captur.exit_status = 2;
    return 2;
  }
  return 0;
}