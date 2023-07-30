/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:55:08 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/30 21:31:26 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_print_new_line(char *str)
{
	int	count;

	count = 0;
	if (str[0] == '-')
	{
		count = 1;
		while (str[count] == 'n' && str[count])
			count++;
		if (str[count] == 'n' || str[count] == '\0')
			return (1);
		else
			return (0);
	}
	return (0);
}

void	echo_in_console(char **content)
{
	int	count;

	count = 0;
	while (content[count])
	{
		if (count == 0)
			while (content[count] && is_print_new_line(content[count]))
				count++;
		if (content[count])
		{
			if (content[count + 1])
			{
				write(1, content[count], \
					ft_strlen(content[count]));
				write(1, " ", 1);
			}
			else
				write(1, content[count], ft_strlen(content[count]));
		}
		else
			break ;
		count++;
	}
	if (content[0] == NULL || !is_print_new_line(content[0]))
		write(1, "\n", 1);
}

int	echo_cmd(t_parsing *shell)
{
	echo_in_console(shell->args);
	captur.exit_status = 0;
	return (0);
}
