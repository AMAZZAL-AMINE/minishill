/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis_part2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:01:16 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/24 21:46:11 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	skip_spaces(char *token)
{
	int	count;

	count = 0;
	while (token[count] == ' ' && token[count])
		count++;
	return (count);
}



char	*rm_spaces_from_cmd(char *cmd)
{
	int	size;
	int	count_quots;
	int	count_squots;
	char	*new_cmd;

	size = 0;
	count_quots = 0;
	count_squots = 0;
	while (cmd[size] && cmd[size] == ' ')
		size++;
	while (cmd[size])
	{
		if (cmd[size] == ' ' && (count_quots % 2 == 0 && count_squots % 2 == 0))
			break ;
		if (cmd[size] == '\"')
			count_quots++;
		if (cmd[size] == '\'')
			count_squots++;
		size++;
	}
	new_cmd = ft_strndup(cmd, size);
	return (new_cmd);
}

int	get_size_of_arg_if_args(char **args)
{
	int	count;
	int	size_of;

	count = 0;
	size_of = 0;
	while (args[count])
	{
		if (is_dolar_var(args[count]))
			size_of += count_length_two_arr(ft_split(args[count], '$'));
		count++;
	}
	return (size_of + count_length_two_arr(args));
}

int	get_length_var(char *s)
{
	int	count;

	count = 0;
	if (s[0] == '$')
		count = 1;
	while (s[count] && (s[count] != '$'))
		count++;
	return (count);
}

int	is_q_in_cmd(char *token)
{
	int	count;
	int	is_space_or_any_to_split;

	count = 0;
	is_space_or_any_to_split = 0;
	while (token[count])
	{
		if (token[count] == ' ' || (token[count] == '>' \
			|| token[count] == '<'))
			is_space_or_any_to_split = 1;
		if ((token[count] == '\'' \
			|| token[count] == '\"') && is_space_or_any_to_split == 0)
			return (1);
		count++;
	}
	return (0);
}
