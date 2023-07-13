/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   appned.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 22:56:25 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/12 15:25:53 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int appned(char **content, int count) {
    struct stat fileStat;
    stat(content[count + 1], &fileStat); 
    if (S_ISDIR(fileStat.st_mode)) {
        captur.exit_status = 1;
        ft_putstr_fd("minishell : ", 2);
        ft_putstr_fd(content[count + 1], 2);
        ft_putstr_fd(": is a directory\n", 2);
        return 1;
    }
    if (access(content[count + 1], F_OK) == -1) {
        captur.exit_status = 1;
        ft_putstr_fd("minishell : ", 2);
        ft_putstr_fd(content[count + 1], 2);
        ft_putstr_fd(": No such file or directory\n", 2);
        return 1;
    }
    int fd = open(content[count + 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (access(content[count + 1], W_OK)) {
        captur.exit_status = 1;
        ft_putstr_fd("minishell : ", 2);
        ft_putstr_fd(content[count + 1], 2);
        ft_putstr_fd(": Permission denied\n", 2);
        return 1;
    }
    dup2(fd, STDOUT_FILENO);
    close(fd);
    return 0;
}
