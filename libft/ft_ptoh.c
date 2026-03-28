/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblanche <kblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 00:22:31 by kblanche          #+#    #+#             */
/*   Updated: 2026/03/24 15:57:33 by kblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>
#define PTOH_LEN 50
#define NIL_STR "(nil)"
#define HEX_ARR "0123456789abcdef"
#define HEX_ARR_LEN 16

char	*ft_ptoh(const void *ptr)
{
	char		str[PTOH_LEN];
	uintptr_t	temp;
	size_t		i;
	const char	hex_arr[] = HEX_ARR;

	if (!ptr)
		return (ft_strdup(NIL_STR));
	temp = (uintptr_t)ptr;
	i = PTOH_LEN - 1;
	str[i] = '\0';
	while (temp > 0 && i > 0)
	{
		--i;
		str[i] = hex_arr[(temp % HEX_ARR_LEN)];
		temp /= HEX_ARR_LEN;
	}
	str[--i] = 'x';
	str[--i] = '0';
	return (ft_strdup(str + i));
}
