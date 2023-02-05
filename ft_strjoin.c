/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 23:56:39 by mmokane           #+#    #+#             */
/*   Updated: 2023/01/10 04:03:43 by mmokane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*resulttab;
	size_t	size;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	resulttab = malloc(sizeof(char) * (size + 1));
	if (!resulttab)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		resulttab[i++] = s1[j++];
	j = 0;
	while (s2[j])
		resulttab[i++] = s2[j++];
	resulttab[i] = '\0';
	return (resulttab);
}
