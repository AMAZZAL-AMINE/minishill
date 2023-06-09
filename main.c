/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:10:03 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/09 18:23:48 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int run_cmd(t_cmd_table *table) {
    int pid = fork();
    if (pid == 0) {
        if (execve(table->path, table->args, NULL) == -1) {
            printf("minishell: %s: command not found\n", table->cmd);
            exit(127);
        }
        wait(NULL);
    }
    waitpid(pid, NULL, 0);
    return 0;
}

int main(void) {
    t_cmd_table *table;

    table = malloc(sizeof(t_cmd_table));
    while (1) {
        table->input = readline("mamazzal@minishell ~>");
        if (*table->input) {
            table->args = ft_split(table->input, ' ');
            table->cmd = table->args[0];
            add_history(table->input);
            // print_table(table);
            lxr(table);
            run_shell(table);
        }
    }
    return 0;
}
