/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:10:03 by mamazzal          #+#    #+#             */
/*   Updated: 2023/06/03 20:34:12 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int run_cmd(char *cmd, char **param, char **env) {
    int pid = fork();
    if(pid == 0)
    {
        if (execve(cmd, param, env) == -1) {
            perror("execve");
            exit(127);
            return -1;
        }
    }
    waitpid(pid, NULL, 0);
    return 0;
}

int main(void) {
    t_shell *shell;
    shell = malloc(sizeof(t_shell));
    while (1) {
        shell->buffer = readline("MINISHELL ~>");
        if (*shell->buffer) {      
            add_history(shell->buffer);
            shell->args = ft_split(shell->buffer, ' ');
            shell->cmd = shell->args[0];
            char *cmd = ft_strjoin("/bin/", shell->cmd);
            run_cmd(cmd, shell->args, NULL);
        }
    }
}
