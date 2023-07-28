/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ambiguous_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 13:13:44 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/28 02:41:48 by mamazzal         ###   ########.fr       */
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
	char    *tmp;

    if (name[index] == '$')
    {
        tmp = ft_strdup(name);
        dst = expand_ambiguous(tmp, mini);
        if (is_btween_word_space(dst))
            return (ambg_err_msg(name));
        free(tmp);// free hna
        free(dst);// free hna
    }
    return (0);
}

int	is_ambiguous_file(char *name, t_minishell *mini)
{
	char    *dst;
	int        index;
	char     *tmp;

	if (name[0] == '$')
	{
			tmp = ft_strdup(name);
			dst = expand_ambiguous(tmp, mini);
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
			free(dst);//free hna
			free(tmp);//free hna
	}
	captur.exit_status = 0;
	return (0);
}
