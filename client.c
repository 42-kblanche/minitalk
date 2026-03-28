/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblanche <kblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 11:03:20 by kblanche          #+#    #+#             */
/*   Updated: 2026/03/28 19:58:17 by kblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	}
}

void	send_string(int server_pid, char *str)
{
	size_t	i;

	while (str[i])
	{
		send_byte(server_pid, str[i]);
		++i;
	}
}

int	main(int argc, char **argv)
{
	int		server_pid;
	char	*str;

	if (argc != 3)
		write(STDERR_FILENO, ARG_ERROR, 25);
	server_pid = atoi(argv[1]);
	str = strdup(argv[2]);
	send_string(server_pid, str);
	free(str);
}
