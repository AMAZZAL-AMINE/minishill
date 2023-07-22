/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utilis_get_exported_vars.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 10:17:17 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/22 12:41:10 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	sp_char(char c)
{
	if (c == '$' \
		|| (c == '\"' \
		|| c == '\\'))
		printf("\\");
}

int	print_first_quot(char c, int is_printed_quit)
{
	if (c == '=' && !is_printed_quit)
	{
		is_printed_quit = 1;
		printf("\"");
	}
	return (is_printed_quit);
}

void	get_exported_vars(t_minishell *shell)
{
	int	count;
	int	is_printed_quit;
	int	index;

	count = 0;
	is_printed_quit = 0;
	while (count < shell->n_var_env)
	{
		index = 0;
		printf("declare -x ");
		while (shell->env_v[count][index])
		{
			sp_char(shell->env_v[count][index]);
			printf("%c", shell->env_v[count][index]);
			is_printed_quit = print_first_quot(shell->env_v[count][index], \
				is_printed_quit);
			index++;
		}
		if (is_printed_quit)
			printf("\"\n");
		else
			printf("\n");
		is_printed_quit = 0;
		count++;
	}
}
