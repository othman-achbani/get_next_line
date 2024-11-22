/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oachbani <oachbani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:26:12 by oachbani          #+#    #+#             */
/*   Updated: 2024/11/22 22:47:30 by oachbani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_add(char *str, int fd)
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
	size_t	len;
	char	*buffer;

	if (!(*str))
		return(NULL);
	len = 0;
	while(str[len] && str[len] != 10)
		len++;
	buffer = (char *)malloc(len + 2);
	if (!buffer)
		return(NULL);
	len = -1 ;
	while(str[++len] && str[len] != '\n')
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
	size_t		clear;
	char		*buffer;
	size_t		save;

	clear = 0;
	save = 0;	
	while (str[clear] && str[clear] != 10)
		clear++;
	if(!str[clear])
	{
		free(str);
		return(NULL);
	}
	buffer = malloc(ft_strlen(str) - clear + 1);
	if (!buffer)
		return (NULL);
	clear++;
	while (str[clear])
		buffer[save++] = str[clear++]; 
	buffer[save] = '\0';
	return(buffer);
}

char	*get_next_line(int fd)
{
	static char *line;
	char		*save;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = 	ft_read_add(line, fd);
	if (!line)
		 return(NULL);
	save = ft_extract(line);
	line = ft_remaining(line);
	return(save);
}
#include <fcntl.h>
#include <stdio.h>
int main()
{
	int fd = open("text.txt", O_RDWR);
	//printf("%d", fd);
	printf("%s",get_next_line(fd));

	
}
