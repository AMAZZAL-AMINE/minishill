/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value_with_no_moure_then_space.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:51:34 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/27 21:06:12 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_new_value_size(char *value)
{
	int	count;
	int	size;

	count = 0;
	size = 0;
	while (value[count])
	{
		if (value[count] != ' ')
		{
			size++;
		}
		else if (value[count] == ' ')
		{
			if (count != 0 && value[count + 1] && value[count + 1] != ' ')
				size++;
		}
		count++;
	}
	return (size);
}

char	*get_value_with_no_moure_then_space(char *value)
{
	int		count;
	int		size;
	char	*dst;

	count = 0;
	size = get_new_value_size(value);
	dst = malloc(sizeof(char) * (size + 1));
	count = 0;
	size = 0;
	while (value[count])
	{
		if (value[count] != ' ')
			dst[size++] = value[count];
		else if (value[count] == ' ')
		{
			if (count != 0 && value[count + 1] && value[count + 1] != ' ')
				dst[size++] = value[count];
		}
		count++;
	}
	if (dst[0] == ' ')
		dst = dst + 1;
	dst[size] = '\0';
	return (dst);
}
