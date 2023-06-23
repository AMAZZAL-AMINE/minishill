/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   appned.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 22:56:25 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/22 23:53:09 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void appned(char **content, int count) {
    int fd = open(content[count + 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
    dup2(fd, STDOUT_FILENO);
}
