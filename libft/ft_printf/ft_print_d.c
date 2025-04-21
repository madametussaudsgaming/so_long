/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:57:36 by rpadasia          #+#    #+#             */
/*   Updated: 2024/12/09 18:09:33 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nbr)
{
	int	count;

	count = 0;
	if (nbr == -2147483648)
		count += ft_print_s("-2147483648");
	else if (nbr < 0)
	{
		count += ft_print_c('-');
		nbr = -nbr;
		count += ft_putnbr(nbr);
	}
	else
	{
		if (nbr >= 10)
		{
			count += ft_putnbr(nbr / 10);
			count += ft_putnbr(nbr % 10);
		}
		else
			count += ft_print_c(nbr + 48);
	}
	return (count);
}

int	ft_print_d(int nbr)
{
	int	count;

	count = 0;
	count += ft_putnbr(nbr);
	if (count < 0)
		return (-1);
	return (count);
}
