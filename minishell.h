/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:10:39 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/07 20:24:04 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <string.h>
#include <fcntl.h>

typedef struct s_lexer {
  char *cmd;
  char **args;
  char *path;
  char *dq;
  char *sq;
  char *token;
} t_lexer;

typedef struct t_cmd_table {
  char *cmd;
  char **args;
  char *input;
  char pip;
  char *path;
  t_lexer *lexer;
} t_cmd_table;


int run_cmd(t_cmd_table *table);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);
int change_dir(t_cmd_table *table);
int	ft_strncmp(const char *str1, const char *str2, size_t max);
size_t	ft_strlen(const char *str);
int cmd_echo(t_cmd_table *table);
int	ft_isdigit(int digit);
int	ft_isalpha(int alpha);
int ft_ispip(char c);
char	*ft_strdup(const char *str);
int is_db_q(char c);
int is_s_q(char c);
void  lxr(t_cmd_table *table);
void print_table(t_cmd_table *table);
#endif