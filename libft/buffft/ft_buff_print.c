/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblanche <kblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:59:17 by kblanche          #+#    #+#             */
/*   Updated: 2026/01/27 21:36:19 by kblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../buffft.h"
#include <unistd.h>

void	ft_buff_print(const t_buff *self, int fd)
{
	write(fd, self->buff, self->curr_size);
}
