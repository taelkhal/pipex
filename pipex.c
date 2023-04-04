/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:34:35 by taelkhal          #+#    #+#             */
/*   Updated: 2023/02/26 20:52:24 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipe_error_msg(void)
{
	ft_putstr(RED"ERROR, CAN'T OPEN THE PIPE\n", 2);
	exit (1);
}

void	run_cmd(char *av, char **env, char **cmd)
{
	int		i;
	char	*path;

	i = 0;
	if (!av)
		exit (1);
	cmd = ft_split(av, ' ');
	path = check_path_env(cmd[0], env);
	if (!path)
	{
		while (cmd[i])
			free(cmd[i++]);
		free(cmd);
	}
	if (execve(path, cmd, env) == -1)
	{
		ft_putstr(RED"ERROR, COMMAND NOT FOUND\n", 2);
		exit (1);
	}
}

void	child_process1(char **av, char **env, int fd[], char **cmd)
{
	int	input_fd;

	input_fd = open(av[1], O_RDONLY);
	if (input_fd == -1)
	{
		perror(RED"ERROR ");
		exit (1);
	}
	dup2(fd[1], 1);
	dup2(input_fd, 0);
	close(fd[0]);
	run_cmd(av[2], env, cmd);
}

void	child_process2(char **av, char **env, int fd[], char **cmd)
{
	int	output_fd;

	output_fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (output_fd == -1)
	{
		perror (RED"ERROR ");
		exit (1);
	}
	dup2(fd[0], 0);
	dup2(output_fd, 1);
	close (fd[1]);
	run_cmd(av[3], env, cmd);
}

int	main(int ac, char **av, char **env)
{
	pid_t	id1;
	pid_t	id2;
	int		fd[2];
	char	**cmd;

	if (ac == 5)
	{
		if (pipe(fd) == -1)
			pipe_error_msg();
		id1 = fork();
		if (id1 == -1)
			exit (1);
		if (id1 == 0)
			child_process1(av, env, fd, cmd);
		id2 = fork();
		if (id2 == -1)
			exit (1);
		if (id2 == 0)
			child_process2(av, env, fd, cmd);
		close_and_wait(fd, id1, id2);
	}
	else
		more_or_less_args();
	return (0);
}
