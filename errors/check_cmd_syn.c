/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd_syn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:41:55 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/20 12:41:51 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


int check_cmd_syntax(char* command, char **args, t_parsing *shell) {
  if (str_cmp(command, ".")) {
    ft_putstr_fd("minishell: .: filename argument required\n", 2);
    ft_putstr_fd(".: usage: . filename [arguments]\n", 2);
    captur.exit_status = 2;
    return 2;
  }else if ((str_cmp(command, ">") || str_cmp(command, ">>") || str_cmp(command, "<") || str_cmp(command, "<<")) && !args[0]) {
    if (shell->is_cmd_var == 1) {
      return 0;
    }
    ft_putstr_fd("minishell: syntax error near unexpected token `newline'\n", 2);
    captur.exit_status = 258;
    return 258;
  }
  return 0;
}