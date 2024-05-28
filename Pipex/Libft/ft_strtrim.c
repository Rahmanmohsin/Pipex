/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 00:26:44 by mohrahma          #+#    #+#             */
/*   Updated: 2023/12/06 00:26:44 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	start_trim(char const *s1, char const *set)
{
	unsigned int	i;
	int				j;

	i = 0;
	while (i < ft_strlen(s1))
	{
		j = -1;
		while (set[++j] != '\0')
			if (s1[i] == set[j])
				break ;
		if (set[j] == '\0')
			return (i);
		i++;
	}
	return (i);
}

static int	end_trim(char const *s1, char const *set)
{
	unsigned int	i;
	int				j;
	int				t_len;

	t_len = ft_strlen(s1);
	i = 0;
	while (i < ft_strlen(s1))
	{
		j = -1;
		while (set[++j] != '\0')
			if (s1[t_len - i - 1] == set[j])
				break ;
		if (set[j] == '\0')
			return (t_len - i);
		i++;
	}
	return (t_len - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*result;

	if (!(*s1))
		return (ft_strdup(""));
	if (!(*set))
		return (ft_strdup((char *)s1));
	start = start_trim(s1, set);
	end = end_trim(s1, set);
	if (start >= end)
		return (ft_strdup(""));
	result = malloc(sizeof(char) * (end - start + 1));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1 + start, end - start + 1);
	free((char *)s1);
	return (result);
}
