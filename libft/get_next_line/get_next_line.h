/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <rpadasia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:39:35 by rpadasia          #+#    #+#             */
/*   Updated: 2024/12/16 15:45:50 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>

void	*ft_calloc(size_t	count, size_t	size);
char	*ft_strjoin(const char	*s1, const char	*s2);
size_t	ft_strlen(const	char *s);
char	*get_next_line(int fd);
char	*read_and_update_buffer(int fd, char *res);
char	*extract_current_line(const char *buffer);
char	*update_buffer_after_line(char *buffer);
char	*append_to_buffer(char *existing_buffer, char *buffy);
char	*ft_strchr(const char *s, int c);

#endif
