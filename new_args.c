/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:26:16 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/09 17:10:59 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
int is_found_this(char *str, char this) {
  int count = 0;
  while (str[count]) {
    if (str[count] == this) {
      return 1;
    }
    count++;
  }
  return 0;
}

char *remove_if_found(char *args, char need_rm) {
  int  count = 0;
  int index = 0;
  char *new_str = malloc(sizeof(char) * ft_strlen(args));
  while (args[count]) {
    if (args[count] != need_rm) {
      new_str[index] = args[count];
      index++;
    }
    count++;
  }
  new_str[index] = '\0';
  return new_str;
}

int is_heredoc(char *args, char her) {
  int count = 0;
  while (args[count]) {
    if (args[count + 1] && (args[count] == her && args[count + 1] == her)) {
      return 1;
    }
    count++;
  }
  return 0;
}

char *filter_args(char *args, t_lexer *lexer) {
  lexer->redirect = NULL;
    lexer->file = NULL;
  if (is_heredoc(args, '>')) {
    lexer->redirect = ">>";
    lexer->file = ft_split(args, '>')[1];
    args = ft_split(args, '>')[0];
    
  }else if (is_heredoc(args, '<')) {
    lexer->redirect = "<<";
    lexer->file = ft_split(args, '<')[1];
    args = ft_split(args, '<')[0];
    
  }else if (is_found_this(args, '<')) {
    lexer->redirect = "<";
    lexer->file = ft_split(args, '<')[1];
    args = ft_split(args, '<')[0];
  }
  else if (is_found_this(args, '>')) {
    lexer->redirect = ">";
    lexer->file = ft_split(args, '>')[1];
    args = ft_split(args, '>')[0];
  }else if (ft_strncmp("cat", lexer->cmd, ft_strlen(lexer->cmd)) == 0) {
    lexer->redirect = NULL;
    lexer->file = ft_split(args, ' ')[0];
    lexer->args = NULL;
  }
  return args;
}
