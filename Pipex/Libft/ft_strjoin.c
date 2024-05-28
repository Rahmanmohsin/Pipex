/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 00:09:46 by mohrahma          #+#    #+#             */
/*   Updated: 2023/12/06 00:09:46 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*result;

	if (s1 == 0 || s2 == 0)
		return (0);
	i = (int)ft_strlen(s1);
	j = (int)ft_strlen(s2);
	result = malloc((i + j + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		result[i] = s1[i];
	j = -1;
	while (s2[++j] != '\0')
	{
		result[i] = s2[j];
		i++;
	}
	result[i] = '\0';
	return (result);
}
