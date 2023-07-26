/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 20:16:43 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/26 17:46:53 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ITERM_SESSION_ID

#include "minishell.h"

char	*get_value_from_env(char **conten, char *what)
{
	int	count;

	count = 0;
	while (conten[count])
	{
		if (ft_strnstr(conten[count], what, ft_strlen(what)) != NULL)
			return (conten[count]);
		count++;
	}
	return ("");
}


