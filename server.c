/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblanche <kblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 10:12:14 by kblanche          #+#    #+#             */
/*   Updated: 2026/03/29 19:08:29 by kblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/printfft.h"
#include "libft/buffft.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

#define REC_SU1 "SIGUSR1 received\n"
#define REC_SU2 "SIGUSR2 received\n"
#define REC_UNK "Unknown signal received\n"
#define BUFFER_SIZE 100

static t_buff	g_buffer;
t_buff	tmp;

void	interpret_bit(int value)
{
	static size_t	current_bit = 0;
	static char		current_byte = 0;

	if (value != 0 && value != 1)
		return ;
	if (current_bit != 0)
		current_byte <<= 1;
	current_byte |= value;
	current_bit++;
	if (current_bit == 8)
	{
		ft_buff_append(&tmp, "  received char: ", 17);
		ft_buff_append(&tmp, &current_byte, 1);
		ft_buff_append(&tmp, "\n", 1);
		ft_buff_append(&g_buffer, &current_byte, 1);
		if (!current_byte)
		{
			ft_buff_print(&g_buffer, STDOUT_FILENO);
			ft_buff_destroy(&g_buffer);
			ft_buff_init(&g_buffer);
		}
		current_byte = 0;
		current_bit = 0;
	}
}

void	receive_sig(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_buff_append(&tmp, "0", 1);
		interpret_bit(0);
	}
	else if (sig == SIGUSR2)
	{
		ft_buff_append(&tmp, "1", 1);
		interpret_bit(1);
	}
	else
	{
	 	ft_buff_print(&tmp, STDOUT_FILENO);
		ft_buff_destroy(&tmp);
		exit(0);
	}
}

int	main(void)
{
	ft_buff_init_str(&tmp, "SERVER LOG:              \n");

	// struct sigaction	act;

	ft_buff_init(&g_buffer);
	ft_buff_double_size(&g_buffer);
	// act.sa_handler = receive_sig;
	ft_printf("SERVER PID: %i \n", getpid());
	// sigaction(SIGUSR1, &act, NULL);
	// sigaction(SIGUSR2, &act, NULL);
	// sigaction(SIGUSR2, &act, NULL);
	signal(SIGUSR1, receive_sig);
	signal(SIGUSR2, receive_sig);
	signal(SIGINT, receive_sig);
	while (1)
		pause();
}
