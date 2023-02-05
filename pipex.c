/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 20:27:26 by mmokane           #+#    #+#             */
/*   Updated: 2023/01/21 16:32:37 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(char *argv[], char **env, int fd[], char **command)
{
	int	infile;

	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
	{
		write(2, argv[1], ft_strlen(argv[1]));
		write(2, " : Infile error\n", 17);
		exit (1);
	}
	dup2(fd[1], 1);
	dup2(infile, 0);
	close(fd[0]);
	launch(argv[2], env, command);
}

void	parent(char *argv[], char **env, int fd[], char **command)
{
	int	outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
	{
		write (2, argv[4], ft_strlen(argv[4]));
		write (2, "Outfile error\n", 15);
		exit(1);
	}
	dup2(fd[0], 0);
	dup2(outfile, 1);
	close(fd[1]);
	launch(argv[3], env, command);
}

int	main(int argc, char *argv[], char **env)
{
	int		fd[2];
	pid_t	id;
	char	**command;

	if (argc != 5)
	{
		write (2, "Invalid number of arguments\n", 29);
		exit(1);
	}
	else
	{
		if (pipe(fd) == -1)
		{
			write (2, "An error has occured with opening the pipe\n", 44);
			exit (1);
		}
		id = fork();
		if (id == -1)
			exit (1);
		if (id == 0)
			child (argv, env, fd, command);
		waitpid (id, NULL, 0);
		parent (argv, env, fd, command);
	}
	return (0);
}

void	launch(char *argv, char **env, char **command)
{
	int		i;
	char	*path;

	if (!argv)
		exit (1);
	command = ft_split(argv, ' ');
	path = check_for_path(command[0], env);
	if (!path)
	{
		while (command[i++])
			free(command[i]);
		free(command);
	}
	if (execve(path, command, env) == -1)
	{
		write (2, argv, ft_strlen(argv));
		write (2, " : Command not found\n", 22);
		exit(1);
	}
}
