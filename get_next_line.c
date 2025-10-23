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
//#include <stdlib.h>
//#include <stdio.h>

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	stash[2000000];
	static int	len = 0;
	ssize_t		index;

	buffer = malloc(BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	while (1)
	{
		index = ft_find_newline(stash, len);
		if (index != -1)
		{
			free(buffer);
			return (ft_extract_line(stash, &len, index));
		}
		index = read(fd, buffer, BUFFER_SIZE);
		if (index <= 0)
		{
			free(buffer);
			return (ft_clean_stash(stash, &len));
		}
		ft_add_to_stash(stash, buffer, &len, index);
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
