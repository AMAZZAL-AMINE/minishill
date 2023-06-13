/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:27:12 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/13 21:28:11 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void clear(void)
{
  printf("\033[2J");       // Clear entire screen
  printf("\033[0;0f");    // Move cursor to the top-left corner
}