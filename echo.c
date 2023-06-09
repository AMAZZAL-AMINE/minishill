/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:35:30 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/09 18:47:29 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int echo_cmd(t_lexer *lexer) {
 int pid = fork();
    if (pid == 0) {
      if (execve(lexer->path, ft_split(ft_strjoin(ft_strjoin(lexer->cmd, " "), lexer->args), ' '), NULL) == -1) {
        printf("minishell: command not found: %s", lexer->cmd);
        exit(127);
      }
      wait(NULL);
    }
 waitpid(pid, NULL, 0);
 return 0;
}
