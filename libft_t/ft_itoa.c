/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 07:48:38 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/29 18:42:35 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_nbr(int number)
{
	int	count_len;

	count_len = 0;
	if (number <= 0)
	{
		count_len++;
	}
	while (number != 0)
	{
		count_len++;
		number = number / 10;
	}
	return (count_len);
}

char	*ft_itoa(int number)
{
	int		nb_ln;
	long	nbr;
	char	*string;

	nbr = number;
	nb_ln = ft_count_nbr(number);
	string = ft_malloc(nb_ln + 1 * sizeof(char), 0, ALLOC, 0);
	if (!string)
	{
		return (NULL);
	}
	if (nbr == 0)
		string[0] = '0';
	if (nbr < 0)
	{
		string[0] = '-';
		nbr = -nbr;
	}
	string[nb_ln--] = '\0';
	while (nbr != 0)
	{
		string[nb_ln--] = nbr % 10 + 48;
		nbr = nbr / 10;
	}
	return (string);
}
