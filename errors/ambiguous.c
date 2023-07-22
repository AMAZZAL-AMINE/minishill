/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambiguous.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 19:28:25 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/22 15:24:07 by mamazzal         ###   ########.fr       */
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

char	*expande_amg_help(int grep_size, char *arg, \
	int count, t_minishell *mini)
{
	char	*tmp1;
	char	*tmp2;
	char	*dst;

	grep_size = is_arobase(arg[count + 1], grep_size, arg, count);
	tmp1 = ft_strndup(arg, count);
	tmp2 = arg + (grep_size + (count + 1));
	if (is_only_dolar(arg[count], arg[count + 1]))
		dst = "$";
	else
	{
		if (arg[count + 1] == '?')
			dst = ft_itoa(captur.exit_status);
		else
			dst = get_env_value(ft_strndup((arg + (count + 1)), \
				grep_size), mini);
	}
	if (dst == NULL)
		dst = "";
	dst = ft_strjoin(ft_strjoin(tmp1, dst), tmp2);
	return (dst);
}

char	*expand_ambiguous(char *arg, t_minishell *mini)
{
	int		grep_size;
	int		count;
	char	*dst;

	count = 0;
	while (arg[count])
	{
		grep_size = 0;
		if (arg[count] == '$')
		{
			dst = expande_amg_help(grep_size, arg, count, mini);
			arg = dst;
		}
		count++;
	}
	dst = ft_strdup(dst);
	return (dst);
}
