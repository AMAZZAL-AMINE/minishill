/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:24:34 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/19 18:21:44 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int ft_count_tokens(char *line) {
  int count = 0;
  int count_tokens = 0;
  int opened_quote = 0;
  int s_opened_quote = 0;
  while (line[count] != '\0') {
   if (line[count] == '\"') {
      opened_quote++;
   }
   if (line[count] == '\'') {
    s_opened_quote++;
   }
   if (line[count] == '|' && (opened_quote % 2 == 0 && s_opened_quote % 2 == 0)) {
     count_tokens++;
   }
   count++;
  }
  return count_tokens;
}

int find_index_pipe(char *line) {
  int count = 0;
  int opened_quote = 0;
  int opened_si_quot = 0;
  while (line[count] != '\0') {
   if (line[count] == '\"') {
      opened_quote++;
   }
   if (line[count] == '\'') {
    opened_si_quot++;
   }
   if (line[count] == '|') {
    if ((opened_quote % 2 == 0 && opened_si_quot % 2 == 0)) {
      return count;
    }
   }
   count++;
  }
  return count;
}

char *pip_strchr(char *arg) {
  int count = 0;
  int opened_quote = 0;
  int opened_si_quot = 0;
  while (arg[count]) {
    if (arg[count] == '\"') {
      opened_quote++;
    }
    if (arg[count] == '\'') {
      opened_si_quot++;
    }
    if (arg[count] == '|') {
      if ((opened_quote % 2 == 0 && opened_si_quot % 2 == 0)) {
        return arg + (count + 1);
      }
    }
    count++;
  }
  return NULL;
}

char *join_strin_with_alpha(char *str, char c) {
  char *dst = malloc(sizeof(char) * (ft_strlen(str) + 2));
  
  int count = 0;
  while (str[count]) {
    dst[count] = str[count];
    count++;
  }
  dst[count] = c;
  dst[count + 1] = '\0';
  return dst;
}

char **new_tokens(char *line) {
  int count = 0;
  int count_tokens = ft_count_tokens(line) * 2;
  char **tokens = (char **)malloc(sizeof(char *) * (count_tokens + 1));
  if (!tokens)
    return NULL;
  char *new_line = ft_strdup(line);
  while (count <= count_tokens) {
    if (find_index_pipe(new_line) == 0) {
      tokens[count] = ft_strndup(new_line, ft_strlen(new_line));
      count++;
    }else {
      tokens[count] = ft_strndup(new_line, (find_index_pipe(new_line)));
      new_line = pip_strchr(new_line);
      count++;
      if (!new_line) {
        break;
      }
      tokens[count] = "|";
      count++;
    }
  }
  // tokens[count] = NULL;
  return tokens;
}

