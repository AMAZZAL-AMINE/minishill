/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utilis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 21:16:47 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/17 12:36:19 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int is_redirec_output(char **args) {
  int count = 0;
  int is_redirec = 0;
  while (args[count]) {
    if (str_cmp(">", args[count]) || str_cmp("<", args[count])) {
      is_redirec = 1;
    }
    count++;
  }
  return is_redirec;
}

char **new_content(char **content) {
  int count = 0;
  int index = 0;
  while (content[index][0] != '>' && content[index][0] != '<') {
    index++;
  }
  char **dst = malloc(sizeof(char *) * (index + 1));
  while (count < index) {
    dst[count] = ft_strdup(content[count]);
    count++;
  }
  dst[count] = NULL;
  return dst;
}
