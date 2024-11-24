/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oachbani <oachbani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 09:33:30 by oachbani          #+#    #+#             */
/*   Updated: 2024/11/24 11:41:36 by oachbani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_add(char *str, int fd)
{
	int		readed;
	char	*buffer;

	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (free(str), NULL);
	readed = 1;
	while (!ft_strchr(str, '\n') && readed)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed == -1)
			return (free(buffer), free(str), NULL);
		buffer[readed] = '\0';
		str = ft_strjoin(str, buffer);
		if (!str)
			return (free(str), NULL);
	}
	free(buffer);
	return (str);
}

char	*ft_extract(char *str)
{
	size_t	len;
	char	*buffer;

	if (!str || !(*str))
		return (NULL);
	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	buffer = (char *)malloc(len + 2);
	if (!buffer)
		return (free(str), NULL);
	len = 0;
	while (str[len] && str[len] != '\n')
	{
		buffer[len] = str[len];
		len++;
	}
	if (str[len] == '\n')
	{
		buffer[len] = str[len];
		len++;
	}
	buffer[len] = '\0';
	return (buffer);
}

char	*ft_remaining(char *str)
{
	size_t	clear;
	char	*buffer;
	size_t	save;

	clear = 0;
	save = 0;
	while (str[clear] && str[clear] != '\n')
		clear++;
	if (!str[clear])
		return (free(str), NULL);
	buffer = malloc(ft_strlen(str) - clear + 1);
	if (!buffer)
		return (free(str), NULL);
	clear++;
	while (str[clear])
		buffer[save++] = str[clear++];
	buffer[save] = '\0';
	free(str);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*line[1024];
	char		*save;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > 1024)
		return (NULL);
	line[fd] = ft_read_add(line[fd], fd);
	if (!line[fd])
		return (NULL);
	save = ft_extract(line[fd]);
	if (!save)
	{
		free(line[fd]);
		line[fd] = NULL;
		return (NULL);
	}
	line[fd] = ft_remaining(line[fd]);
	return (save);
}
/*
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd,fd1,fd2;
    char *line;

    fd = open("tes1.txt",O_RDONLY,0777);
    fd1 = open("tes2.txt", O_RDONLY,0777);
    fd2 = open("tes3.txt", O_RDONLY,0777);
	if (fd == -1)
    {
        printf("Error opening file\n");
        return (1);
    }
    printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd1));
	printf("%s",get_next_line(fd2));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd1));
	printf("%s",get_next_line(fd2));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd1));
	printf("%s",get_next_line(fd2));
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
	while ((line = get_next_line(fd1)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
	while ((line = get_next_line(fd2)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
	close(fd1);
	close(fd2);
    return (0);
}*/