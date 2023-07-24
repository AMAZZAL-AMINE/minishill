/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:14:57 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/24 21:20:33 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*distination;
	size_t	index;

	distination = malloc(ft_strlen(str) + 1);
	if (!distination)
	{
		return (0);
	}
	index = 0;
	while (str[index])
	{
		distination[index] = str[index];
		index++;
	}
	distination[index] = '\0';
	return (distination);
}
