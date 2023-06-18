/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:02:51 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/18 14:44:35 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char *find_cmd_path(char *cmd) {
  int count = 0;
  char *path = NULL;
  char **paths = ft_split(getenv("PATH"), ':');
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