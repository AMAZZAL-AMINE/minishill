/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambiguoys_utilis_p1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 13:15:45 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/22 13:17:07 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_dolar_between_quot(char *str)
{
	int	count;
	int	count2;

	count = 0;
	count2 = 0;
	while (str[count])
	{
		if (str[count] == '\"')
			count2++;
		if (str[count] == '$' && count2 % 2 != 0)
			return (1);
		count++;
	}
	return (0);
}

int	check_prev_str(char *str, int index)
{
	while (index)
	{
		if (str[index] != ' ')
		{
			return (1);
		}
		index--;
	}
	return (0);
}

int	check_next_str(char *str, int index)
{
	while (str[index])
	{
		if (str[index] != ' ')
		{
			return (1);
		}
		index++;
	}
	return (0);
}

int	is_btween_word_space(char *str)
{
	int	count;

	count = 0;
	while (str[count])
	{
		if (count > 0 && str[count] == ' ' \
			&& (check_prev_str(str, count) && check_next_str(str, count)))
			return (1);
		count++;
	}
	return (0);
}
