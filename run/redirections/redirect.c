/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 21:03:03 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/22 23:37:54 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void redirect(int is_path, t_parsing *shell, char **content) {
    if (search_for_heardoc(content))
      herdoc(content);
    int count = 0;
    while (content[count]) {
      if (str_cmp(">", content[count]))
        redirect_output(content, count);
      if (str_cmp("<", content[count]))
        redirect_input(content, count);
      if (str_cmp(">>", content[count]))
        appned(content, count);
      count++;
    }
  (void)is_path;
  (void)shell;
}
