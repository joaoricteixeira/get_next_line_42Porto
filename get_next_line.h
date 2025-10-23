/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joateixe <joateixe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 16:08:01 by joateixe          #+#    #+#             */
/*   Updated: 2025/10/20 16:08:27 by joateixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE 
#  define BUFFER_SIZE 1
# endif

# include <stddef.h>
# include <stdlib.h>

char	*get_next_line(int fd);
void	*ft_memmove(void *dest_str, const void *src_str, size_t n);
int		ft_find_newline(const char *stash, int len);
char	*ft_extract_line(char *stash, int *len, int nl);
char	*ft_clean_stash(char *stash, int *len);
void	ft_add_to_stash(char *stash, const char *buffer,
			int *len, size_t bytes);

#endif
