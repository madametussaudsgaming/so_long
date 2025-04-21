/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <rpadasia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:41:30 by rpadasia          #+#    #+#             */
/*   Updated: 2024/12/16 15:10:04 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_ptr(uintptr_t n)
{
	char	*reference;
	int		count;

	reference = "0123456789abcdef";
	count = 0;
	if (n >= 16)
	{
		count += ft_put_ptr(n / 16);
		if (count < 0)
			return (-1);
		count += ft_put_ptr(n % 16);
		if (count < 0)
			return (-1);
	}
	else
		count += ft_print_c(reference[n]);
	return (count);
}

int	ft_print_p(uintptr_t ptr)
{
	int	count;

	count = 0;
	if (ptr == 0)
		return (ft_print_s(NULL_PTR_REPR));
	count += ft_print_s("0x");
	if (count < 0)
		return (-1);
	count += ft_put_ptr(ptr);
	if (count < -1)
		return (-1);
	return (count);
}
