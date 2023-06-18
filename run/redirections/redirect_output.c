/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 22:49:49 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/18 21:06:19 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void redirect_output(int *fd, char **content, int count, int *last_fd_readed) {
    *fd = open(content[count + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (*fd < 0) {
      dup2(2, 1);
      printf("minishell: %s: No such file or directory\n", content[count + 1]);
      *last_fd_readed = 1;
      exit(127);
    }
    dup2(*fd, 1);
    *last_fd_readed = 1;
    return ;
}
