/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <rpadasia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:45:15 by rpadasia          #+#    #+#             */
/*   Updated: 2025/01/28 13:27:09 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format(const char	*str, va_list args, int i);

int	ft_printf(const char *tbprint, ...)
{
	va_list	args;
	int		count;
	int		j;

	j = 0;
	count = 0;
	va_start(args, tbprint);
	while (tbprint[j] != '\0')
	{
		if (tbprint[j] == '%')
		{
			count += format(tbprint, args, ++j);
			if (count < 0)
				return (-1);
		}
		else
		{
			count += ft_print_c(tbprint[j]);
			if (count < 0)
				return (-1);
		}
		j++;
	}
	va_end(args);
	return (count);
}

static int	format(const char	*str, va_list arg, int i)
{
	int	count;

	count = 0;
	if (str[i] == 'c')
		count += ft_print_c((char) va_arg(arg, int));
	else if (str[i] == 's')
		count += ft_print_s((char *) va_arg(arg, char *));
	else if (str[i] == 'd' || str[i] == 'i')
		count += ft_print_d((int) va_arg(arg, int));
	else if (str[i] == 'u')
		count += ft_print_u((unsigned int) va_arg(arg, unsigned int));
	else if (str[i] == 'x' || str[i] == 'X')
		count += ft_print_x((unsigned int) va_arg(arg, unsigned int), str[i]);
	else if (str[i] == 'p')
		count += ft_print_p((uintptr_t) va_arg(arg, uintptr_t));
	else if (str[i] == '%')
		count += ft_print_c('%');
	return (count);
}
