/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quots.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 10:17:36 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/24 12:44:09 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int count_quots(char *arg) {
  int count = 0;
  int count_quots = 0;
  while (arg[count]) {
    if (arg[count] == '\"')
      count_quots++;
    count++;
  }

  return (count - count_quots);
}


char *remove_quots(char *arg) {
  int count = 0;
  int index = 0;
  char *new_arg = malloc(sizeof(char) * (count_quots(arg) + 1));
  while (arg[count]) {
    if (arg[count] == '\"') {
        count++;
    }else {
      new_arg[index] = arg[count];
      index++;
      count++;
    }
  }
  new_arg[index] = 0;
  return new_arg;
}