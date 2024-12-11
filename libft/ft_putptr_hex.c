/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconiat <sconiat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:16:21 by sconiat           #+#    #+#             */
/*   Updated: 2024/09/23 09:01:05 by sconiat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putp_hex(uintptr_t n, int *cpt)
{
	char	*base;

	base = "0123456789abcdef";
	if (n >= 16)
	{
		ft_putp_hex(n / 16, cpt);
		ft_putp_hex(n % 16, cpt);
		return ;
	}
	ft_putchar(base[n], cpt);
}

void	ft_putptr_hex(uintptr_t p, int *cpt)
{
	if (!p)
	{
		ft_putstr("(nil)", cpt);
		return ;
	}
	ft_putstr("0x", cpt);
	ft_putp_hex(p, cpt);
}
