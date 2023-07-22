/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 20:17:48 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/22 15:58:22 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_get_grepe_size(char *s)
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

int	is_var_between_quot(char *arg)
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

char	*expand(char *arg, t_minishell *mini)
{
	int		count;
	char	*tmp1;
	char	*tmp2;
	char	*dst;
	int		grep_size;

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
				grep_size = ft_get_grepe_size(arg + count);
			tmp1 = ft_strndup(arg, count);
			tmp2 = arg + (grep_size + (count + 1));
			if (arg[count] == '$' && (!ft_isalpha(arg[count + 1]) \
				&& !ft_isdigit(arg[count + 1]) && arg[count + 1] != '_' \
				&& arg[count + 1] != '?' && arg[count + 1] != '@'))
				dst = "$";
			else
			{
				if (arg[count + 1] == '?')
					dst = ft_itoa(captur.exit_status);
				else
				{
					dst = ft_strndup((arg + (count + 1)), grep_size);
					dst = get_env_value(dst, mini);
					if (dst)
						if (!is_var_between_quot(arg))
							dst = get_value_with_no_moure_then_space(dst);
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
