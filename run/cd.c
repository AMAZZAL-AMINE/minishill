/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:29:23 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/22 14:25:13 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int is_redirec(char *args) {
  if (str_cmp(args, ">") || str_cmp(args, ">>") || str_cmp(args, "<") || str_cmp(args, "<<")) {
    return 1;
  }
  return 0;
}

void change_dir(t_parsing *shell, t_minishell *minishell) {
  if (is_redirec_output(shell->args) == 1) {
    dup2(2, 1);
    redirect(0, shell, shell->args);
  }
    if (shell->args[0]) {
      if (chdir(shell->args[0]) == -1) {
        printf("minishell: %s: %s: No such file or directory\n", shell->cmd, shell->args[0]);
      }
    }else if (shell->args[0] == NULL || is_redirec_output(&shell->args[0])) {
      chdir(get_from_env("HOME", minishell));
    }
  return;
}