/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblanche <kblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 00:22:31 by kblanche          #+#    #+#             */
/*   Updated: 2026/03/24 15:57:12 by kblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <malloc.h>
#define ITOA_LEN 50

static size_t	is_nb_negative(int n)
{
	if (n >= 0)
		return (0);
	else
		return (1);
}

char	*ft_uitoa(unsigned int n)
{
	char	ret[ITOA_LEN];
	size_t	i;

	if (n == 0)
		return (ft_strdup("0"));
	i = ITOA_LEN - 1;
	ret[i] = '\0';
	while (n > 0)
	{
		--i;
		ret[i] = '0' + (n % 10);
		n /= 10;
	}
	return (ft_strdup(ret + i));
}

char	*ft_itoa(int n)
{
	char	ret[ITOA_LEN];
	size_t	i;
	size_t	is_negative;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	is_negative = is_nb_negative(n);
	if (is_negative)
		n *= -1;
	i = ITOA_LEN - 1;
	ret[i] = '\0';
	while (n > 0)
	{
		--i;
		ret[i] = '0' + (n % 10);
		n /= 10;
	}
	if (is_negative)
		ret[--i] = '-';
	return (ft_strdup(ret + i));
}
