/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambiguous.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 19:28:25 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/20 13:13:54 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int is_dolar_between_quot(char *str) {
  int count = 0;
  int count2 = 0;

  while (str[count]) {
    if (str[count] == '\"') {
      count2++;
    }

    if (str[count] == '$' && count2 % 2 != 0) {
      return 1;
    }
    count++;
  }
  return 0;
}

int is_btween_word_space(char *str) {
  int count = 0;
  while (str[count]) {
    if (str[count] == ' ') {
      return 1;
    }
    count++;
  }
  return 0;
}

int is_ambiguous_file(char *name, t_minishell *mini) {
  if (name[0] == '$') {
    char *dst = ft_strdup(name);
    dst = expand(dst, mini);
    if (ft_strlen(dst) == 0) {
      ft_putstr_fd("minishell: ", 2);
      ft_putstr_fd(name, 2);
      ft_putstr_fd(": ambiguous redirect\n", 2);
      captur.exit_status = 1;
      return 1;
    }else if (is_dolar_(name)) {
      if (!is_dolar_between_quot(name)) {
        int index = 0;
        while (name[index]) {
          if (name[index] == '$') {
            dst = expand(ft_strdup(name), mini);
            if (is_btween_word_space(dst)) {
              ft_putstr_fd("minishell: ", 2);
              ft_putstr_fd(name, 2);
              ft_putstr_fd(": ambiguous redirect\n", 2);
              captur.exit_status = 1;
              return 1;
            }
          }
          index++;
        }
      }
    }
  }
  captur.exit_status = 0;
  return 0;
}
