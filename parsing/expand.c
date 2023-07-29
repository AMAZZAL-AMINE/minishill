/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 20:17:48 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/29 01:54:46 by mamazzal         ###   ########.fr       */
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

typedef struct t_data
{
	int		count;
	char	*tmp1;
	char	*tmp2;
	char	*dst;
	char	*tmp3;
	char	*tmp4;
	int		grep_size;
	int		yes;
	int	 can_free_tmp4;
	int saved_index;
}	t_data;

int	is_var_between_quot(char *arg, t_data *data)
{
	int	count;
	int	count2;

	count = 0;
	count2 = 0;
	while (arg[count])
	{
		if (arg[count] == '\"')
			count2++;
		if (count == data->count && arg[count] == '$' && count2 % 2 != 0)
			return (1);
		count++;
	}
	return (0);
}


int	nothing_nrear_dolar_importent(t_data *data, char *arg)
{
	if (arg[data->count] == '$' && (!ft_isalpha(arg[data->count + 1]) \
		&& !ft_isdigit(arg[data->count + 1]) && arg[data->count + 1] != '_' \
		&& arg[data->count + 1] != '?' && arg[data->count + 1] != '@'))
		return (1);
	return (0);
}

int	chould_i_expand(char *arg, t_data *data)
{
	int	count;
	int	count2;
	int	count3;

	count = 0;
	count2 = 0;
	count3 = 0;
	while (arg[count])
	{
		if (arg[count] == '\'' && count3 % 2 == 0)
			count2++;
		else if (arg[count] == '\"' && count2 % 2 == 0)
			count3++;
		else if (data->count == count && arg[count] == '$' && count2 % 2 == 0) {
				return (1);
		}
		count++;
	}
	return (0);
}

void	expan_utilis(t_data *data, char *arg, t_minishell *mini)
{
	char *tmp;
	if (arg[data->count + 1] && (arg[data->count + 1] == '@' \
		|| ft_isdigit(arg[data->count + 1])))
		data->grep_size = 1;
	else
		data->grep_size = ft_get_grepe_size(arg + data->count);
	data->tmp1 = ft_strndup(arg, data->count);
	data->tmp2 = arg + (data->grep_size + (data->count + 1));
	tmp = ft_strndup((arg + (data->count + 1)), data->grep_size);
	if (nothing_nrear_dolar_importent(data, arg)) {
		free(data->dst);
		data->dst = "$";
		data->yes = 0;
	}
	else
	{
			if (chould_i_expand(arg, data)) {
				if (arg[data->count + 1] == '?') {
						data->tmp4 = ft_itoa(captur.exit_status);
						data->dst = data->tmp4;
						data->yes = 0;
						data->can_free_tmp4 = 1;
				}else {	
					data->dst = tmp;
					data->dst = get_env_value(data->dst, mini);
					data->yes = 0;
					if (data->dst)
						if (!is_var_between_quot(arg, data)) {
							data->tmp3 = get_value_with_no_moure_then_space(data->dst);
							// free(tmp4);
							data->yes = 1;
							data->dst = data->tmp3;
						}
				}
			}else {
				data->dst = ft_strndup((arg + (data->count)), data->grep_size + 1);
				data->yes = 0;
			}
		}
		free(tmp);
}

char	*expand(char *arg, t_minishell *mini)
{
	t_data	data;
	int			size;
	char	*tmp;

	data.count = 0;
	size = ft_strlen(arg);
	while (size > data.count)
	{
		data.grep_size = 0;
		if (arg[data.count] == '$')
		{
			data.can_free_tmp4 = 0;
			expan_utilis(&data, arg, mini);
			if (data.dst == NULL) {
				data.yes = 0;
				free(data.dst);
				data.dst = "";
			}
			tmp = ft_strjoin(data.tmp1, data.dst);
			data.dst = ft_strjoin(tmp, data.tmp2);
	 
			arg = data.dst;
			size = ft_strlen(arg);
			if (data.can_free_tmp4)
				free(data.tmp4);
			free(tmp);
			if (data.yes)
				free(data.tmp3);
			if (data.tmp1)
				free(data.tmp1);
		}
		data.count++;
	}
	// data.dst = ft_strdup(data.dst);
	return (data.dst);
}
