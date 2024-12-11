/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconiat <sconiat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:50:16 by sconiat           #+#    #+#             */
/*   Updated: 2024/09/29 13:43:52 by sconiat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "libft/libft.h"

void	bin_to_char(int signum, int index);
void	print_msg(pid_t *client_id);
extern volatile char	*g_msg;

void	receiving_size(int signum, pid_t client_id)
{
	static size_t	msg_size = 0;
	static int		itr_bit = 0;
	static int		index = 0;

	if (signum == SIGUSR1)
		msg_size = msg_size << 1 | 1;
	else
		msg_size = msg_size << 1 | 0;
	itr_bit++;
	if (itr_bit == sizeof(size_t) * 8)
	{
		g_msg = malloc(sizeof(char) * (msg_size + 1));
		if (!g_msg)
		{
			ft_printf("Error : allocation failure\n");
			exit(EXIT_FAILURE);
		}
		itr_bit = 0;
		index = 0;
		msg_size = 0;
		kill(client_id, SIGUSR2);
		return ;
	}
	kill(client_id, SIGUSR2);
}

void	verif_id(pid_t *client_id, pid_t pid_to_test)
{
	if (*client_id && *client_id != pid_to_test)
	{
		ft_printf("ERROR : different clients send simultaneous messages\n");
		return ;
	}
	if (!*client_id)
	{
		*client_id = pid_to_test;
		ft_printf("NEW CLIENT : %d\n", pid_to_test);
	}
}

void	sig_action(int signum, siginfo_t *info, void *context)
{
	static pid_t			client_id = 0;
	static int				itr_bit = 0;
	static size_t			index = 0;

	(void) context;
	verif_id(&client_id, info->si_pid);
	if (!g_msg)
		receiving_size(signum, client_id);
	else
	{
		bin_to_char(signum, index);
		itr_bit++;
		if (itr_bit == 8)
		{
			itr_bit = 0;
			if (g_msg[index] == '\0')
			{
				index = 0;
				print_msg(&client_id);
				return ;
			}
			index++;
		}
	}
	kill(client_id, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID : %d\nLISTENING TO SIGNALS...\n", getpid());
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sa.sa_sigaction = sig_action;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
