/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 21:00:59 by mohrahma          #+#    #+#             */
/*   Updated: 2024/05/07 03:22:17 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	leaks(void)
{
	system("leaks pipex");
}

void	stop(char *reason, int exit_val)
{
	perror(reason);
	exit(exit_val);
}

void	parent(int argc, char **argv, char **envp, int *fd)
{
	char		*path;
	int			fid;
	char *const	*arg;

	path = NULL;
	(void)envp;
	fid = open(argv[argc - 1], O_WRONLY | O_TRUNC);
	if (fid == -1)
		stop2("pipex: ", ": No such file or directory", argv[4], EXIT_FAILURE);
	close(fd[1]);
	if (dup2(fid, STDOUT_FILENO) == -1 || dup2(fd[0], STDIN_FILENO) == -1)
		stop("Dup", EXIT_FAILURE);
	path = find_path(argc - 2, argv, envp);
	if (!path)
		stop("Path", EXIT_FAILURE);
	arg = create_arg(argv, argc - 2);
	if (!arg)
		stop("Argument", EXIT_FAILURE);
	if (execve(path, (char *const *)arg, envp) == -1)
		return (close(fd[0]), close(fid), free(path), free_all((char **)arg)
			, stop("Execve", EXIT_FAILURE));
}

void	child(char **argv, char **envp, int *fd)
{
	char		*path;
	int			fid;
	char *const	*arg;

	fid = open(argv[1], O_RDONLY);
	if (fid == -1)
		stop2("pipex: ", ": No such file or directory", argv[1], EXIT_FAILURE);
	close(fd[0]);
	if (dup2(fid, STDIN_FILENO) == -1 || dup2(fd[1], STDOUT_FILENO) == -1)
		stop("Dup", EXIT_FAILURE);
	path = find_path(2, argv, envp);
	if (!path)
		stop("Path", EXIT_FAILURE);
	arg = create_arg(argv, 2);
	if (!arg)
		stop("Argument", EXIT_FAILURE);
	if (execve(path, arg, envp) == -1)
		return (close(fd[1]), close(fid), free(path)
			, free_all((char **)arg), stop("Execve", EXIT_FAILURE));
}

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	pid;

	if (argc < 5 || check_access(argc, argv) == 0)
		stop("Arguments", EXIT_FAILURE);
	if (pipe(fd) < 0)
		stop("Pipe", EXIT_FAILURE);
	pid = fork();
	if (pid < 0)
		stop("Pid", EXIT_FAILURE);
	else if (pid == 0)
	{
		child(argv, envp, fd);
		exit(0);
	}
	else
		parent(argc, argv, envp, fd);
	close(fd[0]);
	close(fd[1]);
}
