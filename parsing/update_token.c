/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 20:15:13 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/11 20:17:07 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char *update_token(char *token, int size) {
  int count = 0;
  int index = 0;
  while (token[count]) {
    if (count == 0) {
      while (token[count] == ' ' && token[count]) {
        count++;
      }
      if (token[count]) {
        while (index < size) {
          index++;
          count++;
        }
        break;
      } 
    }
  }
  return (ft_strdup(token + count));
}