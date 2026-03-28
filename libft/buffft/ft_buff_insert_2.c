/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff_insert_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblanche <kblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 19:16:25 by kblanche          #+#    #+#             */
/*   Updated: 2026/01/28 20:16:12 by kblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../buffft.h"
#include "../libft.h"
#include <stdlib.h>

size_t	ft_buff_insert_int(t_buff *self, size_t index, const int n)
{
	char	*str;
	size_t	ret;

	str = ft_itoa(n);
	ret = ft_buff_insert(self, index, str, ft_strlen(str));
	free(str);
	return (ret);
}

size_t	ft_buff_insert_percent(t_buff *self, size_t index)
{
	const char	*str = "%";
	size_t		ret;

	ret = ft_buff_insert(self, index, str, ft_strlen(str));
	return (ret);
}

size_t	ft_buff_insert_ptr(t_buff *self, size_t index, const void *p)
{
	char	*str;
	size_t	ret;

	str = ft_ptoh(p);
	ret = ft_buff_insert(self, index, str, ft_strlen(str));
	free(str);
	return (ret);
}

size_t	ft_buff_insert_uint(t_buff *self, size_t index, const t_uint n)
{
	char	*str;
	size_t	ret;

	str = ft_uitoa(n);
	ret = ft_buff_insert(self, index, str, ft_strlen(str));
	free(str);
	return (ret);
}
