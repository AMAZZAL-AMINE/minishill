/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambiguoys_utilis_p2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:21:59 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/22 15:22:29 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_var_between_quot_ambiguous(char *arg)
{
	int	count;
	int	count2;

	count = 0;
	count2 = 0;
	while (arg[count])
	{
		if (arg[count] == '\"')
			count2++;
		if (arg[count] == '$' && count2 % 2 != 0)
			return (1);
		count++;
	}
	return (0);
}

int	is_only_dolar(char c, char c_next)
{
	if (c == '$' && (!ft_isalpha(c_next) \
		&& !ft_isdigit(c_next) && c_next != '_' \
		&& c_next != '?' && c_next != '@'))
		return (1);
	return (0);
}

int	is_arobase(char c, int grep_size, char *arg, int count)
{
	if (c && (c == '@' \
		|| ft_isdigit(c)))
		grep_size = 1;
	else
		grep_size = ft_get_grepe_size_ambiguous(arg + count);
	return (grep_size);
}
