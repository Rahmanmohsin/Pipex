/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:03:32 by mohrahma          #+#    #+#             */
/*   Updated: 2024/03/20 14:27:04 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int	ft_strlen(const char *s)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i] != '\0')
// 		i++;
// 	return (i);
// }

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d_len;
	size_t	s_len;
	size_t	t_len;

	d_len = 0;
	s_len = 0;
	while (dst[d_len] != '\0' && d_len < dstsize)
		d_len++;
	t_len = d_len + ft_strlen(src);
	if (d_len == dstsize)
		return (t_len);
	while (src[s_len] != '\0' && (d_len + s_len) < dstsize - 1)
	{
		dst[d_len + s_len] = src[s_len];
		s_len++;
	}
	dst[d_len + s_len] = '\0';
	return (t_len);
}
