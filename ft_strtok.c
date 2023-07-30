/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:45:44 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/30 22:27:01 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strjoin_tok(char const *s1, char const *s2)
{
	int		count;
	int		dstcount;
	char	*distination;

	count = 0;
	dstcount = 0;
	if (!s1 && s2)
	{
		return (NULL);
	}
	distination = malloc(ft_strlen(s1) + (ft_strlen(s2) + 1));
	if (!distination)
		return (0);
	while (s1[count])
	{
		distination[dstcount++] = s1[count++];
	}
	count = 0;
	while (s2[count])
	{
		distination[dstcount++] = s2[count++];
	}
	distination[dstcount] = 0;
	return (distination);
}

char	*ft_strndup_two(char const *str, size_t max)
{
	size_t	index;
	char	*dst;

	index = 0;
	dst = malloc(sizeof(char) * (max + 1));
	if (!dst)
	{
		return (0);
	}
	while (str[index] && index < max)
	{
		dst[index] = str[index];
		index++;
	}
	dst[index] = '\0';
	return (dst);
}

size_t	ft_silter(char const *str, char crt)
{
	size_t	index;
	size_t	word_count;

	index = 0;
	word_count = 0;
	while (str[index])
	{
		if ((index == 0 && str[index] != crt)
			|| (str[index] == crt && str[index + 1] && str[index + 1] != crt))
		{
			word_count++;
		}
		index++;
	}
	return (word_count);
}

char	**ft_strtok(char const *s, char c)
{
	char	**strlist;
	size_t	rslt;
	size_t	count;
	size_t	str_count;

	count = 0;
	str_count = 0;
	if (!s)
		return (0);
	strlist = malloc(sizeof(char *) * (ft_silter(s, c) + 1));
	if (!strlist)
		return (0);
	while (count < ft_silter(s, c) && s[str_count])
	{
		while (s[str_count] == c)
			str_count++;
		rslt = str_count;
		while (s[str_count] != c && s[str_count] != '\0')
			str_count++;
		strlist[count] = ft_strndup_two(&s[rslt], str_count - rslt);
		count++;
	}
	strlist[count] = 0;
	return (strlist);
}
