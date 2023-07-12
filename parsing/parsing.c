/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:24:34 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/12 11:30:26 by mamazzal         ###   ########.fr       */
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
        while (token[count] && token[count] != ' ') {
          if (token[count] == '>' || token[count] == '<')
            return index;
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
char *get_cmd_with_fixes_size(char *token, int size) {
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
          if (token[count] == '>' || token[count] == '<') {
            if (index == 0 && (token[count] == '>' || token[count] == '<')) {
              char *tmp = ft_strdup(ft_strndup(&token[count], get_rederection_length(&token[count])));
              dst[index++] = tmp[0];
              dst[index++] = tmp[1];
            }
            break;
          }
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

int is_dolar_var(char *arg) {
  int count = 0;
  while (arg[count]) {
    if (arg[count] == '$') {
      return 1;
    }
    count++;
  }
  return 0;
}

int get_size_of_arg_if_args(char **args) {
  int count = 0;
  int size_of = 0;
  while (args[count]) {
    if (is_dolar_var(args[count])) {
      size_of += count_length_two_arr(ft_split(args[count], '$'));
    }
    count++;
  }
  return (size_of + count_length_two_arr(args));
}

int get_length_var(char *s) {
  int count = 0;
  if (s[0] == '$') {
    count = 1;
  }
  while (s[count] && (s[count] != '$')) {
    count++;
  }
  return count;
}

char **split_variabls(char *arg, int size) {
  int count = 0;
  int index = 0;
 
  char  **dst = malloc(sizeof(char *) * (size + 1));
  while (index < size) {
    if (index == 0) {
      if (arg[0] != '$') {
        if (index == 0) {
          while (arg[count]) {
            if (arg[count] == '$') {
              break;
            }
            count++;
          }
          dst[index] = ft_strndup(arg, count);
          index++;
          arg = ft_strchr(arg, '$');
        }
      }
    }
    if (*arg && arg[0] == '$') {
      count = 0;
      while (arg[count]) {
        if (arg[count] == '$' && count != 0) {
          break;
        }
        count++;
      }
      dst[index] = ft_strndup(arg, count);
      arg = ft_strchr(arg + 1, '$');
    }
    index++;
    if (arg == NULL) {
      break;
    }
  }
  dst[index++] = NULL;
  return dst;
}

char **get_new_arg(char **dst, char **args, int size, t_minishell *minishell) {
  int count = 0;
  int index = 0;
  (void)size;
  while (args[count]) {
    if (is_dolar_var(args[count])) {
      int new_size = count_length_two_arr(ft_split(args[count], '$'));
      char **new_dst = split_variabls(args[count], new_size);
      char *s = "";
      int new_index = 0;
      while (new_index < new_size) {
        if (new_dst[new_index][0] == '$') {
          char *d;
          if (new_dst[new_index][1] == '?')
            d = ft_itoa(captur.exit_status);
          else
            d  = get_env_value(&new_dst[new_index][1], minishell);
          if (d) {
            s = ft_strjoin(s, d);
          }
        }else {
          s = ft_strjoin(s, new_dst[new_index]);
        }
        new_index++;
      }
      dst[index] = s;
      index++;
    }else {
      dst[index] = args[count];
      index++;
    }
    count++;
  }
  dst[index] = NULL;
  return dst;
}

//intialis the structer
void init_and_split(t_minishell *minishell, char *token, int pos) {
  minishell->parsing[pos].cmd = ft_strdup(rm_spaces_from_cmd(get_cmd_with_fixes_size(token, commande_length(token))));
  int count = 0;
  if (is_dolar_var(minishell->parsing[pos].cmd) && !str_cmp(minishell->parsing[pos].cmd, "$"))
    minishell->parsing[pos].cmd = expande_cmd(minishell->parsing[pos].cmd, minishell);
  token = update_token(token, commande_length(token));
  token = &token[skip_spaces(token)];
  count = 0;
  char **dst = split_commande_args(token);
  char **new_dst = dst;
  while (dst[count]) {
    new_dst[count] = remove_quots(dst[count]);
    count++;
  }
  minishell->parsing[pos].args = new_dst;
  int size_new_vars = count_length_two_arr(minishell->parsing[pos].args);
  char **new_arg = malloc(sizeof(char *) * (size_new_vars + 1));
  minishell->parsing[pos].args = get_new_arg(new_arg,minishell->parsing[pos].args, size_new_vars, minishell);
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
  // exit(0);
  return 0;
}

//ls | ls -l | cat -e | grep ls | wc -l | > a