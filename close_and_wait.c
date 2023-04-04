/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_and_wait.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:50:43 by taelkhal          #+#    #+#             */
/*   Updated: 2023/02/18 15:00:02 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_and_wait(int fd[], pid_t id1, pid_t id2)
{
	close(fd[1]);
	close(fd[0]);
	waitpid(id1, NULL, 0);
	waitpid(id2, NULL, 0);
}
