/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambiguous.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 19:28:25 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/19 19:20:04 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int is_ambiguous_file(char *name, t_minishell *mini) {
  if (name[0] == '$') {
    char *dst = ft_strdup(name);
    dst = expand(dst, mini);
    if (ft_strlen(dst) == 0) {
      ft_putstr_fd("minishell: line 1: ", 2);
      ft_putstr_fd(name, 2);
      ft_putstr_fd(": ambiguous redirect\n", 2);
      captur.exit_status = 1;
      return 1;
    }
  }
  captur.exit_status = 0;
  return 0;
}