//to get the commande length
int commande_length(char *token) {
  int count = 0;
  int index = 0;
  int size = ft_strlen(token);
  while (count < size) {
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

int is_q_in_cmd(char *token) {
  int count = 0;
  int is_space_or_any_to_split = 0;
  while (token[count]) {
    if (token[count] == ' ' || (token[count] == '>' || token[count] == '<'))
      is_space_or_any_to_split = 1;
    if ((token[count] == '\'' || token[count] == '\"') && is_space_or_any_to_split == 0) {
      return 1;
    }
    count++;
  }
  return 0;
}

//to get spicifiq string and skip the first spaces;
char *get_cmd_with_fixes_size(char *token, int size) {
  int count = 0;
  int index = 0;
  char *dst;
  if (is_q_in_cmd(token)) {
    int count_quots = 0;
    int count_s_quots = 0;
    int new_size = 0;
    while (token[count]) {
      if ((token[count] == ' ' || token[count] == '>' || token[count] == '<') && (count_quots % 2 == 0 && count_s_quots % 2 == 0)) {
        break;
      }
      if (token[count] == '\'') {
        count_s_quots++;
        count++;
      }
      if (token[count] == '\"') {
        count_quots++;
        count++;
      }
      count++;
    }
    new_size = count;
    dst = ft_strndup(token, new_size);
  }else {
    dst = malloc(sizeof(char) * (size + 1));
    if (!dst)
      return NULL;
    while (token[count]) {
      if (count == 0) {
        while (token[count] == ' ' && token[count]) {
          count++;
        }
        if (token[count] != ' ' && token[count] != '\0') {
          while (index <= size) {
            if (token[count] == '>' || token[count] == '<') {
              // if (index == 0 && (token[count] == '>' || token[count] == '<')) {
              //   char *tmp = ft_strdup(ft_strndup(&token[count], get_rederection_length(&token[count])));
              //   dst[index++] = tmp[0];
              //   dst[index++] = tmp[1];
              // }
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
  }
  // dst[index] = 0;
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
  int count_quots = 0;
  int count_squots = 0;
  while (cmd[size]) {
    if (cmd[size] == ' ' && (count_quots % 2 == 0 && count_squots % 2 == 0))
      break;
    if (cmd[size] == '\"')
      count_quots++;
    if (cmd[size] == '\'')
      count_squots++;
    size++;
  }
  // printf("size = %d\n", size);
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
// 'hello $HOME'
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
          count = 0;
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
    if (*arg && arg[0] == '$' ) {
      if (!arg[1]) {
        dst[index - 1] = ft_strjoin(dst[index - 1], "$");
        break;
      }
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

int is_bettwen_double(char *arg) {
  int count = 0;
  while (arg[count]) {
    if (arg[count] == '$')
      return 1;
    if (arg[count] == '\'') {
      return 0;
    }else if (arg[count] == '\"') {
      return 1;
    }
    count++;
  }
  return 1;
}

char **get_new_arg(char **dst, char **args, int size, t_minishell *minishell) {
  int count = 0;
  int index = 0;
  (void)size;
  while (args[count]) {
    if (is_dolar_var(args[count]) &&  is_bettwen_double(args[count])) {
      // printf("ARGG => %s\n", args[count]);
      // args[count] = remove_quots(args[count]);
      char *mini_dst =  remove_quots(expand(args[count], minishell));
      if (*mini_dst) {
        dst[index] = mini_dst;
        index++;
      }
    }else {
      dst[index] = remove_quots(args[count]);
      index++;
    }
    count++;
  }
  dst[index] = NULL;
  // count = 0;
  // while (dst[count]) {
  //   printf("[%s]\n", dst[count]);
  //   count++;
  // }
  return dst;
}

char *update_cmd_from_quotes(char *cmd) {
    int len = 0;
    int count_s_quot = 0;
    int count_d_quot = 0;
    int count = 0;
    int index = 0;
    while (cmd[count]) {
        if (cmd[count] == '\"' && count_s_quot == 0) {
          count_d_quot++;
        }
        if (cmd[count] == '\'' && count_d_quot == 0) {
          count_s_quot++;
        }
        count++;
    }
    len = count;
    count_d_quot = 0;
    count_s_quot = 0;
    char *new_cmd = malloc(sizeof(char) * (len + 1));
    count = 0;
    while (cmd[count]) {
        if (cmd[count] == '\'' && count_d_quot == 0) {
          count_s_quot++;
        }
        else if (cmd[count] == '\"' && count_s_quot == 0) {
          count_d_quot++;
        }
        else {
          new_cmd[index] = cmd[count];
          index++;
        }
        count++;
    }
    new_cmd[index] = '\0';
    return new_cmd;
}

int length_new_cmd(char *arg) {
  int count = 0;
  int count_s_quot = 0;
  int count_d_quot = 0;
  while (arg[count]) {
    if (arg[count] == '\'') {
      count_s_quot++;
    }
    if (arg[count] == '\"') {
      count_d_quot++;
    }
    if ((arg[count] == ' ' || arg[count] == '>' || arg[count] == '<') && (count_s_quot % 2 == 0 && count_d_quot % 2 == 0)) {
      break;
    }
    count++;
  }
  return count;
}

int is_commande_var(t_parsing *shell, t_minishell *mini, int index) {
 
  char **cmd = ft_split(shell->cmd, ' ');
  if (count_length_two_arr(cmd) > 0) {
    shell->cmd = cmd[0];
    char **new_args = cmd + 1;
    shell->args = join_tables(new_args, shell->args);
  }else {
    return 0;
  }
  (void)mini;
  (void)index;
  return 0;
}

int is_redirect(char *red) {
  if (str_cmp(red, ">") || str_cmp(red, ">>") || str_cmp(red, "<") || str_cmp(red, "<<")) {
    return 1;
  }
  return 0;
}

int count_redirection_and_files(char **args) {
  int count = 0;
  int count_returend = 0;
  while (args[count]) {
    if (is_redirect(args[count])) {
      if (args[count + 1]) {
        count_returend++;
      }
      count_returend++;
    }
    count++;
  }
  if (count_returend == 0) {
    return 1;
  }
  return count_returend;
}


int count_argment_without_red(char **args) {
  int count = 0;
  int reterned_count = 0;
  while (args[count]) {
    if (count == 0 && !is_redirect(args[count])) {
      reterned_count++;
    }else { 
      if (count - 1 >= 0 && !is_redirect(args[count - 1]) && !is_redirect(args[count])) {
        reterned_count++;
      }
    }
    count++;
  }
  return reterned_count;
}

char** sort_args(char** oldargs) {
 char **dst = malloc(sizeof(char *) * (count_redirection_and_files(oldargs) + 1));
 int index = 0;
  int count = 0;
  while (oldargs[count]) {
    if (is_redirect(oldargs[count])) {
      dst[index] = oldargs[count];
      index++;
      count++;
      if (!oldargs[count])
        break;
      if (oldargs[count]) {
        dst[index] = oldargs[count];
        index++;
      }
    }
    if (!*oldargs[count]) {
      break;
    }
    count++;
  }
  dst[index] = NULL;
  char **dstTwo = malloc(sizeof(char *) * (count_argment_without_red(oldargs) + 1));
  index = 0;
  count = 0;
  while (oldargs[count]) {
    if (count == 0 && !is_redirect(oldargs[count])) {
      dstTwo[index] = oldargs[count];
      index++;
    }else {
      if (count - 1 >= 0 && !is_redirect(oldargs[count - 1]) && !is_redirect(oldargs[count])) {
        dstTwo[index] = oldargs[count];
        index++;
      }
    }
    count++;
  }
  dstTwo[index] = NULL;
  return join_tables(dstTwo, dst);
}

int is_quot_in_cmd(char *cmd) {
  int count = 0;
  while (cmd[count]) {
    if (cmd[count] == '\'' || cmd[count] == '\"') {
      return 1;
    }
    count++;
  }
  return 0;
}

//intialis the structer
void init_and_split(t_minishell *minishell, char *token, int pos) {
  char *get_cmd_ = get_cmd_with_fixes_size(token, commande_length(token));
  char *rem_sp = rm_spaces_from_cmd(get_cmd_);
  minishell->parsing[pos].cmd = rem_sp;
  int count = 0;
  // if (is_dolar_var(minishell->parsing[pos].cmd) && !str_cmp(minishell->parsing[pos].cmd, "$"))
  //   minishell->parsing[pos].cmd = expande_cmd(minishell->parsing[pos].cmd, minishell);
  // if (is_q_in_cmd(minishell->parsing[pos].cmd)) 
  //   minishell->parsing[pos].cmd = update_cmd_from_quotes(minishell->parsing[pos].cmd);
  token = &token[skip_spaces(token)];
  token = ft_strdup(token + (length_new_cmd(token)));
  count = 0;
  if (is_quot_in_cmd(minishell->parsing[pos].cmd)) {
    minishell->parsing[pos].is_cmd_in_quotes = 1;
  }else {
    minishell->parsing[pos].is_cmd_in_quotes = 0;
  }
  char **dst = split_commande_args(token, minishell);
  if (is_redirec_output(dst)) {
    dst = sort_args(dst);
    if ((!ft_strlen(minishell->parsing[pos].cmd) || is_redirect(minishell->parsing[pos].cmd)) && !is_redirect(dst[0])) {
      minishell->parsing[pos].cmd = dst[0];
      dst = dst + 1;
    }
  }
  minishell->parsing[pos].args = dst;
  if (is_dolar_var(minishell->parsing[pos].cmd) &&  is_bettwen_double(minishell->parsing[pos].cmd)) {
      minishell->parsing[pos].cmd = remove_quots(expand(minishell->parsing[pos].cmd, minishell));
      is_commande_var(&minishell->parsing[pos], minishell, pos);
      minishell->parsing[pos].is_cmd_var = 1;
   }else {
      minishell->parsing[pos].cmd = remove_quots(minishell->parsing[pos].cmd);
      minishell->parsing[pos].is_cmd_var = 0;
  }
  
  // int size_new_vars = count_length_two_arr(minishell->parsing[pos].args);
  // char **new_arg = malloc(sizeof(char *) * (size_new_vars + 1));
  // minishell->parsing[pos].args = get_new_arg(new_arg,minishell->parsing[pos].args, size_new_vars, minishell);
  // count = 0;
  // printf("cmd2 = %s\n", minishell->parsing[pos].cmd);
  // while (minishell->parsing[pos].args[count]) {
  //   printf("args[%d] = %s\n", count, minishell->parsing[pos].args[count]);
  //   count++;
  // }
}

int parsing_input(t_minishell *minishell, char *line) {
  char **tokens = new_tokens(line);
  if (tokens == NULL)
    return 1;
  int count = 0; 
  int size = ft_count_tokens(line) * 2;
  minishell->n_cmd = size;
  minishell->parsing = malloc(sizeof(t_parsing) * (size + 1));
  while (count <= size) {
    init_and_split(minishell, tokens[count], count);
    count++;
  }
  return 0;
}
