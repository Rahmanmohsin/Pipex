/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 08:14:42 by mohrahma          #+#    #+#             */
/*   Updated: 2024/05/01 19:01:18 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	count_words_ifs(const char *s, char c, int *flag, int i)
{
	if (s[i] == c && (*flag) != 1)
		(*flag) = 0;
	if ((s[i] == '\'' || s[i] == '\"') && (*flag) == 1)
	{
		if ((s[i - 1] == '\'' || s[i - 1] == '\"'))
			(*flag) = 1;
		else if ((s[i + 1] == '\'' || s[i + 1] == '\"'))
			(*flag) = 0;
		else
			(*flag) = 0;
	}
	else if ((s[i] == '\'' || s[i] == '\"') && (*flag) != 1)
		(*flag) = 1;
}

int	count_words(const char *s, char c)
{
	int	i;
	int	count;
	int	flag;

	count = 0;
	flag = 0;
	i = -1;
	while (s[++i] != '\0')
	{
		count_words_ifs(s, c, &flag, i);
		if (flag != 1)
		{
			if (s[i] != c && flag == 0)
			{
				flag = -1;
				count++;
			}
		}
	}
	return (count + 1);
}

void	create_arg_ifs1(int *flag, char *argv)
{
	if ((*argv == '\"' || *argv == '\'') && (*flag) == -1)
		(*flag) = 0;
	if ((*argv == '\"' || *argv == '\'') && (*flag) == 0)
		(*flag) = -1;
}

void	create_arg_ifs2(int flag, char *argv, int *size)
{
	if (*argv != ' ' || flag == -1)
		(*size)++;
	if (*argv == ' ' && flag != -1)
		(*size) = 0;
}

char	**create_arg_2(char *argv, int flag, char **result)
{
	int	i;
	int	size;
	int	wc;

	i = 0;
	size = 0;
	wc = count_words(argv, ' ');
	while (i < wc - 1)
	{
		create_arg_ifs1(&flag, argv);
		if (((*argv == '\"' || *argv == '\'' || *argv == ' ')
				&& flag != -1) || *argv == '\0')
		{
			result[i] = malloc(size + 1);
			if (!result)
				return (free_all(result), stop("Malloc", EXIT_FAILURE), NULL);
			ft_strlcpy(result[i], (argv - size), size + 1);
			flag = 0;
			i++;
		}
		create_arg_ifs2(flag, argv, &size);
		argv++;
	}
	result[i] = NULL;
	return (result);
}
