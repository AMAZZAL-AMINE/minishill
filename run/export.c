/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:05:53 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/17 13:45:50 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int search_is_already_exported(char *name, t_minishell *shell) {
  int count = 0;
  while (count < shell->n_var_env) {
    if (str_cmp(name, shell->env[count].name)) {
      return 1;
    }
    count++;
  }
  return 0;
}

void update_exported_var(char *content, t_minishell *shell, char *name, char *value) {
  int count = 0;
  while (count < shell->n_var_env) {
    if (str_cmp(name, shell->env[count].name)) {
     if (ft_strchr(content, '=') != NULL) {
      shell->env[count].is_haver_equal = 1;
      shell->env[count].value = value;
     }
    }
    count++;
  }
  count = 0;
  while (count < shell->n_var_env) {
    char **splited = ft_split(shell->env_v[count], '=');
    if (str_cmp(name, splited[0])) {
      if (ft_strchr(content, '=') != NULL) {
        shell->env_v[count] = ft_strjoin(ft_strjoin(name, "="), value);
        return;
      }
    }
    count++;
  }
  return;
}

int export_to_en(t_minishell *shell, char *name, char *value, char *content) {
  int count = 0;
  t_env *envs = malloc(sizeof(t_env) * (shell->n_var_env + 1));
  if (exp_not_valid_identifier(name)) {
    captur.exit_status = 1;
    return 1;
  }
  if (search_is_already_exported(name, shell)) {
    update_exported_var(content, shell, name, value);
    return 0;
  }
  while (count < shell->n_var_env) {
    envs[count] = shell->env[count];
    count++;
  }
  if (ft_strchr(content, '=') != NULL) {
    envs[count].is_haver_equal = 1;
  }
  envs[count].name = name;
  envs[count].value = value;
  shell->env = envs;
  
  char **new_env = malloc(sizeof(char *) * (shell->n_var_env + 2));
  count = 0;
  while (count < shell->n_var_env) {
    new_env[count] = shell->env_v[count];
    count++;
  }
  if (ft_strchr(content, '=') != NULL) {
    new_env[count] = ft_strjoin(ft_strjoin(name, "="), value);
  }else {
    new_env[count] = name;
  }
  shell->n_var_env += 1;
  shell->env_v = new_env;
  return 0;
}

void get_exported_vars(t_minishell *shell) {
  int count = 0;
  int is_printed_quit = 0;
  while (count < shell->n_var_env) {
      int index = 0;
      printf("declare -x ");
      while (shell->env_v[count][index]) {
        if (!shell->env_v[count][index + 1] && shell->env_v[count][index] == '$')
          printf("\\");
        printf("%c", shell->env_v[count][index]);
        if (shell->env_v[count][index] == '=' && !is_printed_quit) {
          is_printed_quit = 1;
          printf("\"");
        }
        index++;
      }
      if (is_printed_quit) {
        printf("\"\n");
      }else {
        printf("\n");
      }
      is_printed_quit = 0;
    count++;
  }
}

char *get_value_with_no_moure_then_space(char *value) {
  int count = 0;
  int size = 0;
  while (value[count]) {
    if (value[count] != ' ') {
      size++;
    }else if (value[count] == ' ') {
      if (count != 0 && value[count + 1] && value[count + 1] != ' ')
        size++;
      }
    count++;
  }
  char *dst = malloc(sizeof(char) * (size + 1));
  count = 0;
  size = 0;
  while (value[count]) {
    if (value[count] != ' ') {
      dst[size++] = value[count];
    }else if (value[count] == ' ') {
      if (count != 0 && value[count + 1] && value[count + 1] != ' ')
        dst[size++] = value[count];
    }
    count++;
  }
  if (dst[0] == ' ')
    dst = dst + 1;
  dst[size] = '\0';
    return dst;
}

void export(t_parsing *shell, t_minishell *ms) {
  int count = 0;
  char *var = NULL;
  char *value = NULL;
  int   return_status = 0;
  char **arg_splited;
 
  int is_last_equal = 0;
  char **new_args  = shell->args;

  if (!*new_args) {
    get_exported_vars(ms);
  }else {
    while (new_args[count]) {
      if (new_args[count][ft_strlen(new_args[count]) - 1] == '=')
        is_last_equal = 1;
       if (str_cmp(new_args[count], "=") || new_args[count][0] == '=') {
        if (new_args[count][0] == '=')
          var = new_args[count];
        else
          var = "=";
      }else {
        arg_splited = ft_split(new_args[count], '=');
        var = arg_splited[0]; 
      }
      value  = new_args[count] + (ft_strlen(var) + 1);
      if (!value) {
        value = "";
      }
      value = get_value_with_no_moure_then_space(value);
      if (export_to_en(ms, var, value, new_args[count]) == 1)
        return_status = 1;
      count++;
    }
  }
  if (return_status == 1)
    captur.exit_status = 1;
  else
    captur.exit_status = 0;
}
