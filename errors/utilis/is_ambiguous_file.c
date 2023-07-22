/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ambiguous_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 13:13:44 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/22 13:38:11 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ambg_err_msg(char *name)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ambiguous redirect\n", 2);
	captur.exit_status = 1;
	return (1);
}

int	help_func_ambg(char *name, char *dst, t_minishell *mini, int index)
{
	if (name[index] == '$')
	{
		dst = expand_ambiguous(ft_strdup(name), mini);
		if (is_btween_word_space(dst))
			return (ambg_err_msg(name));
	}
	return (0);
}

int	is_ambiguous_file(char *name, t_minishell *mini)
{
	char	*dst;
	int		index;

	if (name[0] == '$')
	{
		dst = ft_strdup(name);
		dst = expand_ambiguous(dst, mini);
		if (ft_strlen(dst) == 0)
			return (ambg_err_msg(name));
		else if (is_dolar_(name))
		{
			if (!is_dolar_between_quot(name))
			{
				index = 0;
				while (name[index])
				{
					if (help_func_ambg(name, dst, mini, index))
						return (1);
					index++;
				}
			}
		}
	}
	captur.exit_status = 0;
	return (0);
}
