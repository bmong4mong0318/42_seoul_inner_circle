/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:00:52 by dayun             #+#    #+#             */
/*   Updated: 2023/01/01 16:39:26 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

char	*ft_cutword(char *ptr)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	while (ptr[i] != '\n' && ptr[i])
		i++;
	if (!ptr[i])
	{
		free(ptr);
		return (NULL);
	}
	if (ptr[i] == '\n')
		i++;
	dest = malloc(sizeof(char) * (ft_strlen(ptr) - i + 1));
	if (!dest)
		return (NULL);
	while (ptr[i])
		dest[j++] = ptr[i++];
	dest[j] = '\0';
	free(ptr);
	return (dest);
}

char	*ft_read(int fd, char *ptr)
{
	int		bytes;
	char	*temp;

	bytes = 1;
	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	while (!ft_strchr(ptr, '\n') && bytes != 0)
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(temp);
			free(ptr);
			return (NULL);
		}
		temp[bytes] = '\0';
		ptr = ft_strjoin(ptr, temp);
	}
	free(temp);
	return (ptr);
}

char	*get_next_line(int fd)
{
	static char	*ptr;
	char		*line;
	int			index;

	index = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!ptr)
		ptr = ft_strdup("");
	ptr = ft_read(fd, ptr);
	if (!ptr)
	{
		free(ptr);
		return (NULL);
	}
	while (ptr[index] != '\n' && ptr[index])
		index++;
	line = ft_substr(ptr, 0, index + 1);
	ptr = ft_cutword(ptr);
	if (!line || !line[0])
	{
		free(line);
		return (NULL);
	}
	return (line);
}
