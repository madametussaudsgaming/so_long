/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:47:55 by rpadasia          #+#    #+#             */
/*   Updated: 2025/04/13 16:06:00 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**word_array(char const *s, char c)
{
	int	i;
	int	wc;

	wc = 0;
	i = 0;
	while (s[i])
		if (s[i++] != c && (s[i] == c || s[i] == '\0'))
			wc++;
	return ((char **)malloc((wc + 1) * sizeof(char *)));
}

char	*ft_strndup(const char *s, size_t n)
{
	char	*res;
	size_t	i;

	res = malloc(sizeof(char) * (n + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < n && s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		j;
	int		k;

	result = word_array(s, c);
	i = 0;
	j = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[j] && s[j] != c)
			j++;
		if (j > i)
		{
			result[k] = ft_strndup(s + i, j - i);
			k++;
		}
		i = j;
	}
	result[k] = NULL;
	return (result);
}
