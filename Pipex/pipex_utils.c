/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:46:46 by mohrahma          #+#    #+#             */
/*   Updated: 2024/05/07 03:23:52 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*make_path(char **path_a, char *path, int c)
{
	char	*result;

	result = NULL;
	if (c == 1)
		result = ft_strdup(path);
	free_all(path_a);
	return (result);
}

char	*find_path_2(char **path, char *command, char **argv, int index)
{
	int		i;
	char	*temp;

	i = -1;
	while (path[++i] != NULL)
	{
		temp = path[i];
		path[i] = ft_strjoin(temp, command);
		free(temp);
		if (access(path[i], F_OK | X_OK) == 0)
		{
			command = make_path(path, path[i], 1);
			if (!command)
				return (free(command), stop("Access", EXIT_FAILURE), NULL);
			return (command);
		}
	}
	if (access(path[0], F_OK | X_OK) < 0)
		return (stop2("pipex: ", ": command not found", argv[index], 127)
			, NULL);
	return (free(command), NULL);
}

char	*find_path(int index, char **argv, char **envp)
{
	char	**path;
	char	*command;
	int		envp_path;
	char	*result;

	envp_path = 0;
	while (ft_strncmp(envp[envp_path], "PATH", 4) != 0)
		envp_path++;
	path = ft_split(envp[envp_path], ':');
	if (!path)
		return (stop("Access 1", EXIT_FAILURE), NULL);
	if (argv[index][0] == '/')
		command = init_string(argv[index]);
	else
		command = ft_strjoin("/", argv[index]);
	if (!command)
		return (stop("Access 2", EXIT_FAILURE), NULL);
	command = str_cut_end(command, ' ');
	if (!command)
		return (stop("Access 3", EXIT_FAILURE), NULL);
	ft_strlcpy(path[0], (path[0] + 5), ft_strlen(path[0]));
	result = find_path_2(path, command, argv, index);
	if (!command)
		return (stop("Access 4", EXIT_FAILURE), NULL);
	return (free(command), result);
}

int	check_access(int argc, char **argv)
{
	if (access(argv[1], R_OK | W_OK) < 0)
	{
		if (access(argv[1], F_OK) < 0)
			open(argv[argc - 1], O_CREAT | O_RDWR, 0664);
		else
			return (stop("Access FILE", EXIT_FAILURE), 0);
	}
	else if (access(argv[argc - 1], R_OK | W_OK) < 0)
	{
		if (access(argv[argc - 1], F_OK) < 0)
			open(argv[argc - 1], O_CREAT | O_RDWR, 0664);
		else
			return (stop("Access FILE", EXIT_FAILURE), 0);
	}
	return (1);
}
