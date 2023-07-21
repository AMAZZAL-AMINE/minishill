/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:58:48 by mamazzal          #+#    #+#             */
/*   Updated: 2022/09/29 16:58:53 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int alpha)
{
	if (alpha >= 65 && alpha <= 90)
	{
		alpha += 32;
		return (alpha);
	}
	return (alpha);
}