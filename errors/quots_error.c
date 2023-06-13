/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quots_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:53:31 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/13 14:53:30 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void single_quots_arr(char *line) {
  int count = 0;
  int count_quots = 0;
  while (line[count]) {
    if (line[count] == '\"' || line[count] == '\'') {
      count_quots++;
    }
    count++;
  }

  if (count_quots % 2 != 0) {
    error_message("single quotes not closed", 1, line); 
  }
  return;
}