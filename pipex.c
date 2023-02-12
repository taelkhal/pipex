/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:34:35 by taelkhal          #+#    #+#             */
/*   Updated: 2023/02/12 17:00:09 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    run_cmd(char *av, char **env, char **cmd)
{
    int     i;
    char	*path;

	i = 0;
	if (!av)
		exit (1);
	cmd = ft_split(av, ' ');
	path = check_path_env(cmd[0], env);
	if (!path)
	{
		while (cmd[i++])
			free(cmd[i]);
		free(cmd);
	}
	if (execve(path, cmd, env) == -1)
	{
		ft_putstr(RED"ERROR, COMMAND NOT FOUND\n", 2);
		exit (1);
	}
}

void    child_process(char **av, char **env, int fd[], char **cmd)
{
	int	input_fd;

	input_fd = open(av[1], O_RDONLY);
	if (input_fd == -1)
	{
		ft_putstr(RED"ERROR, CAN'T OPEN THIS FILE\n", 2);
		exit (1);
	}
	dup2(fd[1], 1);
	dup2(input_fd, 0);
	close(fd[0]);
	run_cmd(av[2], env, cmd);
}

void	parent_process(char **av, char **env, int fd[], char **cmd)
{
	int	output_fd;

	output_fd = open(av[4], O_RDONLY | O_WRONLY | O_CREAT);
	if (output_fd == -1)
	{
		ft_putstr(RED"ERROR, CAN'T OPEN THIS FILE\n", 2);
		exit (1);
	}
	dup2(fd[0], 0);
	dup2(output_fd, 1);
	close (fd[1]);
	run_cmd(av[3], env, cmd);
}

int main(int ac, char **av, char **env)
{
	pid_t id;
	int		fd[2];
	char **cmd;

	cmd = NULL;
	if (ac == 5)
	{
		if (pipe(fd) == -1)
		{
			ft_putstr(RED"ERROR, CAN'T OPEN PIPE\n", 2);
			exit (1);
		}
		id = fork();
		if (id == -1)
			exit (1);
		if (id == 0)
			child_process(av, env, fd, cmd);
		waitpid(id, NULL, 0);
		parent_process(av, env, fd, cmd);
	}
	ft_putstr(RED"ERROR, INVALID ARGUMENTS NUMBERS\n", 2);
	return (0);
}
