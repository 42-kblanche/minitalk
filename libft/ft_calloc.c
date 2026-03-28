/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblanche <kblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:03:16 by kblanche          #+#    #+#             */
/*   Updated: 2026/03/24 15:57:05 by kblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <malloc.h>
#include <limits.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*s;
	size_t			i;

	s = 0;
	i = 0;
	if (nmemb != 0 && (UINT_MAX / nmemb < size))
		return (s);
	s = malloc(nmemb * size);
	if (!s)
		return (s);
	while (i < nmemb * size)
	{
		s[i] = 0;
		++i;
	}
	return ((void *)s);
}
