/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 18:24:19 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/02/04 07:50:10 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	has_backslash(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '/')
			return (1);
		i++;
	}
	return (0);
}

void	child_process(t_pipex *data)
{	
	int		fd1;
	char	**cmd1;

	fd1 = open(data->av[1], O_RDWR);
	if (fd1 < 0)
		call_perror(data, data->av[1]);
	if (has_backslash(data->av[2]))
		data->cmdway1 = data->av[2];
	else if (!has_backslash(data->av[2]))
	{
		data->cmdway1 = check_command(data->av[2], data->path_tab);
		if (!data->cmdway1)
		{
			data->blank_cmd = 1;
			call_perror(data, data->av[2]);
		}
	}
	file_stuff(data, fd1);
	cmd1 = ft_split(data->av[2], ' ');
	if (execve(data->cmdway1, cmd1, data->env) == -1)
	{
		free_all(cmd1);
		call_perror(data, "execve error");
	}
	free_all(cmd1);
}

void	child_process2(t_pipex *data)
{
	int		fd2;
	char	**cmd2;

	data->blank_cmd = 0;
	fd2 = open(data->av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (has_backslash(data->av[3]))
		data->cmdway2 = data->av[3];
	else if (!has_backslash(data->av[3]))
	{
		data->cmdway2 = check_command(data->av[3], data->path_tab);
		if (!data->cmdway2)
		{
			close(fd2);
			data->blank_cmd = 1;
			call_perror(data, data->av[3]);
		}
	}
	file_stuff2(data, fd2);
	cmd2 = ft_split(data->av[3], ' ');
	if (execve(data->cmdway2, cmd2, data->env) == -1)
	{
		free_all(cmd2);
		call_perror(data, "execve error");
	}
	free_all(cmd2);
}
