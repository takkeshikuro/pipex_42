/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_directory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 05:30:21 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/02/04 07:50:26 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	file_stuff(t_pipex *data, int fd1)
{
	if (dup2(fd1, 0) == -1)
	{
		close(fd1);
		close(data->pipefd[0]);
		call_perror(data, "dup2 error");
	}
	if (dup2(data->pipefd[1], 1) == -1)
	{
		close(fd1);
		close(data->pipefd[0]);
		call_perror(data, "dup2 error");
	}
	close(data->pipefd[0]);
	close(fd1);
}

void	file_stuff2(t_pipex *data, int fd2)
{
	if (fd2 < 0)
		exit (1);
	if (dup2(fd2, 1) == -1)
	{
		close(data->pipefd[1]);
		close(fd2);
		call_perror(data, "dup2 error");
	}
	if (dup2(data->pipefd[0], 0) == -1)
	{
		close(data->pipefd[1]);
		close(fd2);
		call_perror(data, "dup2 error");
	}
	close(data->pipefd[1]);
	close(fd2);
}
