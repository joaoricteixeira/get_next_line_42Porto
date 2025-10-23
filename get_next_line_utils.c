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

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

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

char	*ft_leftover(char *stash, int *len, int i)
{
	char	*line;
	int		new_len;

	line = malloc(i + 2);
	if (!line)
		return (NULL);
	ft_memmove(line, stash, i + 1);
	line[i + 1] = '\0';
	new_len = *len - (i + 1);
	ft_memmove(stash, stash + i + 1, new_len);
	*len = new_len;
	ft_putstr(line);
	return (line);
}
