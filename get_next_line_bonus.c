/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 21:38:06 by fflamion          #+#    #+#             */
/*   Updated: 2024/06/11 15:30:26 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*clean_storage(char *storage)
{
	char	*new_storage;
	char	*ptr;
	int		len;

	ptr = ft_strchr(storage, '\n');
	if (!ptr)
	{
		new_storage = NULL;
		return (ft_free(&storage));
	}
	else
		len = (ptr - storage) + 1;
	if (!storage[len])
		return (ft_free(&storage));
	new_storage = ft_substr(storage, len, ft_strlen(storage) - len);
	ft_free(&storage);
	if (!new_storage)
		return (NULL);
	return (new_storage);
}

char	*new_line(char *storage)
{
	char	*line;
	char	*ptr;
	int		len;

	ptr = ft_strchr(storage, '\n');
	len = (ptr - storage) + 1;
	line = ft_substr(storage, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

char	*readline(int fd, char *storage)
{
	int		bitread;
	char	*buffer;

	bitread = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	while (bitread > 0 && !ft_strchr(buffer, '\n'))
	{
		bitread = read (fd, buffer, BUFFER_SIZE);
		if (bitread > 0)
		{
			buffer[bitread] = '\0';
			storage = ft_strjoin(storage, buffer);
		}
	}
	free(buffer);
	if (bitread == -1)
		return (ft_free(&storage));
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage[8192] = {0};
	char		*line;

	if (fd < 0)
		return (NULL);
	if ((storage[fd] && !ft_strchr(storage[fd], '\n')) || !storage[fd])
		storage[fd] = readline (fd, storage[fd]);
	if (!storage[fd])
		return (NULL);
	line = new_line(storage[fd]);
	if (!line)
		return (ft_free(&storage[fd]));
	storage[fd] = clean_storage(storage[fd]);
	return (line);
}
