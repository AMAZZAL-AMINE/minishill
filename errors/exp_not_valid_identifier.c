/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_not_valid_identifier.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:27:58 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/21 11:40:11 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_not_valid(char *arg)
{
	int	count;

	count = 0;
	if (ft_isdigit(arg[0]))
		return (1);
	while (arg[count])
	{
		if (!ft_isalpha(arg[count]) && arg[count] != '_' \
			&& !ft_isdigit(arg[count]))
			return (1);
		count++;
	}
	return (0);
}

int	exp_not_valid_identifier(char *arg)
{
	if (ft_strlen(arg) == 0)
	{
		captur.exit_status = 0;
		return (0);
	}
	if (is_not_valid(arg))
	{
		captur.exit_status = 1;
		ft_putstr_fd("minishell: export: `", 2);
		ft_putstr_fd(arg, 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
		return (1);
	}
	captur.exit_status = 0;
	return (0);
}
