/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joateixe <joateixe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 16:07:30 by joateixe          #+#    #+#             */
/*   Updated: 2025/10/20 16:09:01 by joateixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include "get_next_line.h"

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

int	ft_find_newline(const char *stash, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (stash[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_extract_line(char *stash, int *len, int index)
{
	char	*line;
	int		line_len;
	int		remaining;

	line_len = index + 1;
	remaining = *len - line_len;
	line = malloc(line_len + 1);
	if (!line)
		return (NULL);
	ft_memmove(line, stash, line_len);
	line[line_len] = '\0';
	ft_memmove(stash, stash + line_len, remaining);
	*len = remaining;
	stash[*len] = '\0';
	return (line);
}

char	*ft_clean_stash(char *stash, int *len)
{
	char	*line;

	if (*len <= 0)
		return (NULL);
	line = malloc(*len + 1);
	if (!line)
		return (NULL);
	ft_memmove(line, stash, *len);
	line[*len] = '\0';
	*len = 0;
	stash[0] = '\0';
	return (line);
}

void	ft_add_to_stash(char *stash, const char *buffer, int *len, size_t bytes)
{
	ft_memmove(stash + *len, buffer, bytes);
	*len += bytes;
	stash[*len] = '\0';
}
