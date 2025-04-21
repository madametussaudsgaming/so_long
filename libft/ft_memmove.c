/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:43:10 by rpadasia          #+#    #+#             */
/*   Updated: 2024/11/18 17:03:56 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void	*src, size_t	len)
{
	char	*tempsrc;
	char	*tempdest;
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	tempsrc = (char *) src;
	tempdest = (char *) dst;
	if (tempdest > tempsrc)
	{
		while (len-- > 0)
		{
			tempdest[len] = tempsrc[len];
		}
	}
	else
	{
		while (i < len)
		{
			tempdest[i] = tempsrc[i];
			i++;
		}
	}
	return (dst);
}
