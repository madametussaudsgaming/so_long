/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:06:07 by rpadasia          #+#    #+#             */
/*   Updated: 2025/04/25 16:06:18 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "get_next_line_bonus.h"

// void	*ft_calloc(size_t	count, size_t	size)
// {
// 	unsigned char	*temp;
// 	size_t			i;

// 	i = 0;
// 	if (size != 0 && count > SIZE_MAX / size)
// 		return (NULL);
// 	temp = malloc(count * size);
// 	if (temp == NULL)
// 		return (NULL);
// 	while (i < count * size)
// 	{
// 		temp[i] = 0;
// 		i++;
// 	}
// 	return (temp);
// }

// char	*ft_strjoin(const char	*s1, const char	*s2)
// {
// 	char	*res;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	if (!s1 || !s2)
// 		return (NULL);
// 	res = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
// 	if (!res)
// 		return (NULL);
// 	while (s1[i])
// 		res[j++] = s1[i++];
// 	i = 0;
// 	while (s2[i])
// 		res[j++] = s2[i++];
// 	res[j] = '\0';
// 	return (res);
// }

// size_t	ft_strlen(const	char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i] != '\0')
// 		i++;
// 	return (i);
// }

// char	*ft_strchr(const char *s, int c)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i] != '\0')
// 	{
// 		if (s[i] == (char)c)
// 			return ((char *) &s[i]);
// 		i++;
// 	}
// 	if (s[i] == (char)c)
// 		return ((char *) &s[i]);
// 	return (NULL);
// }
