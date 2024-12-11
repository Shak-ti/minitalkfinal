/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconiat <sconiat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 09:27:07 by sconiat           #+#    #+#             */
/*   Updated: 2024/09/23 09:01:02 by sconiat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_bonus(int n, int *cpt, int b)
{
	if (b == 3 && n >= 0)
		ft_putchar(' ', cpt);
	else if (b == 4 && n >= 0)
		ft_putchar('+', cpt);
	return (0);
}

void	ft_putnbr(int n, int *cpt, int b)
{
	long	nbr;

	nbr = (long) n;
	b = ft_bonus(n, cpt, b);
	if (nbr < 0)
	{
		nbr = nbr * (-1);
		ft_putchar('-', cpt);
	}
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10, cpt, b);
		ft_putnbr(nbr % 10, cpt, b);
		return ;
	}
	ft_putchar('0' + nbr, cpt);
}
