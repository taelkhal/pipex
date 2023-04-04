/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:01:36 by taelkhal          #+#    #+#             */
/*   Updated: 2023/02/24 15:16:30 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>

# define RED    "\033[1m\033[31m"

void	ft_putstr(char *str, int fd);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(char *str);
char	*ft_strstr(char *str, char *to_find);

char	*check_path_env(char *cmd, char **env);
void	more_or_less_args(void);
void	close_and_wait(int fd[], pid_t id1, pid_t id2);

#endif
