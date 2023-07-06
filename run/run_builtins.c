/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_builtins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 13:42:49 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/06 18:36:18 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void run_buitins(t_minishell *shell, int count) {
  if (str_cmp("echo", shell->parsing[count].cmd) || str_cmp("/bin/echo", shell->parsing[count].cmd))
    echo_cmd(&shell->parsing[count]);
  else if (str_cmp("cd", shell->parsing[count].cmd) || str_cmp("/usr/bin/cd", shell->parsing[count].cmd))
    change_dir(&shell->parsing[count], shell);
  else if (str_cmp("clear", shell->parsing[count].cmd))
    clear();
  else if (str_cmp("pwd", shell->parsing[count].cmd) || str_cmp("/bin/pwd", shell->parsing[count].cmd))
    pwd(&shell->parsing[count]);
  else if (str_cmp("exit", shell->parsing[count].cmd))
    exit_shell(&shell->parsing[count]);
  else if (str_cmp("env", shell->parsing[count].cmd))
    get_env(shell->env, shell, shell->parsing[count].args);
  else if (str_cmp("export", shell->parsing[count].cmd))
    export(&shell->parsing[count], shell);
  else if (str_cmp("unset", shell->parsing[count].cmd))
    unset(shell, &shell->parsing[count]);  
}
