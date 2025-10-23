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
#include <stdlib.h>

char	*get_next_line(int fd)
{
	char		buffer[4];
	int			bytes_read;
	int			i;
	static char	stash[5000];
	static int	len = 0;
	char		*line;

	while (1)
	{
		i = 0;
		while (i < len && stash[i] != '\n')
			i++;
		if (i < len)
		{
			line = ft_leftover(stash, &len, i);
			return (line);
		}
		bytes_read = read(fd, buffer, sizeof(buffer));
		if (bytes_read <= 0)
		{
			if (len > 0)
			{
				line = malloc(len + 1);
				if (!line)
					return (NULL);
				ft_memmove(line, stash, len);
				line[len] = '\0';
				len = 0;
				ft_putstr(line);
				return (line);
			}
			return (NULL);
		}
		i = 0;
		while (i < bytes_read)
		{
			stash[len] = buffer[i];
			len++;
			i++;
		}
	}
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			ft_putstr("Cannot read file.\n");
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
		ft_putstr("Too many arguments.\n");
		return (1);
	}
	else
	{
		ft_putstr("File name missing.\n");
		return (1);
	}
	return (0);
}
