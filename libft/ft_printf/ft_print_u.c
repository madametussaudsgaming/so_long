/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <rpadasia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:54:57 by rpadasia          #+#    #+#             */
/*   Updated: 2025/01/28 13:17:26 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putorinbr(int nbr)
{
	int	count;

	count = 0;
	if (nbr == -2147483648)
		count += ft_print_s("-2147483648");
	else if (nbr < 0)
	{
		count += ft_print_c('-');
		nbr = -nbr;
		count += ft_putorinbr(nbr);
	}
	else
	{
		if (nbr >= 10)
		{
			count += ft_putorinbr(nbr / 10);
			count += ft_putorinbr(nbr % 10);
		}
		else
			count += ft_print_c(nbr + 48);
	}
	return (count);
}

int	ft_putunbr(unsigned int nb)
{
	int	printable;

	printable = 0;
	if (nb >= 10)
	{
		printable += ft_putorinbr(nb / 10);
		printable += ft_putorinbr(nb % 10);
	}
	else
		printable += ft_print_c(nb + 48);
	return (printable);
}

int	ft_print_u(unsigned int n)
{
	return (ft_putunbr(n));
}
