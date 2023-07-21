/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_cmd_redirected.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 12:52:09 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/21 11:24:17 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_cmd_redirected(char *cmd)
{
	if (str_cmp(cmd, ">") || str_cmp(cmd, ">>") \
		|| str_cmp(cmd, "<") || str_cmp(cmd, "<<"))
		return (1);
	return (0);
}
