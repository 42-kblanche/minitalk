/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffft.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblanche <kblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 20:37:03 by kblanche          #+#    #+#             */
/*   Updated: 2026/01/25 01:42:42 by kblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFFT_H
# define BUFFFT_H

# include <stddef.h>

typedef unsigned int	t_uint;
typedef struct s_ft_buff
{
	char	*buff;
	size_t	curr_size;
	size_t	max_size;
}	t_buff;

void	ft_buff_append(t_buff *self, const char *buff, size_t size);
void	ft_buff_assign(t_buff *self, const char *str);
void	ft_buff_destroy(t_buff *self);
size_t	ft_buff_double_size(t_buff *self);
void	ft_buff_erase(t_buff *self, size_t index, size_t len);
t_buff	*ft_buff_init(t_buff *self);
t_buff	*ft_buff_init_str(t_buff *self, const char *str);
size_t	ft_buff_insert(t_buff *self, size_t index,
			const char *str, size_t size);
size_t	ft_buff_insert_char(t_buff *self, size_t index, const char c);
size_t	ft_buff_insert_hex_lo(t_buff *self, size_t index, const int n);
size_t	ft_buff_insert_hex_up(t_buff *self, size_t index, const int n);
size_t	ft_buff_insert_int(t_buff *self, size_t index, const int n);
size_t	ft_buff_insert_percent(t_buff *self, size_t index);
size_t	ft_buff_insert_ptr(t_buff *self, size_t index, const void *p);
size_t	ft_buff_insert_uint(t_buff *self, size_t index, const t_uint n);
void	ft_buff_print(const t_buff *self, int fd);
t_buff	ft_buff_substr(t_buff *self, size_t index, size_t len);

#endif
