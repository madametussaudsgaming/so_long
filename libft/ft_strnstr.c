/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:10:11 by rpadasia          #+#    #+#             */
/*   Updated: 2024/11/18 18:41:09 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*pool, const char	*tofind, size_t	len)
{
	size_t	i;
	size_t	j;

	if (ft_strlen(tofind) <= 0)
		return ((char *)pool);
	i = 0;
	if (len == 0)
		return (0);
	while ((pool[i] && i < len))
	{
		j = 0;
		while (pool[i + j] == tofind[j] && pool[i + j] && i + j < len)
		{
			j++;
			if (tofind[j] == 0)
				return ((char *) pool + i);
		}
		i++;
	}
	return (0);
}
