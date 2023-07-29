/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:28:29 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/29 18:56:23 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	dst_count;
	char	*distination;

	dst_count = 0;
	if (!s)
		return (NULL);
	if (ft_strlen((char *)s) < len)
		len = ft_strlen(s) - start;
	if (start >= ft_strlen((char *)s))
	{
		distination = ft_malloc(1, 0, ALLOC, 0);
		distination[0] = '\0';
		return (distination);
	}
	distination = ft_calloc(len + 1, sizeof(char));
	if (!distination)
		return (0);
	while (s[start + dst_count] && len--)
	{
		distination[dst_count] = s[start + dst_count];
		dst_count++;
	}
	distination[dst_count] = '\0';
	return (distination);
}
