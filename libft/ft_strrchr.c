/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:46:24 by rpadasia          #+#    #+#             */
/*   Updated: 2024/11/14 11:43:54 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			*ret;
	char			cc;

	ret = NULL;
	cc = (char) c;
	i = 0;
	while (s[i])
	{
		if (s[i] == cc)
			ret = (char *) &s[i];
		i++;
	}
	if (s[i] == cc)
		ret = (char *) &s[i];
	return (ret);
}
