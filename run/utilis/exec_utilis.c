/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utilis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 21:16:47 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/15 21:18:17 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int is_redirec_output(char **args) {
  int count = 0;
  int is_redirec = 0;
  while (args[count]) {
    if (args[count][0] == '>' && args[count][1] == 0) {
      is_redirec = 1;
    }
    count++;
  }
  return is_redirec;
}

int find_file_after_redir(char **args, char c) {
  int count = 0;
  while (args[count]) {
    if (args[count][0] == c && args[count][1] == 0) {
      return (count + 1);
    }
    count++;
  }
  return count;
}

char **get_only_what_ineed_in_arr(char **args) {
  int count = 0;
  char **dst = malloc(sizeof(char *) * (find_file_after_redir(args, '>')));
  while (count < (find_file_after_redir(args, '>') - 1)) {
    dst[count] = ft_strdup(args[count]);
    count++;
  }
  dst[count] = NULL;
  return dst;
}

char **new_content(char **content) {
  int count = 0;
  int index = 0;
  while (content[index][0] != '>') {
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
