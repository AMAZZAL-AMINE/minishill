/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_commande_args.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:23:36 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/12 17:44:20 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int count_splited_words(char *token) {
  int count = 0;
  int count_quots = 0;
  int retured_value = 0;
  int saved = 0;
  while (token[count]) {
    if (token[count] == '\'' || token[count] == '\"') {
      count_quots++;
    }

    if ((token[count] == ' ' && count_quots % 2 == 0) || count == 0) {
      retured_value++;
    }
    saved = count;
    while (token[saved] == ' ' && count_quots % 2 == 0) {
      saved++;
    }
    if (saved == count) {
      count++;
    }else {
      count = saved;
    }
  }
  return retured_value;
}


char *get_string(char *token , int size) {
  int count = 0;
  char *dst = malloc(sizeof(char) * (size + 1));
  while (count < size) {
    dst[count] = token[count];
    count++;
  }
  dst[count] = '\0';
  return dst;
}

char **split_commande_args(char *token) {
  int count = 0;
  int save = 0;
  int index = 0;
  int stopen = 0;
  int within_quots = 0;
  char **dst = malloc(sizeof(char *) * (count_splited_words(token) + 1));
  while (token[count]) {
    if (token[count] == '\"') {
      within_quots++;
    }
    while (token[count] == ' ' && within_quots % 2 == 0) {
      printf("TOKEN INDEX : %d\n",  count);
      count++;
    }
    stopen = count;
    while (token[count] != ' ' && token[count])  {
      save++;
      count++;
      if (token[count] == '\"' && token[count + 1]) {
        within_quots++;
        save++;
      }
      if (token[count] == ' ' && within_quots % 2 != 0) {
        count++;
        save++;
      }
    }
    dst[index++] =  ft_strndup(&token[stopen], save);
    save = 0;
    count++;
  }
  dst[index] = NULL;
  return  dst;
}
