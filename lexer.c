/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:16:37 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/07 20:27:46 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h" 


int count_cmds_pip(t_cmd_table *table) {
  int count = 0;
  int count_pip = 0;
  while (table->input[count]) {
    if (table->input[count] == '|') {
      count_pip++;
    }
    count++;
  }
  return count_pip;
}

int count_args(char **table) {
  int count = 0;
  while (table[count]) {
    count++;
  }
  return count;
}

int ft_strlen_without_dq_sq(char *str) {
  int count = 0;
  int counter = 0;
  while (str[count]) {
    if (str[count] == '\"' || str[count] == '\'') {
      counter++;
    }
    count++;
  }
  return (count - counter);
}

char *splite_from_dq_sq(char *str) {
  int count = 0;
  int index = 0;
  char *new_str = malloc(sizeof(char) * (ft_strlen_without_dq_sq(str) + 1));
  while (str[count]) {
    if (str[count] != '\'' || str[count] != '\"') {
      new_str[index] = str[count];
      index++;
    }
    count++;
    return new_str;
  }
  return NULL;
}
void  lxr(t_cmd_table *table) {
  table->lexer = malloc(sizeof(t_lexer) * count_cmds_pip(table));
  int count = 0;
  int index = 0;
  while (count <= count_cmds_pip(table)) {
    table->lexer[count].token = ft_split(table->input, '|')[count];
    count++;
  }

  char **str = NULL;
  count = 0;
  while (count < count_args(ft_split(table->input, '|'))) {
      index = 0;
      str = ft_split(table->lexer[count].token, ' ');
      table->lexer[count].cmd = str[0];
      table->lexer[count].args = ft_split(table->lexer[count].token, ' ');
      count++;
  }
}


void print_table(t_cmd_table *table) {
  lxr(table);
  printf("\n");
  printf("------------------------------------\n");
  printf("CMD\t\t|\t\tARGS\n");
  printf("------------------------------------\n");
  int count = 0;
  int index = 0;
  while (count <= count_cmds_pip(table)) {
    index = 1;
    printf("%s\t\t|\t\t", table->lexer[count].cmd);
    while (table->lexer[count].args[index]) {
      printf("%s ", table->lexer[count].args[index]);
      index++;
    }
    printf("\n");
    count++;
  }
  printf("\n");
  return ;
}