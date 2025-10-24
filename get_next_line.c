/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joateixe <joateixe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:31:33 by joateixe          #+#    #+#             */
/*   Updated: 2025/10/22 15:32:23 by joateixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

char	*ft_handle_eof_or_error(ssize_t bytes, char *stash, int *len)
{
	if (bytes == -1)
	{
		*len = 0;
		stash[0] = '\0';
		return (NULL);
	}
	return (ft_clean_stash(stash, len));
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	stash[2000000];
	static int	len = 0;
	ssize_t		index;
	ssize_t		bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (1)
	{
		index = ft_find_newline(stash, len);
		if (index != -1)
			return (free(buffer), ft_extract_line(stash, &len, index));
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
			return (free(buffer), ft_handle_eof_or_error(bytes, stash, &len));
		buffer[bytes] = '\0';
		ft_add_to_stash(stash, buffer, &len, bytes);
	}
}
/*
int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			printf("Cannot read file.\n");
			return (1);
		}
		line = get_next_line(fd);
		while (line != NULL)
		{
			free(line);
			line = get_next_line(fd);
		}
		close(fd);
	}
	else if (argc > 2)
	{
		printf("Too many arguments.\n");
		return (1);
	}
	else
	{
		printf("File name missing.\n");
		return (1);
	}
	return (0);
}*/
