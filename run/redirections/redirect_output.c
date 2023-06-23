/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 22:49:49 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/23 01:06:44 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void redirect_output(char **content, int count) {
    int red = open(content[count + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (red == -1) {
        printf("minishell: No such file or directory %s\n", content[count + 1]);
        exit(EXIT_FAILURE);
    }
    dup2(red, STDOUT_FILENO);
}
