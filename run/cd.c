/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:29:23 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/15 13:28:18 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char *get_env_oldpwd(char **conten) {
  int count = 0;
  while (conten[count]) {
    if (ft_strnstr(conten[count], "OLDPWD", ft_strlen("OLDPWD")) != NULL) {
      return conten[count];
    }
    count++;
  }
  return NULL;
}

int update_oldpwd(t_parsing *shell, t_minishell *mini) {
   
  (void)shell;
  // char *old_pwd_value = get_env_value("OLDPWD", mini);
  // printf("OLDPWD => %s\n", old_pwd_value);
  update_exported_var(get_env_oldpwd(mini->env_v), mini, "OLDPWD", getcwd(NULL, 0));
  return 0;
}

int is_redirec(char *args) {
  if (str_cmp(args, ">") || str_cmp(args, ">>") || str_cmp(args, "<") || str_cmp(args, "<<")) {
    return 1;
  }
  return 0;
}

void change_dir(t_parsing *shell, t_minishell *minishell, int index, int size) {
    if ((index - 1 > 0 && str_cmp(minishell->parsing[index - 1].cmd, "|")) || (index + 1 <= size && str_cmp(minishell->parsing[index + 1].cmd, "|"))) {
      captur.exit_status = 1;
      return ;
    }
    if (shell->args[0] && !is_redirec_output(&shell->args[0])) {
      //modified
      if (check_the_dir_name(shell->args[0]) != 0)
        return;
      update_oldpwd(shell, minishell);
      if (chdir(shell->args[0]) == -1) {
        captur.exit_status = 1;
        printf("minishell: %s: %s: Nooo such file or directory\n", shell->cmd, shell->args[0]);
        return ;
      }
    }else if (shell->args[0] == NULL || is_redirec_output(&shell->args[0])) {
      char *home = get_env_value("HOME", minishell);
      if (home == NULL) {
        ft_putstr_fd("minishell: cd: ", 2);
        ft_putstr_fd("HOME not set\n", 2);
        captur.exit_status = 1;
        return ;
      }
      chdir(home);
    }
    captur.exit_status = 0;
  return;
}
