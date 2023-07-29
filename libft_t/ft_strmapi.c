/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 09:53:58 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/29 18:43:47 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	count;
	char			*result;

	count = 0;
	if (s == NULL || f == NULL)
	{
		return (0);
	}
	result = ft_malloc(ft_strlen(s)+ 1 * sizeof(char), 0, ALLOC, 0);
	if (!result)
		return (NULL);
	while (s[count])
	{
		result[count] = f(count, s[count]);
		count++;
	}
	result[count] = '\0';
	return (result);
}
