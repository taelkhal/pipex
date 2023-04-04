/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 16:12:12 by taelkhal          #+#    #+#             */
/*   Updated: 2023/02/26 21:02:30 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_cmd_path(char *cmd, char **paths)
{
	int		i;
	char	*path;
	char	*saver_path;

	i = 0;
	while (paths[i])
	{
		if (access(cmd, F_OK) == -1)
		{
			saver_path = ft_strjoin(paths[i], "/");
			path = ft_strjoin(saver_path, cmd);
			free (saver_path);
			if (access(path, F_OK) == 0)
				return (path);
			free (path);
			i++;
		}
		else
			return (cmd);
	}
	return (NULL);
}

char	*check_path_env(char *cmd, char **env)
{
	int		i;
	char	**paths;

	i = 0;
	if (!env)
		return (NULL);
	while (env[i])
	{
		if (ft_strstr(env[i], "PATH"))
			break ;
		i++;
	}
	if (env[i])
	{
		paths = ft_split(env[i] + 5, ':');
		return (find_cmd_path(cmd, paths));
	}
	write (2, cmd, ft_strlen(cmd));
	write (2, " : No such file or directory\n", 30);
	exit (1);
}
