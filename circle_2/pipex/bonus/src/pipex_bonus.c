/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:56:04 by dayun             #+#    #+#             */
/*   Updated: 2023/02/03 16:39:15 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

static void	init_info(t_env *info, int argc, char **argv, char **envp)
{
	int	i;

	ft_memset(info, 0, sizeof(t_env));
	info->result = 0;
	info->envp = envp;
	get_fd(info, argc, argv);
	info->n_cmd = argc - 3 - info->here_doc;
	info->pipe = (int *)malloc(sizeof(int) * 2 * (info->n_cmd - 1));
	if (!info->pipe)
		exit_perror("malloc error", 1);
	i = -1;
	while (++i < info->n_cmd - 1)
	{
		if (pipe(info->pipe + 2 * i) < 0)
		{
			free(info->pipe);
			exit_perror(ERR_PIPE, 1);
		}
	}
}

static void	sub_dup2(int zero, int first)
{
	dup2(zero, STDIN_FILENO);
	dup2(first, STDOUT_FILENO);
}

void	child(t_env p)
{
	p.pid = fork();
	if (!p.pid)
	{
		if (p.idx == 0)
			sub_dup2(p.i_fd, p.pipe[1]);
		else if (p.idx == p.n_cmd - 1)
			sub_dup2(p.pipe[2 * p.idx - 2], p.o_fd);
		else
			sub_dup2(p.pipe[2 * p.idx - 2], p.pipe[2 * p.idx + 1]);
		close_pipes(&p);
		if (execve(p.cmd[p.idx].path, p.cmd[p.idx].cmd, p.envp) < 0)
			exit_perror(ERR_CMD, p.result);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_env	info;

	if (argc < args_in(argv[1]))
		exit(EXIT_FAILURE);
	init_info(&info, argc, argv, envp);
	parse_cmd(&info, argc - (&info)->here_doc, argv + (&info)->here_doc);
	info.idx = -1;
	while (++(info.idx) < info.n_cmd)
		child(info);
	close_pipes(&info);
	waitpid(-1, NULL, 0);
	parent_free(&info);
	return (info.result);
}