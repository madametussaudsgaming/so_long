/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:19:11 by rpadasia          #+#    #+#             */
/*   Updated: 2024/11/04 16:04:42 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptrtemp;

	ptrtemp = (unsigned char *)b;
	while (len > 0)
	{
		*ptrtemp = (unsigned char)c;
		ptrtemp++;
		len--;
	}
	return (b);
}
