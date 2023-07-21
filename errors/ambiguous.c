/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambiguous.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 19:28:25 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/21 11:22:37 by rouali           ###   ########.fr       */
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

int	is_dolar_between_quot(char *str)
{
	int	count;
	int	count2;

	count = 0;
	count2 = 0;
	while (str[count])
	{
		if (str[count] == '\"')
			count2++;
		if (str[count] == '$' && count2 % 2 != 0)
			return (1);
		count++;
	}
	return (0);
}

int	check_prev_str(char *str, int index)
{
	while (index)
	{
		if (str[index] != ' ')
		{
			return (1);
		}
		index--;
	}
	return (0);
}

int	check_next_str(char *str, int index)
{
	while (str[index])
	{
		if (str[index] != ' ')
		{
			return (1);
		}
		index++;
	}
	return (0);
}

int	is_btween_word_space(char *str)
{
	int	count;

	count = 0;
	while (str[count])
	{
		if (count > 0 && str[count] == ' ' \
			&& (check_prev_str(str, count) && check_next_str(str, count)))
			return (1);
		count++;
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
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(name, 2);
			ft_putstr_fd(": ambiguous redirect\n", 2);
			captur.exit_status = 1;
			return (1);
		}
		else if (is_dolar_(name))
		{
			if (!is_dolar_between_quot(name))
			{
				index = 0;
				while (name[index])
				{
					if (name[index] == '$')
					{
						dst = expand_ambiguous(ft_strdup(name), mini);
						if (is_btween_word_space(dst))
						{
							ft_putstr_fd("minishell: ", 2);
							ft_putstr_fd(name, 2);
							ft_putstr_fd(": ambiguous redirect\n", 2);
							captur.exit_status = 1;
							return (1);
						}
					}
					index++;
				}
			}
		}
	}
	captur.exit_status = 0;
	return (0);
}
