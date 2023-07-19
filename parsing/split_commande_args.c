/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_commande_args.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:23:36 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/19 18:35:51 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int get_rederection_length(char *token) {
  int count = 0;
  if (token[0] == '>') {
    while (token[count] == '>') {
      count++;
    }
  }else if (token[0] == '<') {
    while (token[count] == '<') {
      count++;
    }
  }
  return count;
}


int count_splited_words(char *token) {
  int count = 0;
  int count_quots = 0;
  int retured_value = 0;
  int helped_counter = 0;
  int saved = 0;
  while (token[count]) {
    if (token[count] == '\'' || token[count] == '\"')
      count_quots++;

    if (((token[count] == ' ') && count_quots % 2 == 0) || count == 0)
      retured_value++;
    if ((token[count] == '>' || token[count] == '<') && count_quots % 2 == 0) {
      helped_counter++;
    }
    saved = count;
    while ((token[saved] == ' ') && count_quots % 2 == 0) {
      saved++;
    }
    if (saved == count) {
      count++;
    }else {
      count = saved;
    }
  }
  return (retured_value + helped_counter);
}

int chekc_is_quots(char *str) {
  int count = 0;
  int count_quots = 0;
  while (str[count]) {
    if (str[count] == '\'' || str[count] == '\"') {
      count_quots++;
    }
    count++;
  }
  if (count_quots % 2 == 0) {
    return 1;
  }else {
    return 0;
  }
}

char	*ft_strndup_new(char const *str, size_t max)
{
	size_t	index;
	char	*dst;

	index = 0;
	dst = malloc(sizeof(char) * (max + 1));
	if (!dst)
	{
		return (0);
	}
  int count_quots = 0;
	while (str[index] && index < max)
	{
    if (str[index] == '\"' || str[index] == '\'') {
      count_quots++;
    }
    if ((str[index] == '>' || str[index] == '<') && count_quots % 2 == 0) {
      break;
    }
		dst[index] = str[index];
		index++;
	}
	dst[index] = '\0';
	return (dst);
}

char **split_commande_args(char *token, t_minishell *minishell) {
  int count = 0;
  int save = 0;
  int index = 0;
  int stopen = 0;
  int within_quots = 0;
  int within_quots_two = 0;
  char **dst = malloc(sizeof(char *) * (count_splited_words(token) + 1));
  while (token[count]) {
    while ((token[count] == ' ') && (within_quots % 2 == 0 && within_quots_two % 2 == 0))
      count++;
    stopen = count;
    if (token[count] == '\"')
      within_quots++;
    if (token[count] == '\'')
      within_quots_two++;
    while (token[count])  {
      if ((token[count] == '>' || token[count] == '<') && (within_quots % 2 == 0 && within_quots_two % 2 == 0))
        break;
      save++;
      count++;
      if (token[count] == '\"') {
        within_quots++;
      }
      if (token[count] == '\'') {
        within_quots_two++;
      }
      if (token[count] == ' ' && (within_quots % 2 == 0 && within_quots_two % 2 == 0))
        break;
    }
    
    if (save > 0) {
      dst[index] =  ft_strdup(ft_strndup_new(&token[stopen], save));
      index++;
    }
  
    if ((token[count] == '>' || token[count] == '<') && (within_quots % 2 == 0 && within_quots_two % 2 == 0)) {
      dst[index] =  ft_strdup(ft_strndup(&token[count], get_rederection_length(&token[count])));
      index++;
    }

    save = 0;
    if ((token[count] == '>' || token[count] == '<') && (within_quots % 2 == 0 && within_quots_two % 2 == 0))
      count += get_rederection_length(&token[count]);
    else {
      if (token[count]) {
        count++;
      }
    }
  }
  dst[index] = NULL;
  within_quots = 0;
  within_quots_two = 0;
  int helepr = 0;
  int helper2 = 0;
  count = 0;
  while (dst[count]) {
    within_quots = 0;
    within_quots_two = 0;
    helepr = 0;
    helper2 = 0;
    while (dst[count][helper2]) {
      if (dst[count][helper2] == '\'') {
        within_quots_two++;
      }
      if (dst[count][helper2] == '\"') {
        within_quots++;
      }
      if (dst[count][helper2] == ' ' && (within_quots % 2 == 0 && within_quots_two % 2 == 0)) {
        break;
      }
      helper2++;
    }
    // printf("%s\n", dst[count]);
    // printf("END\n");
    dst[count] = ft_strndup(dst[count], helper2);
    count++;
  }
  dst[count] = NULL;
  // int size_new_vars = count_length_two_arr(dst);
  // char **new_arg = malloc(sizeof(char *) * (size_new_vars + 1));
  // dst = get_new_arg(new_arg,dst, size_new_vars, minishell);
  (void)minishell;
  return  dst;
}

//echo hello world nice"brother thank you">a | ls -l>a