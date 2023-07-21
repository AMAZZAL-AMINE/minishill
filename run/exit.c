/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:22:04 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/21 17:36:07 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_not_num(char *arg)
{
	int	count;

	count = 0;
	while (arg[count])
	{
		if (!ft_isdigit(arg[count]) && (arg[count] != '-' && arg[count] != '+'))
			return (1);
		count++;
	}
	return (0);
}

void	num_arg_err(t_parsing *shell, int status, int is_exit)
{
	captur.exit_status = status;
	ft_putstr_fd("minishell: exit: ", 2);
	ft_putstr_fd(shell->args[0], 2);
	ft_putstr_fd(": numeric argument required\n", 2);
	if (is_exit)
		exit(captur.exit_status);
	return ;
}

void	too_many_arg(void)
{
	captur.exit_status = 1;
	ft_putstr_fd("minishell: exit: too many arguments\n", 2);
	return ;
}

void	exit_shell(t_parsing *shell, t_minishell *minishell, \
	int index, int size)
{
	if ((index - 1 > 0 && str_cmp(minishell->parsing[index - 1].cmd, "|")) \
		|| (index + 1 <= size \
		&& str_cmp(minishell->parsing[index + 1].cmd, "|")))
	{
		if (shell->args[0] && is_not_num(shell->args[0]))
			return (num_arg_err(shell, 255, 0));
		else if (count_length_two_arr(shell->args) > 1)
			return (too_many_arg());
		captur.exit_status = 0;
		return ;
	}
	if (shell->args[0] && is_not_num(shell->args[0]))
		num_arg_err(shell, 255, 1);
	else if (count_length_two_arr(shell->args) > 1)
		return (too_many_arg());
	if (!shell->args[0])
		exit(captur.exit_status);
	captur.exit_status = 0;
	exit(ft_atoi(shell->args[0]));
}
