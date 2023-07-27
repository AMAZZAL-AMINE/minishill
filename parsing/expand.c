/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 20:17:48 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/27 21:18:04 by mamazzal         ###   ########.fr       */
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

typedef struct t_data
{
	int		count;
	char	*tmp1;
	char	*tmp2;
	char	*dst;
	int		grep_size;
}	t_data;

int	nothing_nrear_dolar_importent(t_data *data, char *arg)
{
	if (arg[data->count] == '$' && (!ft_isalpha(arg[data->count + 1]) \
		&& !ft_isdigit(arg[data->count + 1]) && arg[data->count + 1] != '_' \
		&& arg[data->count + 1] != '?' && arg[data->count + 1] != '@'))
		return (1);
	return (0);
}

void	expan_utilis(t_data *data, char *arg, t_minishell *mini)
{
	if (arg[data->count + 1] && (arg[data->count + 1] == '@' \
		|| ft_isdigit(arg[data->count + 1])))
		data->grep_size = 1;
	else
		data->grep_size = ft_get_grepe_size(arg + data->count);
	data->tmp1 = ft_strndup(arg, data->count);
	data->tmp2 = arg + (data->grep_size + (data->count + 1));
	if (nothing_nrear_dolar_importent(data, arg))
		data->dst = ft_strdup("$");
	else
	{
		if (arg[data->count + 1] == '?')
			data->dst = ft_itoa(captur.exit_status);
		else
		{
			data->dst = ft_strndup((arg + (data->count + 1)), data->grep_size);
			data->dst = get_env_value(data->dst, mini);
			if (data->dst)
				if (!is_var_between_quot(arg)) {
					data->dst = get_value_with_no_moure_then_space(data->dst);
				}
		}
	}
}

char	*expand(char *arg, t_minishell *mini)
{
	t_data	data;
	int			size;
	char	*tmp;

	data.count = 0;
	size = ft_strlen(arg);
	while (arg[data.count])
	{
		data.grep_size = 0;
		if (arg[data.count] == '$')
		{
			expan_utilis(&data, arg, mini);
			if (data.dst == NULL)
				data.dst = ft_strdup("");
			tmp = ft_strjoin(data.tmp1, data.dst);
			data.dst = ft_strjoin(tmp, data.tmp2);
			arg = data.dst;
			free(tmp);
			if (data.tmp1)
				free(data.tmp1);
		}
		data.count++;
	}
	// free(arg);
	// data.dst = ft_strdup(data.dst);
	return (data.dst);
}
