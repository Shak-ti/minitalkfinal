/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconiat <sconiat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:36:48 by sconiat           #+#    #+#             */
/*   Updated: 2024/09/23 09:00:57 by sconiat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_bonus_u(int *cpt, int b)
{
	if (b == 3)
		ft_putchar(' ', cpt);
	else if (b == 4)
		ft_putchar('+', cpt);
	return (0);
}

void	ft_putnbr_u(unsigned int nbr, int *cpt, int b)
{
	long	n;

	n = (long)nbr;
	b = ft_bonus_u(cpt, b);
	if (nbr >= 10)
	{
		ft_putnbr_u(nbr / 10, cpt, b);
		ft_putnbr_u(nbr % 10, cpt, b);
		return ;
	}
	ft_putchar('0' + nbr, cpt);
}
