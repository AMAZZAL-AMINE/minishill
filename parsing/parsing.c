/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:24:34 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/29 18:47:14 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	init_and_split_utilis_part2(t_minishell *minishell, \
	char __unused *token, int pos)
{
	if (is_dolar_var(minishell->parsing[pos].cmd) && \
		is_bettwen_double(minishell->parsing[pos].cmd))
	{
		minishell->parsing[pos].cmd_tmp = minishell->parsing[pos].cmd;
		minishell->parsing[pos].cmd = \
			remove_quots(expand(minishell->parsing[pos].cmd, minishell));
		is_commande_var(&minishell->parsing[pos], minishell, pos);
		minishell->parsing[pos].is_cmd_var = 1;
	}
	else
	{
		minishell->parsing[pos].cmd_tmp = minishell->parsing[pos].cmd;
		minishell->parsing[pos].cmd = remove_quots(minishell->parsing[pos].cmd);
		minishell->parsing[pos].is_cmd_var = 0;
	}
}

char	**init_and_split_utilis_part1(t_minishell *minishell, \
	char **dst, int pos)
{
	char **tmp;
	if (is_redirec_output(dst))
	{
		tmp = sort_args(dst);
		//free(dst);
		dst = tmp;
		if ((!ft_strlen(minishell->parsing[pos].cmd) \
			|| is_redirect(minishell->parsing[pos].cmd)) \
			&& !is_redirect(dst[0]))
		{
			//free(minishell->parsing[pos].cmd);
			minishell->parsing[pos].cmd = dst[0];
			dst = duplicate_content(&dst[1]);
		}
	}
	return (dst);
}

void	init_and_split(t_minishell *minishell, char *token, int pos)
{
	char	*get_cmd_;
	char	*rem_sp;
	char	**dst;

	get_cmd_ = get_cmd_with_fixes_size(token, commande_length(token));
	rem_sp = rm_spaces_from_cmd(get_cmd_);
	//free(get_cmd_);
	minishell->parsing[pos].cmd = rem_sp;
	token = &token[skip_spaces(token)];
	token = token + (length_new_cmd(token));
	if (is_quot_in_cmd(minishell->parsing[pos].cmd))
		minishell->parsing[pos].is_cmd_in_quotes = 1;
	else
		minishell->parsing[pos].is_cmd_in_quotes = 0;
	dst = split_commande_args(token, minishell);
	minishell->parsing[pos].args = init_and_split_utilis_part1(minishell, dst, pos);
	init_and_split_utilis_part2(minishell, token, pos);
}


int	parsing_input(t_minishell *minishell, char *line)
{
	int		count;
	int		size;
	t_parsing	*parsing;

	//ceold duplacate line
	size = ft_count_tokens(line) * 2;
	minishell->tokens = new_tokens(line);
	if (minishell->tokens == NULL)
		return (1);
	count = 0;
	minishell->n_cmd = size;
	parsing = ft_malloc(sizeof(t_parsing) * (size + 1), 0, ALLOC, 0);
	minishell->parsing = parsing;
	while (count <= size)
	{
		init_and_split(minishell, minishell->tokens[count], count);
		count++;
	}
	return (0);
}
