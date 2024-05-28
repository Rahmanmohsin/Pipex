/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 21:01:06 by mohrahma          #+#    #+#             */
/*   Updated: 2024/05/01 20:48:06 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "Libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

// static int		original_stdout; //uncomment to show leaks

int		check_access(int argc, char **argv);
char	*find_path(int argc, char **argv, char **envp);
void	stop(char *reason, int exit_val);
char	*make_path(char **path_a, char *path, int c);
char	**create_arg(char **argv, int index);
char	**create_arg_2(char *argv, int flag, char **result);
int		count_words(const char *s, char c);
void	count_words_ifs(const char *s, char c, int *flag, int i);
void	create_file(int argc, char **argv, char **envp);
char	*find_path_2(char **path, char *command, char **argv, int index);
char	*str_cut_end(char *s, char c);
void	stop2(char *statement, char *reason, char *argv, int exit_c);
void	create_arg_ifs2(int flag, char *argv, int *size);
void	create_arg_ifs1(int *flag, char *argv);
int		free_all(char **s);
char	*init_string(char *s);

#endif