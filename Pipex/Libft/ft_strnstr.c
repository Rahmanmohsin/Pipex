/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:23:27 by mohrahma          #+#    #+#             */
/*   Updated: 2024/03/20 14:28:09 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	s2_len;

	i = 0;
	j = 0;
	s2_len = 0;
	if (!(*s2))
		return ((char *)s1);
	while (s2[s2_len] != '\0')
		s2_len++;
	while (s1[i] != '\0' && i < n)
	{
		j = 0;
		while (s1[i + j] == s2[j] && (i + j) < n && s2[j] != '\0')
			j++;
		if (j == s2_len)
			return ((char *)s1 + i);
		i++;
	}
	return (NULL);
}
