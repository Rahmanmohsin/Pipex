/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:55:30 by mohrahma          #+#    #+#             */
/*   Updated: 2024/05/06 21:49:18 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**create_arg(char **argv, int index)
{
	int		i;
	int		flag;
	char	**result;
	char	*temp;

	result = malloc(count_words(argv[index], ' ') * sizeof(char *));
	if (!result)
		return (stop("Malloc", EXIT_FAILURE), NULL);
	flag = 0;
	result = create_arg_2(argv[index], flag, result);
	if (!result)
		return (stop("Malloc", EXIT_FAILURE), NULL);
	result[count_words(argv[index], ' ') - 1] = NULL;
	i = -1;
	while (result[++i] != NULL)
	{
		temp = result[i];
		if (result[i][0] == '\'')
			result[i] = ft_strtrim(temp, "\'");
		else if (result[i][0] == '\"')
			result[i] = ft_strtrim(temp, "\"");
	}
	return (result);
}

void	stop2(char *statement, char *reason, char *argv, int exit_c)
{
	char	*print;
	char	*temp;

	temp = ft_strjoin(statement, argv);
	print = ft_strjoin(temp, reason);
	ft_putendl_fd(print, 2);
	free(temp);
	free(print);
	exit(exit_c);
}

char	*str_cut_end(char *s, char c)
{
	int		i;
	char	*result;

	i = -1;
	while (s[++i] != '\0')
		if (s[i] == c)
			break ;
	result = malloc(i);
	if (!result)
		return (stop("Malloc", EXIT_FAILURE), NULL);
	result[(ft_strlen(s) - (ft_strlen(s) - i))] = '\0';
	i = -1;
	while (s[++i] != '\0')
	{
		result[i] = s[i];
		if (s[i] == c)
			break ;
	}
	result[i] = '\0';
	free(s);
	return (result);
}

int	free_all(char **s)
{
	int	i;

	i = -1;
	while (s[++i] != NULL)
		free(s[i]);
	free(s);
	return (1);
}

char	*init_string(char *s)
{
	int		i;
	int		j;
	char	*result;

	i = ft_strlen(s);
	result = NULL;
	while (s[i] != '/' && i > -1)
		i--;
	if (i < (int)ft_strlen(s))
	{
		result = malloc(ft_strlen(s) - i + 1);
		i--;
		j = -1;
		while (s[i] != '\0')
			result[++j] = s[++i];
		result[j] = '\0';
	}
	if (!result)
		return (s);
	else
		return (result);
}
