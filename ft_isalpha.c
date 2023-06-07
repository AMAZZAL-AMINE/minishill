/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:27:08 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/07 12:16:05 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_isalpha(int alpha)
{
	if ((alpha >= 65 && alpha <= 90) || (alpha >= 97 && alpha <= 122))
	{
		return (1);
	}
	return (0);
}
