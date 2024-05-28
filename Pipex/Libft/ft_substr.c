/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 23:31:40 by mohrahma          #+#    #+#             */
/*   Updated: 2023/12/05 23:31:40 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	i;
	int		j;

	i = 0;
	j = start;
	if (start >= ft_strlen(s))
		return (sub_s = ft_strdup(""), sub_s);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sub_s = malloc((len + 1) * sizeof(char));
	if (!sub_s)
		return (NULL);
	while (s[j] != '\0' && i < len)
		sub_s[i++] = s[j++];
	sub_s[i] = '\0';
	return (sub_s);
}
