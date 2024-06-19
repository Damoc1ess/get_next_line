/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:44:26 by fflamion          #+#    #+#             */
/*   Updated: 2024/06/11 15:51:48 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		return (ft_free(&new_storage));
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
		return (ft_free(&line));
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
	static char	*storage = {0};
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if ((storage && !ft_strchr(storage, '\n')) || !storage)
		storage = readline (fd, storage);
	if (!storage)
		return (NULL);
	line = new_line(storage);
	if (!line)
		return (ft_free(&storage));
	storage = clean_storage(storage);
	return (line);
}
