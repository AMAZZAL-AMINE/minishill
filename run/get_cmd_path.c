/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:02:51 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/23 20:25:57 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char *get_env_value(char *what, t_minishell *shell) {
  int count = 0;
  char **content = NULL;
  while (shell->n_var_env > count) {
    content = ft_split(shell->env_v[count], '=');
    if (str_cmp(content[0], what)) {
      return content[1];
    }
    count++;
  }
  return NULL;
}

char *find_cmd_path(char *cmd, t_minishell *shell) {
  int count = 0;
  char *path = NULL;
  char **paths = ft_split(get_env_value("PATH", shell), ':');
  struct stat state;
  while (paths[count]) {
    if (stat(ft_strjoin(ft_strjoin(paths[count], "/"), cmd), &state) == 0) {
      path = ft_strjoin(ft_strjoin(paths[count], "/"), cmd);
      return path;
      break;
    }
    count++;
  }
  return cmd;
}
