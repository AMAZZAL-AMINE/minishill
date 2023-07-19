/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 12:51:14 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/19 17:24:40 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void handle_signals(int sig) {
    if (sig == SIGINT) {
        captur.is_press_ctrl_c = 1;
        printf("\n");
        // rl_on_new_line();
        // rl_replace_line("", 0);
        rl_redisplay();
    }else if (sig == SIGQUIT) {
        rl_redisplay();
    }
}

void handle_ctl_d(char *line) {
    
    if ((int)line == 0) {
        captur.is_press_ctrl_d = 1;
        exit(captur.exit_status);
    }
}