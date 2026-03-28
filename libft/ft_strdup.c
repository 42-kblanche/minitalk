/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblanche <kblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:59:38 by kblanche          #+#    #+#             */
/*   Updated: 2026/03/24 15:57:45 by kblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*t;
	size_t	i;
	size_t	size;

	i = 0;
	size = ft_strlen(s) + 1;
	t = (char *)ft_calloc(size, sizeof(char));
	if (!t)
		return (0);
	while (i < size)
	{
		t[i] = s[i];
		++i;
	}
	return (t);
}

char	*ft_memdup(const char *buff, size_t size)
{
	char	*t;

	t = ft_calloc(size, sizeof(char));
	if (!t)
		return (0);
	ft_memcpy(t, buff, size);
	return (t);
}
