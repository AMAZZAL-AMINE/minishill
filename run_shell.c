/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_shell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:18:35 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/09 18:24:55 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int run_shell(t_cmd_table *table) {
  int count = 0;
  while (count < table->count) {
    if ((ft_strncmp("echo", table->lexer[count].cmd, ft_strlen(table->lexer[count].cmd)) == 0) || 
      ft_strncmp(ft_strjoin("/bin/", table->lexer[count].cmd + ft_strlen("/bin/")), table->lexer[count].cmd, ft_strlen(table->lexer[count].cmd)) == 0) {
        if (ft_strncmp(ft_strjoin("/bin/", table->lexer[count].cmd + ft_strlen("/bin/")), table->lexer[count].cmd, ft_strlen(table->lexer[count].cmd)) == 0) {
          table->lexer[count].path = table->lexer[count].cmd;
        }else {
          table->lexer[count].path = ft_strjoin("/bin/", table->lexer[count].cmd);
        }
        if (echo_cmd(&table->lexer[count]) == -1)
          return -1;
    }
    count++;
  }

  return 0;
}