/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconiat <sconiat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:21:05 by sconiat           #+#    #+#             */
/*   Updated: 2024/09/23 09:00:53 by sconiat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_bonus_hex(int n, int maj, int *cpt, int b)
{
	if (!n)
		return (0);
	if (b == 2)
	{
		if (maj == 1)
			ft_putstr("0X", cpt);
		else
			ft_putstr("0x", cpt);
	}
	else if (b == 3)
		ft_putchar(' ', cpt);
	else if (b == 4)
	{
		if (n >= 0)
			ft_putchar('+', cpt);
		else
			ft_putchar('-', cpt);
	}
	return (0);
}

void	ft_putnbr_hex(unsigned int nbr, int maj, int *cpt, int b)
{
	long	n;
	char	*base;

	base = "0123456789abcdef";
	if (maj == 1)
		base = "0123456789ABCDEF";
	b = ft_bonus_hex(nbr, maj, cpt, b);
	n = (long) nbr;
	if (n >= 16)
	{
		ft_putnbr_hex(n / 16, maj, cpt, b);
		ft_putnbr_hex(n % 16, maj, cpt, b);
		return ;
	}
	ft_putchar(base[n], cpt);
}
