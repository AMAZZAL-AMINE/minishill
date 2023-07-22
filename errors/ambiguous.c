/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambiguous.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 19:28:25 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/22 13:59:07 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_get_grepe_size_ambiguous(char *s)
{
	int	count;

	count = 1;
	while (s[count] && (ft_isalpha(s[count]) \
		|| s[count] == '_' || ft_isdigit(s[count])))
		count++;
	if ((s[count] == '\'' || s[count] == '\"'))
		return (count - 1);
	else if (s[count] == '?')
		return (count);
	return (count - 1);
}

int	is_var_between_quot_ambiguous(char *arg)
{
	int	count;
	int	count2;

	count = 0;
	count2 = 0;
	while (arg[count])
	{
		if (arg[count] == '\"')
			count2++;
		if (arg[count] == '$' && count2 % 2 != 0)
			return (1);
		count++;
	}
	return (0);
}

int	is_only_dolar(char c, char c_next)
{
	if (c == '$' && (!ft_isalpha(c_next) \
		&& !ft_isdigit(c_next) && c_next != '_' \
		&& c_next != '?' && c_next != '@'))
		return (1);
	return (0);
}

char	*expand_ambiguous(char *arg, t_minishell *mini)
{
	int		grep_size;
	int		count;
	char	*tmp1;
	char	*tmp2;
	char	*dst;

	count = 0;
	while (arg[count])
	{
		grep_size = 0;
		if (arg[count] == '$')
		{
			if (arg[count + 1] && (arg[count + 1] == '@' \
				|| ft_isdigit(arg[count + 1])))
				grep_size = 1;
			else
				grep_size = ft_get_grepe_size_ambiguous(arg + count);
			tmp1 = ft_strndup(arg, count);
			tmp2 = arg + (grep_size + (count + 1));
			if (is_only_dolar(arg[count], arg[count + 1]))
				dst = "$";
			else
			{
				if (arg[count + 1] == '?')
					dst = ft_itoa(captur.exit_status);
				else
				{
					dst = ft_strndup((arg + (count + 1)), grep_size);
					dst = get_env_value(dst, mini);
				}
			}
			if (dst == NULL)
				dst = "";
			dst = ft_strjoin(ft_strjoin(tmp1, dst), tmp2);
			arg = dst;
		}
		count++;
	}
	dst = ft_strdup(dst);
	return (dst);
}
