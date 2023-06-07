/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:30:08 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/06 15:30:31 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strncmp(const char *str1, const char *str2, size_t max)
{
	size_t			count;
	unsigned char	*s1;
	unsigned char	*s2;

	count = 0;
	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	while ((s1[count] != '\0' || s2[count] != '\0') && count < max)
	{
		if (s1[count] > s2[count])
		{
			return (1);
		}
		else if (s1[count] < s2[count])
		{
			return (-1);
		}
		count++;
	}
	return (0);
}
