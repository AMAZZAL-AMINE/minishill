/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_utilis.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 19:52:39 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/21 20:23:14 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	check_appned(t_minishell *mini, char *filename, \
	int count, char **new_content)
{
	int	captur;

	captur = 0;
	if (filename && \
		!is_ambiguous_file(filename, mini))
	{
		captur = appned(new_content, count);
		if (captur != 0)
			return (captur);
	}
	else
	{
		captur = 1;
		return (captur);
	}
	return (0);
}

int	check_redrect_input(char **new_content, \
	t_minishell *mini, int count, char *filename)
{
	int	captur;

	captur = 0;
	if (filename && \
		!is_ambiguous_file(filename, mini))
	{
		captur = redirect_input(new_content, count);
		if (captur != 0)
			return (captur);
	}
	else
	{
		captur = 1;
		return (captur);
	}
	return (0);
}

int	check_redrect_output(char **new_content, \
	t_minishell *mini, int count, char *filename)
{
	int	captur;

	captur = 0;
	if (filename && \
		!is_ambiguous_file(filename, mini))
	{
		captur = redirect_output(new_content, count);
		if (captur != 0)
			return (captur);
	}
	else
	{
		captur = 1;
		return (captur);
	}
	return (0);
}
