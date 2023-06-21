/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 22:58:20 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/21 09:56:12 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void herdoc(char **content) {
  int i = 0;
  int fd = 0;
  char *line = NULL;
  char *tmp = NULL;
  while (content[i]) {
    if (str_cmp("<<", content[i])) {
      while (1) {
        line = readline("> ");
        if (str_cmp(line, content[i + 1]))
          break;
        line = ft_strjoin(line, "\n");
        if (tmp == NULL)
          tmp = ft_strjoin("", line);
        else
          tmp = ft_strjoin(tmp, line);
        free(line);
      }
      fd = open("herdoc", O_RDWR | O_CREAT | O_TRUNC, 0644);
      write(fd, tmp, ft_strlen(tmp));
      close(fd);
      fd = open("herdoc", O_RDONLY);
      dup2(fd, 0);
      close(fd);
      tmp = NULL;
      content[i] = ft_strdup("<");
      content[i + 1] = ft_strdup("herdoc");
    }
    i++;
  }
}