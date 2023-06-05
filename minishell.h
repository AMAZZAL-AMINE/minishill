/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:10:39 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/03 14:49:30 by mamazzal         ###   ########.fr       */
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

typedef struct t_shell {
  char *cmd;
  char **args;
  char *buffer;
} t_shell;

char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);
#endif