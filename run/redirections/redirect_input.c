/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 22:45:05 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/21 23:56:28 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void redirect_input(int *fd2, char **content, int count, int *last_fd_readed) {
  *fd2 = open(content[count + 1], O_RDONLY);
  if (*fd2  < 0) {
    dup2(2, 1);
    printf("minishell: %s: No such file or directory\n", content[count + 1]);
    *last_fd_readed = 1;
    exit(1);
  }
  dup2(*fd2, 0);
  *last_fd_readed = 0;
  close(*fd2);
}