/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:01:36 by taelkhal          #+#    #+#             */
/*   Updated: 2023/02/12 16:58:58 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>

# define RED    "\033[1m\033[31m"
// # define GREEN    "\033[1m\033[32m"
// # define YELLOW    "\033[1m\033[33m"
//libft
void	ft_putstr(char *str, int fd);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(char *str);
char	*ft_strstr(char *str, char *to_find);


char	*check_path_env(char *cmd, char **env);
void	parent_process(char **av, char **env, int fd[], char **cmd);
void    child_process(char **av, char **env, int fd[], char **cmd);
void    run_cmd(char *av, char **env, char **cmd);


#endif
