/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:42:01 by mohrahma          #+#    #+#             */
/*   Updated: 2024/04/30 19:35:02 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_split(char	**split, int i)
{
	while (i > -1)
	{
		free(split[i]);
		i--;
	}
	free(split);
}

static int	mem_aloc(char **split, int i, int w_len, char const *s)
{
	split[i] = malloc(w_len + 1);
	if (!split[i])
	{
		free_split(split, i - 1);
		return (0);
	}
	ft_strlcpy(split[i], (s - w_len), w_len + 1);
	return (1);
}

static int	count_words(const char *s, char c)
{
	int	count;
	int	flag;

	count = 0;
	flag = 0;
	while (*s)
	{
		if (*s == c)
			flag = 0;
		else if (flag == 0 && *s != c)
		{
			flag = -1;
			count++;
		}
		s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		w_count;
	int		w_len;

	i = 0;
	w_len = 0;
	w_count = count_words(s, c);
	split = malloc((w_count + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	while (i < w_count)
	{
		if (*s != c && *s)
			w_len++;
		else if (w_len > 0)
		{
			if (!(mem_aloc(split, i, w_len, s)))
				return (NULL);
			w_len = 0;
			i++;
		}
		s++;
	}
	return (split[i] = NULL, split);
}
