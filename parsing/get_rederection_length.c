/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rederection_length.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 01:10:36 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/23 01:10:44 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_rederection_length(char *token)
{
	int	count;

	count = 0;
	if (token[0] == '>')
	{
		while (token[count] == '>')
			count++;
	}
	else if (token[0] == '<')
	{
		while (token[count] == '<')
			count++;
	}
	return (count);
}
