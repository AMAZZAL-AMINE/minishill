/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 21:46:58 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/11 21:48:40 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char *expande_cmd(char *cmd, t_minishell *minishell) {
  int count = 0;
  int cmd_size = count_length_two_arr(ft_split(cmd, '$'));
  char **dst_cmd = split_variabls(cmd, cmd_size);
  char *s = "";
  while (count < cmd_size) {
    if (dst_cmd[count][0] == '$') {
        char *d;
        if (dst_cmd[count][1] == '?')
          d = ft_itoa(captur.exit_status);
        else
          d  = get_env_value(&dst_cmd[count][1], minishell);
        if (d) {
          s = ft_strjoin(s, d);
        }
      }else {
        s = ft_strjoin(s, dst_cmd[count]);
      }
      count++;
  }
  return  s;
}