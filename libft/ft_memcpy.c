/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:26:43 by rpadasia          #+#    #+#             */
/*   Updated: 2024/11/18 17:45:55 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*dst, const void	*src, size_t	n)
{
	unsigned char	*tempdest;
	unsigned char	*tempsrc;
	size_t			i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	tempsrc = (unsigned char *) src;
	tempdest = (unsigned char *) dst;
	while (n > 0)
	{
		tempdest[i] = tempsrc[i];
		i++;
		n--;
	}
	return (dst);
}
