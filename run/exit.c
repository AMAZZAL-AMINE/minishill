/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:22:04 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/22 11:09:18 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void exit_shell(t_parsing *shell) {
  printf("exit\n");
  if (!shell->args[0]) {
    exit(0);
  }
  exit(ft_atoi(shell->args[0]));
}
