#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

void	*ft_memmove(void *dest_str, const void *src_str, size_t n)
{
	unsigned char		*dest;
	const unsigned char	*src;

	dest = (unsigned char *)dest_str;
	src = (const unsigned char *)src_str;
	if (dest < src)
	{
		while (n--)
			*dest++ = *src++;
	}
	else
	{
		dest += n;
		src += n;
		while (n--)
		{
			*(--dest) = *(--src);
		}
	}
	return (dest_str);
}


char	*get_next_line(int fd)
{
	char		buffer[4];
	int			bytes_read;
	int			i;
	static char	stash[5000];
	static int	len = 0;
	char		*line;
	int			new_len;

	while (1)
	{
		i = 0;
		while (i < len && stash[i] != '\n')
			i++;
		if (i < len)
		{
			line = malloc(i + 2);
			if (!line)
				return (NULL);
			ft_memmove(line, stash, i + 1);
			line[i + 1] = '\0';
			new_len = len - (i + 1);
			ft_memmove(stash, stash + i + 1, new_len);
			len = new_len;
			ft_putstr(line);
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
