/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oachbani <oachbani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:26:12 by oachbani          #+#    #+#             */
/*   Updated: 2024/11/22 17:33:46 by oachbani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char *line;
	char		*save;
	int			i;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = ft_read(line, fd);
	if (!save)
		return(NULL);
	save = ft_extract(line);
	line = ft_remaining(line);
	return(save);
}

char	*ft_read(char *str, int fd)
{
	int		readed;
	char	*buffer;

	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	readed = 1;
	while (!ft_strchr(str,10) && readed)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed == -1)
		{
			free(buffer);
			return(NULL);
		}
		buffer[readed] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return(str);
}

char	*ft_extract(char *str)
{
	int	len;
	char *buffer;

	len = 0;
	while(str[len] && str[len] != 10)
		len++;
	buffer = (char *)malloc(len + 2);
	if (!buffer)
		return(NULL);
	len = -1 ;
	while(str[++len] && str[len] != 10)
		buffer[len]= str[len];
	if (str[len] == 10)
	{
		buffer[len] = str[len];
		len++;
	}
	str[len] = '\0';
	return(str);
}

char	*ft_remaining(char *str)
{
	int		len;
	char	*buffer;

	len = 0;
	while (str[len] && str[len] != 10)
		len++;
	buffer = (char *)
	

}