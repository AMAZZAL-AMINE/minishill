/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_tables.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 15:10:49 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/15 18:42:58 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char **join_tables(char **table1, char **table2) {
  int count = 0;
  int index = 0;
  if (table1 == NULL) {
    return table2;
  }
  int size = count_length_two_arr(table1) + count_length_two_arr(table2);
  char **dst = malloc(sizeof(char *) * (size + 1));
  while (table1[count]) {
    dst[index] = table1[count];
    count++;
    index++;
  }
  count = 0;
  while (table2[count]) {
    dst[index] = table2[count];
    count++;
    index++;
  }
  dst[index] = NULL;
  return dst;
}