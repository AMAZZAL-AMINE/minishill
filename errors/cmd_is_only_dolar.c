/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_is_only_dolar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 11:24:30 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/21 11:32:23 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	cmd_is_only_dolar(char *cmd)
{
	if (str_cmp(cmd, "$"))
		return (1);
	return (0);
}
