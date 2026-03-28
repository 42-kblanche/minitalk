/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff_destroy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblanche <kblanche@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:37:43 by kblanche          #+#    #+#             */
/*   Updated: 2026/01/08 17:41:04 by kblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../buffft.h"
#include <stdlib.h>

void	ft_buff_destroy(t_buff *self)
{
	free(self->buff);
	self->buff = NULL;
	self->max_size = 0;
	self->curr_size = 0;
}
