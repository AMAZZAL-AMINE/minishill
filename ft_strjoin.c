/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:09:31 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/02 18:06:00 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t ft_strlen(char *str)
{
  size_t count;

  count = 0;
  while (str[count])
  {
   count++; 
  }
  return count;
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		c;
	char	*str;

	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		s1[0] = 0;
	}
	i = 0;
	c = 0;
	if (s1)
	{
		while (s1[i] != '\0')
		{
			str[i] = s1[i];
			i++;
		}
		while (s2[c] != '\0')
			str[i++] = s2[c++];
		str[i] = '\0';
	}
	// free(s1);
	return (str);
}