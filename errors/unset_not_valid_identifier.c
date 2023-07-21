/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_not_valid_identifier.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:52:42 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/21 11:56:21 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_not_valid_two(char *arg)
{
	if ((arg[ft_strlen(arg) - 1] >= 35 && arg[ft_strlen(arg) - 1] <= 38) \
		|| arg[ft_strlen(arg) - 1] == 33)
		return (1);
	else if ((arg[ft_strlen(arg) - 1] >= 40 && arg[ft_strlen(arg) - 1] <= 47))
		return (1);
	return (0);
}

int	check_first_two(char *arg)
{
	if (!ft_isalpha(arg[0]) && arg[0] != '_')
		return (1);
	return (0);
}

int	unset_not_valid_identifier(char *arg)
{
	if (ft_strlen(arg) == 0)
	{
		captur.exit_status = 0;
		return (0);
	}
	if (is_not_valid_two(arg) || check_first_two(arg))
	{
		captur.exit_status = 1;
		ft_putstr_fd("minishell: unset: `", 2);
		ft_putstr_fd(arg, 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
		return (1);
	}
	captur.exit_status = 0;
	return (0);
}
