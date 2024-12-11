/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconiat <sconiat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:50:06 by sconiat           #+#    #+#             */
/*   Updated: 2024/09/29 13:28:23 by sconiat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "libft/libft.h"

volatile int	g_ack = 0;

void	sig_handler(int signum)
{
	if (signum == SIGUSR1)
	{
		g_ack = 0;
		ft_printf("SUCCESS : Message fully send\n");
		exit(EXIT_SUCCESS);
	}
	if (signum == SIGUSR2)
		g_ack = 1;
}

void	char_to_bin(unsigned char c, int pid)
{
	int	index;
	int	timer;

	timer = 0;
	index = 7;
	while (index >= 0)
	{
		g_ack = 0;
		if (c >> index & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (!g_ack)
			;
		index--;
	}
}

void	send_len(size_t len, pid_t server_id)
{
	int	index;

	index = sizeof(size_t) * 8 - 1;
	while (index >= 0)
	{
		g_ack = 0;
		if (len >> index & 1)
			kill(server_id, SIGUSR1);
		else
			kill(server_id, SIGUSR2);
		while (!g_ack)
			;
		index--;
	}
}

void	send_msg(char *msg, pid_t server_id)
{
	int	byte_index;

	byte_index = 0;
	send_len(ft_strlen(msg), server_id);
	while (msg[byte_index])
	{
		char_to_bin(msg[byte_index], server_id);
		byte_index++;
	}
	char_to_bin(msg[byte_index], server_id);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	pid_t				server_id;

	if (argc != 3 || ft_strlen(argv[2]) == 0 || !argv[2])
	{
		ft_printf("Error arg\n");
		return (1);
	}
	server_id = ft_atoi(argv[1]);
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sa.sa_handler = sig_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	send_msg(argv[2], server_id);
	return (0);
}
