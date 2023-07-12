/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_not_found.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:40:37 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/11 13:54:04 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void cmd_not_found(char *cmd, t_minishell *mini)
{
  (void)mini;
  ft_putstr_fd("minishell: ", 2);
  ft_putstr_fd(cmd, 2);
  ft_putstr_fd(": command not found\n", 2);
  captur.exit_status = 127;
  exit(127);
}
