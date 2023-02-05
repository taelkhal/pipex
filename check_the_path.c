/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_the_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 00:00:13 by mmokane           #+#    #+#             */
/*   Updated: 2023/01/15 00:54:20 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char *command, char **path_line)
{
	int		i;
	char	*path;
	char	*joined_path;

	i = 0;
	while (path_line[i])
	{
		if (access(command, F_OK) == -1)
		{
			joined_path = ft_strjoin(path_line[i], "/");
			path = ft_strjoin(joined_path, command);
			free(joined_path);
			if (access(path, F_OK) == 0)
				return (path);
			free(path);
			i++;
		}
		else
			return (command);
	}
	return (0);
}

char	*check_for_path(char *command, char **env)
{
	int		i;
	char	**path_line;
	char	*path_index;

	if (!env)
		return (0);
	i = 0;
	while (env[i])
	{
		if (ft_strstr(env[i], "PATH"))
			break ;
		i++;
	}
	if (env[i])
	{	
		path_index = env[i];
		path_line = ft_split(path_index + 5, ':');
		return (find_path(command, path_line));
	}
	write (2, "PATH is unset.\n", 16);
	exit(1);
}
