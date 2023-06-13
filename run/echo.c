/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:55:08 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/13 19:29:57 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void echo_redirect_to_file(char **content, char *file, int index) {
  (void) content;
  (void)file;
  (void)index;
  return;
}

int count_quots(char *arg) {
  int count = 0;
  int count_quots = 0;
  while (arg[count]) {
    if (arg[count] == '\"')
      count_quots++;
    count++;
  }

  return (count - count_quots);
}

char *remove_quots(char *arg) {
  int count = 0;
  int index = 0;
  char *new_arg = malloc(sizeof(char) * (count_quots(arg) + 1));
  while (arg[count]) {
    if (arg[count] == '\"') {
        count++;
    }else {
      new_arg[index] = arg[count];
      index++;
      count++;
    }
  }
  new_arg[index] = 0;
  return new_arg;
}

int count_length_two_arr(char **arr) {
  int count = 0;
  while (arr[count]) {
    count++;
  }
  return count;
}

char **join_two_dim_arr(char *s1, char **arr) {
  int count = 1;
  int size = count_length_two_arr(arr) + 1;
  char **dst = malloc(sizeof(char *) * (size + 1));
  dst[0] = s1;
  while (count < size) {
    dst[count] = arr[count - 1];
    count++;
  }
  dst[count] = 0;
  return dst;
}

void echo_in_console(char **content, char *cmd) {
  int chld_pid = fork();
  if (chld_pid == 0) {
    int count = 0;
    while (content[count]) {  
      content[count] = remove_quots(content[count]);
      count++;
    }
    if (execve("/bin/echo", join_two_dim_arr(cmd, content), NULL) == -1) {
      printf("shell: %s: command not found\n", cmd);
    }
    wait(NULL);
  }
  waitpid(chld_pid, NULL, 0);
  return;
}

int echo_cmd(t_parsing *shill) {
  shill->is_re_to_file = 0;
  int count = 0;
  while (shill->args[count]) {
    if (ft_strncmp(">", shill->args[count], ft_strlen(">")) == 0) {
      shill->is_re_to_file = 1;
      break;
    }
    count++;
  }
  if (shill->is_re_to_file == 1) {
    echo_redirect_to_file(shill->args, shill->args[count + 1], count);
  }else {
    echo_in_console(shill->args, shill->cmd);
  }
  return 0;
}