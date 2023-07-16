/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 20:16:43 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/16 20:25:07 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ITERM_SESSION_ID

#include "minishell.h"

char *get_value_from_env(char **conten, char *what) {
  int count = 0;
  while (conten[count]) {
    if (ft_strnstr(conten[count], what, ft_strlen(what)) != NULL) {
      return conten[count];
    }
    count++;
  }
  return NULL;
}


void update_env_ontime(t_parsing *shell, t_minishell *mini) {
   
  (void)shell;
  // char *old_pwd_value = get_env_value("OLDPWD", mini);
  // printf("OLDPWD => %s\n", old_pwd_value);
  update_exported_var(get_value_from_env(mini->env_v, "ITERM_SESSION_ID"), mini, "ITERM_SESSION_ID", getenv("ITERM_SESSION_ID"));
  update_exported_var(get_value_from_env(mini->env_v, "LS_COLORS"), mini, "LS_COLORS", getenv("LS_COLORS"));
  update_exported_var(get_value_from_env(mini->env_v, "empty"), mini, "empty", getenv("empty"));
  update_exported_var(get_value_from_env(mini->env_v, "equals"), mini, "equals", getenv("equals"));
  update_exported_var(get_value_from_env(mini->env_v, "SHLVL"), mini, "SHLVL", getenv("SHLVL"));
  return ;
}
