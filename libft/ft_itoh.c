/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblanche <kblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 00:22:31 by kblanche          #+#    #+#             */
/*   Updated: 2026/03/24 15:57:20 by kblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define ITOH_LEN 50
#define HEX_ARR "0123456789abcdef"
#define HEX_ARR_LEN 16

char	*ft_itoh(unsigned int n)
{
	char			str[ITOH_LEN];
	size_t			i;
	const char		hex_arr[] = HEX_ARR;

	if (n == 0)
		return (ft_strdup("0"));
	i = ITOH_LEN - 1;
	str[i] = '\0';
	while (n > 0)
	{
		--i;
		str[i] = hex_arr[(n % HEX_ARR_LEN)];
		n /= HEX_ARR_LEN;
	}
	return (ft_strdup(str + i));
}
