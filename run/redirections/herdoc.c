/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 22:58:20 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/17 23:01:54 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void herdoc(int *fd, int *fd2, char **content, int count, int *last_fd_readed) {
  char *line = "";
  char *tmp = "";
  if (content[count + 1] == NULL) {
    printf("minishell: syntax error near unexpected token `newline'\n");
    exit(127);
  }
  while (1) {
    line = readline("> ");
    if (str_cmp(line, content[count + 1]))
      break;
    line = ft_strjoin(line, "\n");
    if (tmp == NULL)
      tmp = ft_strjoin("", line);
    else
      tmp = ft_strjoin(tmp, line);
    free(line);
  }
  *fd = open("herdoc", O_WRONLY | O_CREAT | O_TRUNC, 0644);
  write(*fd, tmp, ft_strlen(tmp));
  *fd2 = open("herdoc", O_RDONLY);
  dup2(*fd2, 0);
  *last_fd_readed = 0;
}