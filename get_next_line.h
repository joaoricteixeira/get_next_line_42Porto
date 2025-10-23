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

#include <stddef.h>

void	ft_putstr(char *str);
void	*ft_memmove(void *dest_str, const void *src_str, size_t n);
char	*ft_leftover(char *stash, int *len, int i);

#endif
