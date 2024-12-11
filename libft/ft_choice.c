/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choice.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconiat <sconiat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 08:31:14 by sconiat           #+#    #+#             */
/*   Updated: 2024/09/23 13:38:14 by sconiat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_choice(const char *format, va_list args, int *cpt, int b)
{
	int	i;

	i = 0;
	if (b != 1)
		i = 1;
	if (format[i] == 's')
		ft_putstr(va_arg(args, char *), cpt);
	else if (format[i] == 'c')
		ft_putchar(va_arg(args, int), cpt);
	else if (format[i] == 'd' || format[i] == 'i')
		ft_putnbr(va_arg(args, int), cpt, b);
	else if (format[i] == 'p')
		ft_putptr_hex((uintptr_t) va_arg(args, void *), cpt);
	else if (format[i] == 'u')
		ft_putnbr_u(va_arg(args, unsigned int), cpt, b);
	else if (format[i] == 'x')
		ft_putnbr_hex(va_arg(args, unsigned int), 0, cpt, b);
	else if (format[i] == 'X')
		ft_putnbr_hex(va_arg(args, unsigned int), 1, cpt, b);
	else if (format[i] == '%')
		ft_putchar('%', cpt);
	if (b == 1)
		return (1);
	return (2);
}
