/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:22:50 by mohrahma          #+#    #+#             */
/*   Updated: 2024/03/11 20:53:33 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	t_len;
	char			*result;

	if (!s)
	{
		result = malloc(1);
		result[0] = '\0';
		return (result);
	}
	t_len = ft_strlen(s);
	result = malloc(t_len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < t_len)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
