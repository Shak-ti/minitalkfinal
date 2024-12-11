/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconiat <sconiat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:10:18 by sconiat           #+#    #+#             */
/*   Updated: 2024/09/23 09:00:36 by sconiat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(const char *c, int id)
{
	char	*s;
	char	*b;
	int		i;

	i = 0;
	b = "# +";
	s = "cspdiuxX";
	while (s[i])
	{
		if (b[i] && c[id] == b[i] && c[id + 1] && in_set(c, id + 1))
			return (i + 2);
		if (c[id] == s[i] || c[id] == '%')
			return (1);
		i++;
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		cpt;
	int		i;

	i = 0;
	cpt = 0;
	if (!str)
		return (-1);
	va_start (args, str);
	while (str[i])
	{
		if (str[i] == '%' && in_set(str, i + 1))
		{
			i = i + ft_choice((str + i + 1), args, &cpt, in_set(str, i + 1));
		}
		else if (str[i] == '%' && !in_set(str, i + 1))
			return (-1);
		else
			ft_putchar(str[i], &cpt);
		i++;
	}
	va_end (args);
	return (cpt);
}
