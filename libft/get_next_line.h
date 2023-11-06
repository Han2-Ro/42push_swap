/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrother <hrother@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:23:07 by hrother           #+#    #+#             */
/*   Updated: 2023/11/06 18:49:28 by hrother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

size_t	gnl_strlen(const char *str);
char	*get_next_line(int fd);
int		get_i_of_newline(char *str);
char	*gnl_strjoin(const char *str, const char *buffer);
void	gnl_bzero(void *s, size_t n);
size_t	gnl_strlcpy(char *dst, const char *src, size_t size);

#endif
