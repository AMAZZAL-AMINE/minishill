/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 11:01:26 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/19 14:20:16 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void pwd(t_parsing *shell) {
  char *buff;
  buff = getcwd(NULL, 0);
  if (buff == NULL) {
    printf("PWD: error");
    exit(2);
  }

  printf("%s\n", buff);
  (void)shell;
  free(buff);
}