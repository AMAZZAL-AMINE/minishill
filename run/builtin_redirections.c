/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_redirections.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 10:40:31 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/21 23:57:37 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void builtin_redirections(char **content, t_parsing *shell) {
  if (is_redirec_output(content)) {
    int count = 0;
    int fd = 0;
    int fd2 = 0;
    int last_fd_readed = 0;
    while (content[count]) {
      if (str_cmp(">", content[count])) 
        redirect_output(&fd, content, count, &last_fd_readed);
      else if (str_cmp("<", content[count]))
        redirect_input(&fd2, content, count, &last_fd_readed);
      else if (str_cmp(">>", content[count]))
        appned(&fd, content, count, &last_fd_readed);
      count++;
    }
  }
  (void)shell;
}
