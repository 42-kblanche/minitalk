/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff_substr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblanche <kblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:45:09 by kblanche          #+#    #+#             */
/*   Updated: 2026/01/22 06:06:50 by kblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../buffft.h"
#include "../libft.h"
#include <stddef.h>

t_buff	ft_buff_substr(t_buff *self, size_t index, size_t len)
{
	t_buff	ret;

	ret.buff = ft_memdup(self->buff + index, len);
	ret.max_size = len;
	ret.curr_size = len;
	return (ret);
}
