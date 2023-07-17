/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_two_dem_arr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:26:05 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/16 23:25:37 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int count_length_two_arr(char **arr) {
  int count = 0;
  while (arr[count]) {
    count++;
  }
  return count;
}

char **join_two_dim_arr(char *s1, char **arr) {
  int count = 1;
  int size = count_length_two_arr(arr) + 1;
  char **dst = malloc(sizeof(char *) * (size + 1));
  dst[0] = s1;
  while (count < size) {
    dst[count] = arr[count - 1];
    count++;
  }
  dst[count] = 0;
  return dst;
}