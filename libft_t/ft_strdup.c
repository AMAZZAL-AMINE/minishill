/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:14:57 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/29 18:43:25 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*distination;
	size_t	index;

	distination = ft_malloc(ft_strlen(str) + 1, 0, ALLOC, 0);
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
