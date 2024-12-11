/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconiat <sconiat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 09:29:09 by sconiat           #+#    #+#             */
/*   Updated: 2024/09/23 09:01:09 by sconiat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char *s, int *cpt)
{
	int	i;

	i = 0;
	if (!s)
	{
		ft_putstr("(null)", cpt);
		return ;
	}
	while (s[i])
	{
		ft_putchar(s[i], cpt);
		i++;
	}
}
