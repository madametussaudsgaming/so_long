/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <rpadasia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:08:53 by rpadasia          #+#    #+#             */
/*   Updated: 2025/01/28 14:14:58 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdint.h>

# if defined(__linux__)
#  define NULL_PTR_REPR "(nil)"
# else
#  define NULL_PTR_REPR "0x0"
# endif

int		ft_printf(const char *tbprint, ...);
int		ft_print_c(char c);
int		ft_print_s(char *s);
int		ft_print_d(int nbr);
int		ft_print_u(unsigned int n);
int		ft_print_p(uintptr_t ptr);
int		ft_print_x(unsigned int nbr, int format);

#endif
