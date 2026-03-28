/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblanche <kblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 08:26:19 by kblanche          #+#    #+#             */
/*   Updated: 2026/03/24 15:57:52 by kblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_strfind(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	haystack_len;
	size_t	needle_len;
	int		r;

	i = 0;
	haystack_len = ft_strlen(haystack);
	needle_len = ft_strlen(needle);
	if (needle_len > haystack_len)
		return (-1);
	while (i + needle_len <= haystack_len)
	{
		if (haystack[i] == needle[0])
		{
			r = ft_strncmp(haystack + i, needle, needle_len);
			if (r == 0)
				return (i);
		}
		++i;
	}
	return (-1);
}

ssize_t	ft_bufffind(const char *haystack, const char *needle, size_t max_len)
{
	size_t	i;
	size_t	needle_len;
	int		r;

	i = 0;
	needle_len = ft_strlen(needle);
	if (needle_len > max_len)
		return (-1);
	while (i + needle_len <= max_len)
	{
		if (haystack[i] == needle[0])
		{
			r = ft_strncmp(haystack + i, needle, needle_len);
			if (r == 0)
				return (i);
		}
		++i;
	}
	return (-1);
}
