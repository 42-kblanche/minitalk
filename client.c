/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblanche <kblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 11:03:20 by kblanche          #+#    #+#             */
/*   Updated: 2026/03/29 19:27:46 by kblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "./libft/printfft.h"
#include <signal.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define ARG_ERROR "ERROR: this program takes exactly 2 arguments\n"

void	send_byte(int server_pid, char to_send)
{
	size_t	i;

	i = 0;
	while (i < 8)
	{
		if ((to_send & 128) == 0)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		to_send <<= 1;
		++i;
		usleep(5000);
	}
}

void	send_string(int server_pid, char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		send_byte(server_pid, str[i]);
		++i;
	}
	send_byte(server_pid, '\0');
}

int	main(int argc, char **argv)
{
	int		server_pid;
	char	*str;

	if (argc != 3)
	{
		ft_errorf(ARG_ERROR);
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	str = ft_strdup(argv[2]);
	send_string(server_pid, str);
	free(str);
}
