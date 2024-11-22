/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oachbani <oachbani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:39:17 by oachbani          #+#    #+#             */
/*   Updated: 2024/11/22 17:33:06 by oachbani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;

	if (!str)
		return (NULL);
	i = -1;
	while (str[++i])
		if (str[i] == (char) c)
			return ((char *)&str[i]);
	if (str[i] == (char) c)
		return ((char *)&str[i]);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*p;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	p = malloc(i + 1);
	if (!p)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		p[i] = s1[i];
	while (s2[++j])
	{
		p[i] = s2[j];
		i++;
	}
	p[i] = '\0';
	return (p);
}