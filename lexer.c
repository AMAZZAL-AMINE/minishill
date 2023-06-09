/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:16:37 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/09 18:23:33 by mamazzal         ###   ########.fr       */
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
int count_quots(char *str) {
  int count = 0;
  int count_q = 0;
  if (!str)
    return 0;
  while(str[count]) {
    if (str[count] == '\'' || str[count] == '\"') {
      count_q++;
    }
    count++;
  }
  return (count - count_q);
}

char *sp_double_single_quts(char *str) {
  int count = 0;
  int index = 0;
  char *new_str = malloc(sizeof(char) * (count_quots(str) + 1));
  while (str[count]) {
    if (str[count] != '\'' && str[count] != '\"') {
      new_str[index] = str[count];
      index++;
    }
    count++;
  }
  new_str[index] = '\0';
  return new_str;
}

int count_cmd_length(char *str) {
  int count = 0;
  while (str[count] == ' ') {
    count++;
  }
  while ((str[count] != '>' && str[count] != ' ' && str[count] != '<') && str[count]) {
    count++;
  }
  return count;
}
//cat < "Makefile" | grep something > outfile | wc -l < outfile
void  lxr(t_cmd_table *table) {
  table->lexer = malloc(sizeof(t_lexer) * count_cmds_pip(table));
  int count = 0;
  int index = 0;
  int nbr_args = 0;
  while (count <= count_cmds_pip(table)) {
    table->lexer[count].token = ft_split(table->input, '|')[count];
    nbr_args++;
    table->count++;
    count++;
  }
  char *input = NULL;
  count = 0;
  int size =  nbr_args;
  while (count < size) {
    index = 0;
    input = sp_double_single_quts(table->lexer[count].token);
    table->lexer[count].cmd = ft_strndup(input, count_cmd_length(input));
    table->lexer[count].args =  filter_args(input + count_cmd_length(input), &table->lexer[count]);
    count++;
  }
}

// void print_table(t_cmd_table *table) {
//   lxr(table);
//   printf("\n");
//   printf("\033[1;33m");
//   printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
//   printf("\t%-23s|%-23s|\t%-23s|\t%-23s|\n", "CMD", "ARGS", "Redirect","File");
//   printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
//   printf("\033[0m");
//   int count = 0;
//   while (count <= count_cmds_pip(table)) {
//     if (table->lexer[count].cmd)
//       printf("\t%-23s|", table->lexer[count].cmd);
//     else
//       printf("\t%-23s|", " NULL");
//     if (table->lexer[count].args)
//       printf("%-23s|", table->lexer[count].args);
//     else
//       printf("\t%-23s|", " NULL");
//     if (table->lexer[count].redirect)
//       printf("\t%-23s|", table->lexer[count].redirect);
//     else
//       printf("\t%-23s|", " NULL");
//     if (table->lexer[count].file)
//       printf("\t%-23s|", table->lexer[count].file);
//     else
//       printf("\t%-23s|", " NULL");
//     printf("\n----------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
//     count++;
//   }
//   printf("\n");
//   return ;
// }

