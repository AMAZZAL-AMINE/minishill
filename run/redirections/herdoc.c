/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 22:58:20 by mamazzal          #+#    #+#             */
/*   Updated: 2023/07/30 17:31:49 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_dolar(char *arg)
{
	int	count;

	count = 0;
	while (arg[count])
	{
		if (arg[count] == '$')
			return (1);
		count++;
	}
	return (0);
}

int	is_eof_in_quot_fun(char *arg)
{
	int	count;

	count = 0;
	while (arg[count])
	{
		if (arg[count] == '\'')
			return (1);
		else if (arg[count] == '\"')
			return (1);
		count++;
	}
	return (0);
}

void	heredoc_segnal(int sig) 
{
	captur.is_press_ctrl_c = 0;
	if (sig == SIGINT) {
		printf("\n");
		// rl_on_new_line();
		exit(0);
	}
}

char	*start_herdoc_utilis(char *eof, int is_eof_in_quot, \
	char *tmp, t_minishell *mini)
{
	char	*line;
	
	while (1)
	{
		signal(SIGINT, heredoc_segnal);
		line = readline("> ");
		if ((int)line == 0)
			break ;
		if (*line)
		{
			if (is_dolar(line))
			{
				if (!is_eof_in_quot)
					line = expand(line, mini);
			}
			if (eof && str_cmp(line, eof))
				break ;
			line = ft_strjoin(line, "\n");
			tmp = ft_strjoin(tmp, line);
		}
	}
	return (tmp);
}

int	run_herdoc(char __unused **content, \
	char *eof, t_minishell __unused *mini, int *pipid)
{
	captur.is_press_ctrl_c = 1;
	int pid = 0;
	char	*line;
	int		is_eof_in_quot;
	char	*tmp;

	line = NULL;
	is_eof_in_quot = 0;
	tmp = "";
	pid = fork();
	if (pid == 0) {
		close(pipid[0]);
		if (is_eof_in_quot_fun(eof))
			is_eof_in_quot = 1;
		eof = remove_quots(eof);
		if (is_dolar(eof) && !is_eof_in_quot)
			eof = expand(eof, mini);
		tmp = start_herdoc_utilis(eof, is_eof_in_quot, tmp, mini);
		if (tmp)
			write(pipid[1], tmp, ft_strlen(tmp));
		exit(0);
	}else {
		waitpid(pid, NULL, 0);
		close(pipid[1]);
		return (pipid[0]);
	}
	return (0);
}

int	herdoc(char **content, t_minishell __unused *mini)
{
	int		count;
	int		savedid;
	int		status;
	int		pid;
	int		pipid[2];

	count = 0;
	savedid = -1;
	pid = -1;
	while (content[count])
	{
		if (str_cmp(content[count], "<<"))
		{
			pipe(pipid);
			savedid = run_herdoc(content, content[count + 1], mini, pipid);
			waitpid(pid, &status, 0);
		}
		count++;
	}
	dup2(savedid, 0);
	if (savedid != -1)
		close(savedid);
	captur.is_press_ctrl_c = 0;
	return (0);
}
