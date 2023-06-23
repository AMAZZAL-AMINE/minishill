/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 22:45:05 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/23 20:11:26 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void redirect_input(char **content, int count) {
   if (access(content[count + 1], F_OK) == -1) {
      dup2(0, 1);
      ft_putstr_fd("minishell: ", 2);
      ft_putstr_fd(content[count + 1], 2);
      ft_putstr_fd(": No such file or directory\n", 2);
      close(1);
      return;
   }
  int fd = open(content[count + 1], O_RDONLY);
  dup2(fd, 0);
}