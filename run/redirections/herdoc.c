/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 22:58:20 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/17 19:08:26 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int is_dolar(char *arg) {
  int count = 0;
  while (arg[count]) {
    if (arg[count] == '$') {
      return 1;
    }
    count++;
  }
  return 0;
}

int is_eof_in_quot_fun(char *arg) {
  int count = 0;
  int count_it_one = 0;
  int count_it_two = 0;
  while (arg[count]) {
    if (arg[count] == '\'') {
      count_it_one++;
    }else if(arg[count] == '\"') {
      count_it_two++;
    }
    if (arg[count] == '$') {
      if (count_it_one % 2 == 0 && count_it_two % 2 == 0) {
        return 0;
      }
      return 1;
    }
    count++;
  }
  return 0;
}

// int herdoc(char **content, t_minishell __unused *mini) {
//   int i = 0;
//   int fd = 0;
//   char *line = NULL;
//   char *tmp = NULL;
//   char *eof;
//   char *check;
//   int is_eof_in_quot = 0;
//   while (content[i]) {
//     if (str_cmp(content[i], "<<")) {
//       if (content[i + 1] && is_dolar(content[i + 1])) {
//         if (is_eof_in_quot_fun(content[i + 1])) {
//           is_eof_in_quot = 1;
//         }
//         eof = remove_quots(expand(content[i + 1], mini));
//       }else {
//         eof = remove_quots(content[i + 1]);
//       }
//       while (1) {
//         line = readline("> ");
//         if (line) {
//           check = line;
//           if (is_dolar(line)) {
//             if (!is_eof_in_quot)
//               line = expand(line, mini);
//             check = expand(line, mini);
//           }
//           if (eof && str_cmp(check, eof))
//             break;
//           line = ft_strjoin(line, "\n");
//           if (tmp == NULL)
//             tmp = ft_strjoin("", line);
//           else
//             tmp = ft_strjoin(tmp, line);      
//           free(line);
//         }
//       }
//       fd = open("herdoc", O_WRONLY | O_CREAT | O_TRUNC, 0644);
//       ft_putstr_fd(tmp, fd);
//       close(fd);
//     }
//     i++;
//   }

//   captur.exit_status = 0;
//   return 0;
// }

 //<< a << b


int herdoc(char **content,t_minishell __unused *mini) {
  int i = 0;
  int fd = 0;
  char *line = NULL;
  char *tmp = NULL;
  while (content[i]) {
    if (str_cmp("<<", content[i])) {
      while (1) {
        line = readline("> ");
        if ((int)line == 0)
          break;
       if (*line) {
          if (content[i + 1] && str_cmp(line, content[i + 1]))
            break;
          line = ft_strjoin(line, "\n");
          if (tmp == NULL)
            tmp = ft_strjoin("", line);
          else
            tmp = ft_strjoin(tmp, line);
       }
      }
      fd = open("herdoc", O_WRONLY | O_CREAT | O_TRUNC, 0644);
      if (tmp)
        write(fd, tmp, ft_strlen(tmp));
      close(fd);
      fd = open("herdoc", O_RDONLY);
      dup2(fd, 0);
      close(fd);
      content[i] = ft_strdup("<");
      content[i + 1] = ft_strdup("herdoc");
      
    }
    i++;
  }
  captur.exit_status = 0;
  return 0;
}