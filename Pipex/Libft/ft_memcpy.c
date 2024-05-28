/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:14:52 by mohrahma          #+#    #+#             */
/*   Updated: 2024/03/20 14:14:37 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*dst_address;

	dst_address = dst;
	while (n > 0 && dst != src)
	{
		*(char *)dst = *(char *)src;
		dst++;
		src++;
		n--;
	}
	return (dst_address);
}
