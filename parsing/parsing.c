/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:24:34 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/21 22:58:19 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int ft_count_tokens(char *line) {
  int count = 0;
  int count_tokens = 0;
  int opened_quote = 0;
  while (line[count] != '\0') {
   if (line[count] == '\"' || line[count] == '\'') {
      opened_quote++;
      count++;
   }
   if (line[count] == '|' && opened_quote % 2 == 0) {
     count_tokens++;
     count++;
   }
   count++;
  }
  return count_tokens;
}

int find_index_pipe(char *line) {
  int count = 0;
  int count_tokens = 0;
  int opened_quote = 0;
  while (line[count] != '\0') {
   if (line[count] == '\"' || line[count] == '\'') {
      opened_quote++;
      count++;
   }
   if (line[count] == '|' && opened_quote % 2 == 0) {
      return count;
   }
   count++;
  }
  return count_tokens;
}

char **new_tokens(char *line) {
  int count = 0;
  int count_tokens = ft_count_tokens(line) * 2;
  char **tokens = malloc(sizeof(char *) * (count_tokens + 1));
  if (!tokens)
    return NULL;
  char *new_line = ft_strdup(line);
  while (count <= count_tokens) {
    if (find_index_pipe(new_line) == 0) {
      tokens[count] = ft_strndup(new_line, ft_strlen(new_line));
      count++;
    }else {
      tokens[count] = ft_strndup(new_line,find_index_pipe(new_line));
      new_line = new_line + (find_index_pipe(new_line) + 1);
      count++;
      tokens[count] = "|";
      count++;
    }
  }
  tokens[count] = NULL;
  return tokens;
}

//to get the commande length
int commande_length(char *token) {
  int count = 0;
  int index = 0;
  while (token[count]) {
    if (count == 0) {
      while (token[count] == ' ' && token[count]) {
        count++;
      }
      if (token[count] != '\0') {
        while ((token[count] != ' ' && (token[count] != '>'&& token[count] != '<')) && token[count]) {
          index++;
          count++;
        }
      }
    }
    count++;
  }
  if (token[index] == ' ') {
    return index--;
  }
  return index;
}

//to get spicifiq string and skip the first spaces;
char *get_with_fixes_size(char *token, int size) {
  int count = 0;
  int index = 0;
  char *dst = malloc(sizeof(char) * (size + 1));
  while (token[count]) {
    if (count == 0) {
      while (token[count] == ' ' && token[count]) {
        count++;
      }
      if (token[count] != ' ' && token[count] != '\0') {
        while (index <= size) {
          dst[index] = token[count];
          index++;
          count++;
        }
        break;
      }
    }
  }
  dst = ft_strdup(dst);
  return dst;
}

int skip_spaces(char *token) {
  int count = 0;
  while (token[count] == ' ' && token[count]) {
    count++;
  }
  return count;
}

char *rm_spaces_from_cmd(char *cmd) {
  int size = 0;
  while (cmd[size] != ' ' && cmd[size]) {
    size++;
  }
  return ft_strndup(cmd, size);
}

//intialis the structer
void init_and_split(t_minishell *minishell, char *token, int pos) {
  minishell->parsing[pos].cmd = ft_strdup(rm_spaces_from_cmd(get_with_fixes_size(token, commande_length(token))));
  token = update_token(token, commande_length(token));
  token = &token[skip_spaces(token)];
  int count = 0;
  char **dst = split_commande_args(token);
  char **new_dst = dst;
  while (dst[count]) {
    new_dst[count] = remove_quots(dst[count]);
    count++;
  }
  minishell->parsing[pos].args = new_dst;
}

int parsing_input(t_minishell *minishell, char *line) {
  char **tokens = new_tokens(line);
  int count = 0;
  int size = (ft_count_tokens(line) * 2);
  minishell->n_cmd = size;
  minishell->parsing = malloc(sizeof(t_parsing) * size);
  while (count <= size) {
    init_and_split(minishell, tokens[count], count);
    count++;
  }
  return 0;
}
