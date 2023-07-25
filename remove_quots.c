/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quots.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 10:17:36 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/25 23:17:15 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_quots(char *arg)
{
	int	count;
	int	count_quots;

	count = 0;
	count_quots = 0;
	while (arg[count])
	{
		if (arg[count] == '\"')
			count_quots++;
		count++;
	}
	return (count - count_quots);
}

int	dst_size(char *arg)
{
	int		count_s_quot;
	int		count_d_quot;
	int		count;

	count = 0;
	count_s_quot = 0;
	count_d_quot = 0;
	while (arg[count])
	{
		if (arg[count] == '\"' && count_s_quot % 2 == 0)
			count_d_quot++;
		else if (arg[count] == '\'' && count_d_quot % 2 == 0)
			count_s_quot++;
		count++;
	}
	return (count);
}

char	*remove_quots(char *arg)
{
	int		count_s_quot;
	int		count_d_quot;
	int		count;
	int		index;
	char	*new_arg;

	count = dst_size(arg);
	index = 0;
	count_d_quot = 0;
	count_s_quot = 0;
	new_arg = malloc(sizeof(char) * (count + 2));
	count = 0;
	while (arg[count])
	{
		if (arg[count] == '\'' && count_d_quot % 2 == 0)
			count_s_quot++;
		else if (arg[count] == '\"' && count_s_quot % 2 == 0)
			count_d_quot++;
		else
			new_arg[index++] = arg[count];
		count++;
	}
	new_arg[index] = '\0';
	return (new_arg);
}
