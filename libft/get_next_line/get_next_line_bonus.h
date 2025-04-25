/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:57:23 by rpadasia          #+#    #+#             */
/*   Updated: 2025/04/25 16:07:42 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef MAX_FDS
#  define MAX_FDS 1024
# endif

# include "../libft.h"
# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>

// void	*ft_calloc(size_t	count, size_t	size);
// char	*ft_strjoin(const char	*s1, const char	*s2);
// size_t	ft_strlen(const	char *s);
char	*get_next_line(int fd);
char	*read_and_update_buffer(int fd, char *res);
char	*extract_current_line(const char *buffer);
char	*update_buffer_after_line(char *buffer);
char	*append_to_buffer(char *existing_buffer, char *buffy);
// char	*ft_strchr(const char *s, int c);

#endif
