/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconiat <sconiat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 17:55:50 by sconiat           #+#    #+#             */
/*   Updated: 2024/09/28 18:54:39 by sconiat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "libft/libft.h"

volatile char	*g_msg = NULL;

void	bin_to_char(int signum, int index)
{
	if (signum == SIGUSR1)
		g_msg[index] = (g_msg[index] << 1) | 1;
	else if (signum == SIGUSR2)
		g_msg[index] <<= 1;
}

void	print_msg(pid_t *client_id)
{
	kill(*client_id, SIGUSR1);
	*client_id = 0;
	ft_printf("%s", g_msg);
	ft_printf("\nSUCCESS : Message fully received\n");
	free((void *)g_msg);
	g_msg = NULL;
}
