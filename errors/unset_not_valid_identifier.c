/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_not_valid_identifier.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:52:42 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/12 12:55:45 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int is_not_valid_two(char *arg) {
  if ((arg[ft_strlen(arg) - 1] >= 35 && arg[ft_strlen(arg) - 1] <= 38) || arg[ft_strlen(arg) - 1] == 33) {
    return 1;
  }else if ((arg[ft_strlen(arg) - 1] >= 40 && arg[ft_strlen(arg) - 1] <= 47)) {
    return 1;
  }
  return 0;
}

int unset_not_valid_identifier(char *arg) {
    if (is_not_valid_two(arg)) {
      if (arg[ft_strlen(arg) - 1] == 40 ||  arg[ft_strlen(arg) - 1] == 41) {
          ft_putstr_fd("minishell: syntax error near unexpected token '", 2);
          ft_putchar_fd(arg[ft_strlen(arg) - 1], 2);
          ft_putstr_fd("'\n", 2);
          captur.exit_status = 1;
        }else {
          captur.exit_status = 1;
          ft_putstr_fd("minishell: unset: `", 2);
          ft_putstr_fd(arg, 2);
          ft_putstr_fd("': not a valid identifier\n", 2);
        }
      return 1;
    }
  return 0;
}
