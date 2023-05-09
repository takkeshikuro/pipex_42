/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 08:52:11 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/02/04 08:00:52 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libs/libft/libft.h"
# include "libs/printf/ft_printf.h"
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	char	**path_tab;
	char	**env;
	char	**av;
	int		pid1;
	int		pid2;
	int		blank_cmd;
	int		pipefd[2];
	char	*cmdway1;
	char	*cmdway2;
}		t_pipex;

void	ft_pipex(char **av, char **env);
void	doing_process(t_pipex *ok);
char	**save_path(char **env);
char	*check_command(char *command, char **path);

void	child_process2(t_pipex *ok);
void	child_process(t_pipex *ok);

void	file_stuff2(t_pipex *ok, int fd2);
void	file_stuff(t_pipex *ok, int fd1);

void	free_all(char **tab);
void	call_perror(t_pipex *ok, char *error_msg);
int		has_backslash(char *str);

#endif