/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambiguous.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 19:28:25 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/28 01:48:21 by mamazzal         ###   ########.fr       */
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
	char	*tmp;
	char	*tmp1;
	char	*tmp2;
	char	*tmp3;
	char	*dst;

	grep_size = is_arobase(arg[count + 1], grep_size, arg, count);
	tmp = ft_strndup((arg + (count + 1)), grep_size);
	tmp1 = ft_strndup(arg, count);
	tmp2 = arg + (grep_size + (count + 1));
	if (is_only_dolar(arg[count], arg[count + 1]))
			dst = "$";
	else
	{
			if (arg[count + 1] == '?')
					dst = ft_itoa(captur.exit_status);
			else
					dst = get_env_value(tmp, mini);
	}
	if (dst == NULL)
			dst = "";
	tmp3 = ft_strjoin(tmp1, dst);
	dst = ft_strjoin(tmp3, tmp2);
	free(tmp);//free hna
	free(tmp1);//free hna
	free(tmp3);//free hna
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
	free(arg);
	return (dst);
}
