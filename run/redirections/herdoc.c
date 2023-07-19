/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 22:58:20 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/19 17:25:46 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int is_dolar(char *arg)
{
  int count = 0;
  while (arg[count])
  {
    if (arg[count] == '$')
    {
      return 1;
    }
    count++;
  }
  return 0;
}

int is_eof_in_quot_fun(char *arg)
{
  int count = 0;
 
  while (arg[count])
  {
    if (arg[count] == '\'')
    {
      return 1;
    }
    else if (arg[count] == '\"')
    {
      return 1;
    }
    count++;
  }
  return 0;
}

int run_herdoc(char __unused **content, char *eof, t_minishell __unused *mini, int *pipid) {
    char *line = NULL;
    int is_eof_in_quot = 0;
    char *tmp = "";
    if (is_eof_in_quot_fun(eof))
      is_eof_in_quot = 1;
    eof = remove_quots(eof);
    if (is_dolar(eof) && !is_eof_in_quot)
      eof = expand(eof, mini);
    while (1) {
      line = readline("> ");
      if ((int)line == 0)
        break;
      if (*line) {
        if (is_dolar(line)) {
          if (!is_eof_in_quot)
            line = expand(line, mini);
        }
        if (eof && str_cmp(line, eof))
          break;
        line = ft_strjoin(line, "\n");
        tmp = ft_strjoin(tmp, line);
      }
    }
    if (tmp)
      write(pipid[1], tmp, ft_strlen(tmp));
    close(pipid[1]);
  return pipid[0];
}


int herdoc(char **content, t_minishell __unused *mini) {
  int count = 0;
  int savedid = -1;
  int status;
  char **env = mini->env_v;
  int pid = -1;

  while (content[count]) {
    if (str_cmp(content[count], "<<")) {
      int pipid[2];
      pipe(pipid);
        mini->env_v = env;
        savedid = run_herdoc(content, content[count + 1], mini, pipid);
        close(pipid[1]);
        waitpid(pid, &status, 0);
    }
    count++;
  }

  dup2(savedid, 0);
  if (savedid != -1)
    close(savedid);
  return 0;
}