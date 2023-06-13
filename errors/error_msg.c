/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:54:23 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/13 14:51:53 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void error_message(char *msg, int free_flag, char *line) {
  printf("\033[0;31m");
  printf("Error : %s\n", msg);
  printf("\033[0m");
  if (free_flag) {
    free(line);
  }
  exit(1); 
}
