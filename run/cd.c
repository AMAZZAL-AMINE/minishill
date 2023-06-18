/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:29:23 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/18 22:24:48 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int is_redirec(char *args) {
    if (str_cmp(args, ">") || str_cmp(args, ">>") || str_cmp(args, "<") || str_cmp(args, "<<")) {
      return 1;
    }
  return 0;
}

  
void redirect_cd(t_parsing *shell) {
  int count = 0;
  int fd = 0;
  int fd2 = 0;
  while (shell->args[count]) {
    if (str_cmp(shell->args[count], ">")) {
      fd = open(shell->args[count + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
      dup2(0, fd);
    }
    if (str_cmp(shell->args[count], "<")) {
      fd2 = open(shell->args[count + 1], O_RDONLY);
      dup2(0, fd2);
    }
    if (str_cmp(shell->args[count], ">>")) {
      fd = open(shell->args[count + 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
      dup2(0, fd);
    }else if (str_cmp(shell->args[count], "<<")) {
      char *line = NULL;
      char *tmp = NULL;
      while (1) {
        line = readline("> ");
        if (str_cmp(line, shell->args[count + 1]))
            break;
        line = ft_strjoin(line, "\n");
        if (tmp == NULL)
            tmp = ft_strjoin("", line);
        else
            tmp = ft_strjoin(tmp, line);
      }
    }
    count++;
  }
}

void change_dir(t_parsing *shell) {
    if (is_redirec_output(shell->args)) {
      redirect_cd(shell);
    }
    if (shell->args[0] && !is_redirec(shell->args[0])) {
      if (chdir(shell->args[0]) == -1) {
        printf("minishell: %s: %s: No such file or directory\n", shell->cmd, shell->args[0]);
      }
    }else if (shell->args[0] == NULL || is_redirec_output(&shell->args[0])) {
      chdir(getenv("HOME"));
    }
  return;
}