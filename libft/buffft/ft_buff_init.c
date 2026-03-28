/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblanche <kblanche@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 20:43:04 by kblanche          #+#    #+#             */
/*   Updated: 2026/01/18 21:06:09 by kblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../buffft.h"
#include "../libft.h"

#include <stdlib.h>

t_buff	*ft_buff_init(t_buff *self)
{
	self->max_size = 0;
	self->curr_size = 0;
	self->buff = NULL;
	return (self);
}

t_buff	*ft_buff_init_str(t_buff *self, const char *str)
{
	size_t	str_len;

	str_len = ft_strlen(str);
	self->max_size = str_len;
	self->curr_size = str_len;
	self->buff = ft_calloc(str_len, sizeof(char));
	ft_memcpy(self->buff, str, str_len);
	return (self);
}
