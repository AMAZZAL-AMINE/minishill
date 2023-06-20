/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:05:53 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/20 13:00:39 by mamazzal         ###   ########.fr       */
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

void export_to_en(t_minishell *shell, char *name, char *value, char *content) {
  int count = 0;
  t_env *envs = malloc(sizeof(t_env) * (shell->n_var_env + 1));

  if (search_is_already_exported(name, shell)) {
    update_exported_var(content, shell, name, value);
    return;
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
  return;
}

void get_exported_vars(t_minishell *shell) {
  int count = 0;
  int is_printed_quit = 0;
  while (count < shell->n_var_env) {
      int index = 0;
      printf("declare -x ");
      while (shell->env_v[count][index]) {
        printf("%c", shell->env_v[count][index]);
        if (shell->env_v[count][index] == '=') {
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
      is_printed_quit= 0;
    count++;
  }
  return;
}

void export(t_parsing *shell, t_minishell *ms) {
  int count = 0;
  char *var = NULL;
  char *value = NULL;
  char **arg_splited;
  if (shell->args[0] == NULL) {
    get_exported_vars(ms);
    return;
  }
  while (shell->args[count]) {
    arg_splited = ft_split(shell->args[count], '=');
    var = arg_splited[0];
    value  = arg_splited[1];
    if (value == NULL) {
      value = "";
    }
    export_to_en(ms, var, value, shell->args[count]);
    count++;
  }
  return;
}
