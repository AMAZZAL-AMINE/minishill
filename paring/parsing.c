/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:24:34 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/12 22:09:50 by mamazzal         ###   ########.fr       */
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
  char **tokens = (char **)malloc(sizeof(char *) * (count_tokens + 1));
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
  tokens[count] = "\0n,";
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
      if (token[count]) {
        while (index < size) {
          dst[index] = token[count];
          index++;
          count++;
        }
        break;
      }
    }
  }
  dst[index] = '\0';
  return dst;
}

int skip_spaces(char *token) {
  int count = 0;
  while (token[count] == ' ' && token[count]) {
    count++;
  }
  return count;
}

//intialis the structer
void init_and_split(t_minishell *minishell, char *token, int pos) {
  minishell->parsing[pos].cmd = get_with_fixes_size(token, commande_length(token));
  token = update_token(token, commande_length(token));
  token = &token[skip_spaces(token)];
  minishell->parsing[pos].args = split_commande_args(token);
  int count = 0;
  while (minishell->parsing[pos].args[count]) {
    printf("%s\n", minishell->parsing[pos].args[count]);
    count++;
  }
 
}

int parsing_input(t_minishell *minishell, char *line) {
  char **tokens = new_tokens(line);
  (void)tokens;
  int count = 0;
  int size = (ft_count_tokens(line) * 2);
  minishell->parsing = malloc(sizeof(t_parsing) * size);
  while (count <= size) {
    init_and_split(minishell, tokens[count], count);
    count++;
  }
  return 0;
}
