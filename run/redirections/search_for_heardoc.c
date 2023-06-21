/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_for_heardoc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:25:08 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/21 12:25:16 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int search_for_heardoc(char **content) {
  int count = 0;
  while (content[count]) {
    if (str_cmp("<<", content[count]))
      return (1);
    count++;
  }
  return (0);
}