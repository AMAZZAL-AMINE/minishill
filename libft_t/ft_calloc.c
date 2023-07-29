/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 13:03:13 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/29 18:38:44 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*sr;

	if (count == SIZE_MAX || size == SIZE_MAX)
	{
		return (0);
	}
	sr = ft_malloc(count * size, 0, ALLOC, 0);
	if (!sr)
	{
		return (0);
	}
	ft_bzero(sr, count * size);
	return (sr);
}
