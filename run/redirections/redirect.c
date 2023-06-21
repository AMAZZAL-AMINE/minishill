/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 21:03:03 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/21 23:56:59 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void redirect(int is_path, t_parsing *shell, char **content) {
    int last_fd_readed = 0;
    int fd = 0;
    int fd2 = 0;
    if (shell->n_in_files >= 1 || shell->n_out_files >= 1) {
      int count = 0;
      while (content[count]) {
        if (str_cmp(">", content[count]))
          redirect_output(&fd, content, count, &last_fd_readed);
        if (str_cmp("<", content[count]))
          redirect_input(&fd2, content, count, &last_fd_readed);
        if (str_cmp(">>", content[count]))
         appned(&fd, content, count, &last_fd_readed);
        count++;
      }
    }
    if (last_fd_readed == 0)
      dup2(fd2, 0);
    else if (last_fd_readed == 1)
      dup2(fd, 1);
    else if (last_fd_readed == 2)
      dup2(fd, 1);

  (void)is_path;
}
