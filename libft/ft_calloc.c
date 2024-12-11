/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconiat <sconiat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 10:15:50 by sconiat           #+#    #+#             */
/*   Updated: 2024/09/05 11:33:33 by sconiat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*res;

	if (size != 0 && nitems > ((size_t) -1 / size))
		return (NULL);
	res = malloc(size * nitems);
	if (!res)
		return (NULL);
	ft_bzero(res, size * nitems);
	return (res);
}
