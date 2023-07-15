/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_the_dir_name.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 11:30:09 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/15 13:11:32 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int check_the_dir_name(char *dir_name) {
    struct stat fileStat;
    stat(dir_name, &fileStat); 
    if (S_ISDIR(fileStat.st_mode)) {
      captur.exit_status = 0;
      return 0;
    }
    if (access(dir_name, F_OK) == -1) {
      captur.exit_status = 1;
      ft_putstr_fd("minishell: cd: ", 2);
      ft_putstr_fd(dir_name, 2);
      ft_putstr_fd(": No such file or directory\n", 2);
      return 1;
    }
    if (S_ISREG(fileStat.st_mode)) {
      captur.exit_status = 1;
      ft_putstr_fd("minishell: cd", 2);
      ft_putstr_fd(dir_name, 2);
      ft_putstr_fd(": Not a directory\n", 2);
      return 1;
    }
    return 0;
}
