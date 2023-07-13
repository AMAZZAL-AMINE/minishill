/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quots.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 10:17:36 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/12 23:08:55 by mamazzal         ###   ########.fr       */
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
    int len = 0;
    int count_s_quot = 0;
    int count_d_quot = 0;
    int count = 0;
    int index = 0;
    while (arg[count]) {
        if (arg[count] == '\"' && count_s_quot == 0) {
            count_d_quot++;
        }
        if (arg[count] == '\'' && count_d_quot == 0) {
          count_s_quot++;
        }
        count++;
    }
    len = count;
    count_d_quot = 0;
    count_s_quot = 0;
    char *new_arg = malloc(sizeof(char) * (len + 1));
    count = 0;
    while (arg[count]) {
        if (arg[count] == '\'' && count_d_quot == 0) {
          count_s_quot++;
        }
        else if (arg[count] == '\"' && count_s_quot == 0) {
          count_d_quot++;
        }
        else {
          new_arg[index] = arg[count];
          index++;
        }
        count++;
    }
    new_arg[index] = '\0';
    return new_arg;
}