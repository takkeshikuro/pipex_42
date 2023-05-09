/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 08:51:41 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/02/04 07:50:15 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*check_command(char *command, char **path)
{
	int		i;
	char	**cmd;
	char	*slash_cmd;
	char	*way;

	i = 0;
	cmd = ft_split(command, ' ');
	if (!cmd[0])
	{
		free_all(cmd);
		return (NULL);
	}
	slash_cmd = ft_strjoin("/", cmd[0]);
	while (path[i])
	{	
		way = ft_strjoin(path[i], slash_cmd);
		if (access(way, X_OK) == 0)
			return (way);
		free(way);
		i++;
	}
	free(slash_cmd);
	free_all(cmd);
	return (NULL);
}

char	**save_path(char **env)
{
	int		i;
	char	*path;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp("PATH", env[i], 4) == 0)
			break ;
		i++;
	}
	if (!env[i])
		path = " ";
	else
		path = env[i] + 5;
	return (ft_split(path, ':'));
}

void	doing_process(t_pipex *data)
{
	data->pid1 = fork();
	if (data->pid1 < 0)
		call_perror(data, "Fork");
	if (data->pid1 == 0)
		child_process(data);
	else
	{
		data->pid2 = fork();
		if (data->pid2 < 0)
			call_perror(data, "Fork");
		if (data->pid2 == 0)
			child_process2(data);
		else
		{
			close(data->pipefd[0]);
			close(data->pipefd[1]);
			waitpid(data->pid1, NULL, 0);
			waitpid(data->pid2, NULL, 0);
		}
	}
	return ;
}

void	ft_pipex(char **av, char **env)
{
	t_pipex	data;

	if (!env[0])
		exit (1);
	else
		data.env = env;
	if (pipe(data.pipefd) == -1)
	{
		perror("Error (wrong pipe)");
		exit (1);
	}
	data.av = av;
	data.blank_cmd = 0;
	data.path_tab = save_path(data.env);
	doing_process(&data);
	free_all(data.path_tab);
	exit (0);
}

int	main(int ac, char **av, char **env)
{
	if (ac != 5)
	{
		ft_printf("To few or to much arg.\n");
		exit (1);
	}
	else
		ft_pipex(av, env);
	return (0);
}
