/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_double.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 22:27:43 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/30 22:27:54 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_double(char **str)
{
	int	i;

	i = 0;
	if (str[0] && ft_strlen(str[0]) == 0)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
